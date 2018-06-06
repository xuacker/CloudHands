/*
 *
 *      Filename: ch_packet_record_session_tcp.h
 *
 *        Author: shajf,csp001314@gmail.com
 *   Description: ---
 *        Create: 2018-04-10 16:07:48
 * Last Modified: 2018-04-10 16:07:48
 */

#ifndef CH_PACKET_RECORD_SESSION_TCP_H
#define CH_PACKET_RECORD_SESSION_TCP_H

typedef struct ch_packet_record_session_tcp_t ch_packet_record_session_tcp_t;

#include "ch_packet_record.h"

/*
 *TCP Session Phase state
 * */
#define TCP_SESSION_PHASE_STATE_SYN 0
#define TCP_SESSION_PHASE_STATE_SYN_ACK 1
#define TCP_SESSION_PHASE_STATE_ACK_ACK 2
#define TCP_SESSION_PHASE_STATE_CON 3
#define TCP_SESSION_PHASE_STATE_CLOSE 4


struct ch_packet_record_session_tcp_t {

	uint8_t  is_timeout;

	uint16_t timeout_tv;
	uint16_t phase_state;
    uint16_t src_port;
    uint16_t dst_port;
	
	size_t db_path_len;
	char *db_path;

    uint32_t src_ip;
    uint32_t dst_ip;
	uint32_t req_data_size;
	uint32_t res_data_size;
	uint32_t req_data_seq;
	uint32_t res_data_seq;

	uint64_t session_id;
	uint64_t req_packets;
	uint64_t res_packets;
	uint64_t req_bytes;
	uint64_t res_bytes;
	uint64_t req_start_time;
	uint64_t req_last_time;
	uint64_t res_start_time;
	uint64_t res_last_time;

};

#define CH_PACKET_RECORD_SESSION_TCP_META_SIZE(d_plen) (sizeof(uint8_t)+\
	sizeof(uint16_t)*4+\
	sizeof(uint32_t)*6+\
	sizeof(uint64_t)*9+\
	sizeof(size_t)+\
	d_plen)

extern void ch_packet_record_session_tcp_read(ch_packet_record_session_tcp_t *pkt_tcp_session,ch_packet_record_t *pkt_rcd);

extern size_t 
ch_packet_record_session_tcp_write(ch_packet_record_session_tcp_t *pkt_tcp_session,void *buffer,size_t bsize,void *data,size_t dlen);

#endif /*CH_PACKET_RECORD_SESSION_TCP_H*/