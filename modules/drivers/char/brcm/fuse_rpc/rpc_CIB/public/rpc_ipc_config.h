/****************************************************************************
*
*     Copyright (c) 2007-2008 Broadcom Corporation
*
*   Unless you and Broadcom execute a separate written software license 
*   agreement governing use of this software, this software is licensed to you 
*   under the terms of the GNU General Public License version 2, available 
*    at http://www.gnu.org/licenses/old-licenses/gpl-2.0.html (the "GPL"). 
*
*   Notwithstanding the above, under no circumstances may you combine this 
*   software in any way with any other Broadcom software provided under a license 
*   other than the GPL, without Broadcom's express prior written consent.
*
****************************************************************************/
/**
*
*   @file   rpc_ipc_config.h
*
*   @brief  This file defines the initial config types
*
****************************************************************************/

#ifndef _RPC_IPC_CONFIG_H_
#define _RPC_IPC_CONFIG_H_

#define CFG_RPC_CMD_MAX_PACKETS	64
#define CFG_RPC_CMD_PKT_SIZE		2048

#define CFG_RPC_CMD_MAX_PACKETS2	2
#define CFG_RPC_CMD_PKT_SIZE2		25600

#define CFG_RPC_CMD_MAX_PACKETS3	2
#define CFG_RPC_CMD_PKT_SIZE3		65536

#define CFG_RPC_CMD_START_THRESHOLD		1
#define CFG_RPC_CMD_END_THRESHOLD			0

/*TE --> NW i.e. UL IPC Buffer Count*/
#define CFG_RPC_PKTDATA_MAX_TE2NW_PACKETS	350
/*NW --> TE i.e. DL IPC Buffer Count*/
#define CFG_RPC_PKTDATA_MAX_NW2TE_PACKETS	128

#define PDCP_MAX_HEADER_SIZE 168

/* Increased from 1600 to allow 168 for header decompresion */
#define CFG_RPC_PKTDATA_PKT_SIZE		(1600 + PDCP_MAX_HEADER_SIZE)

#ifdef UNDER_LINUX
//ftp consumes high mips during UL, because frequently calling netif on/off
//since we have 64 buffer right now, make transmit start when free buffer
//is 15, which should not affect the UL performace.
#define CFG_RPC_PKT_START_THRESHOLD             15
#else
#define CFG_RPC_PKT_START_THRESHOLD             1
#endif
#define CFG_RPC_PKT_END_THRESHOLD		    0

/*TE --> NW i.e. UL IPC CSD Buffer Count*/
#define CFG_RPC_CSDDATA_MAX_TE2NW_PACKETS		4
/*NW --> TE i.e. DL IPC CSD Buffer Count*/
#define CFG_RPC_CSDDATA_MAX_NW2TE_PACKETS		20
#define CFG_RPC_CSDDATA_PKT_SIZE		512

#define CFG_RPC_CSD_START_THRESHOLD		1
#define CFG_RPC_CSD_END_THRESHOLD		    0

#define CFG_RPC_LOG_MAX_PACKETS		 50
#define CFG_RPC_LOG_PKT_SIZE			5000
#define CFG_RPC_LOG_START_THRESHOLD	  1
#define CFG_RPC_LOG_END_THRESHOLD		  0


#define CFG_RPC_EEMDATA_MAX_PACKETS		8
#define CFG_RPC_EEMDATA_PKT_SIZE		1600

#define CFG_RPC_EEM_START_THRESHOLD		1
#define CFG_RPC_EEM_END_THRESHOLD		0

#endif  // _RPC_IPC_CONFIG_H_

