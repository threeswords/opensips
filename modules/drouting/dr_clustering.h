/*
 * Copyright (C) 2017 OpenSIPS Project
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#ifndef _DROUTING_CLUSTERING_H_
#define _DROUTING_CLUSTERING_H_

#include "../../sr_module.h"
#include "../../bin_interface.h"
#include "../clusterer/api.h"

#define BIN_VERSION 1

#define REPL_GW_STATUS_UPDATE 1
#define REPL_CR_STATUS_UPDATE 2

extern int dr_cluster_id;
extern str dr_cluster_shtag;

struct clusterer_binds clusterer_api;

int dr_init_cluster(void);

/* checks if the sharing tag is on active */
int dr_cluster_shtag_is_active(void);

/* replicate the GW status via BIN */
void replicate_dr_gw_status_event(struct head_db *p, pgw_t *gw);

/* replicate the Carrier status via BIN */
void replicate_dr_carrier_status_event(struct head_db *p, pcr_t *cr);

/* handler for incoming BIN packets */
void receive_dr_binary_packet(bin_packet_t *packet);

#endif
