/*

 File generated by ../../tools/common_config.py from common_config.input

 Copyright (c) 2010 Fizians SAS. <http://www.fizians.com>
 This file is part of Rozofs.

 Rozofs is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published
 by the Free Software Foundation, version 2.

 Rozofs is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see
 <http://www.gnu.org/licenses/>.
 */
#ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <libconfig.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>

void common_config_read(char * fname);

typedef struct _common_config_global_t {

  /*
  ** global scope configuration elements
  */

  // Number of core files that each module is allowed to keep.
  // Older core files are kept while newest are removed.	
  uint32_t    nb_core_file;
  // Directory where the core files are stored.
  char *      core_file_directory;
  // Enables to take into account the NUMA architecture of the board in 
  // order to collocate some RozoFS modules on the same node for memory
  // access efficiency.
  uint32_t    numa_aware;
  // Number of slices in the STORIO.
  uint32_t    storio_slice_number;
  // File distribution mode upon cluster, storages and devices.
  // Check  rozofs_file_distribution_rule_e. 
  uint32_t    file_distribution_rule;
  // DSCP for exchanges from/to the STORIO.
  uint32_t    storio_dscp;
  // DSCP for exchanges from/to the EXPORTD.
  uint32_t    export_dscp;

  /*
  ** export scope configuration elements
  */

  // Max number of file that the exportd can remove from storages in a run.
  // A new run occurs every 2 seconds.
  uint32_t    trashed_file_per_run;
  // High trash water mark when FID recycling is activated.
  // When the trash has already this number of files, files are no more
  // deleted but recycled.
  uint32_t    trash_high_threshold;
  // Whether FID recycling feature is activated.
  uint32_t    fid_recycle;
  uint32_t    export_buf_cnt;
  // To activate export writebehind attributes thread.
  uint32_t    export_attr_thread;
  // Support of deleted directory/file versioning.
  uint32_t    export_versioning;
  // Number of MB to account a file for during file distribution phase
  uint32_t    alloc_estimated_mb;

  /*
  ** client scope configuration elements
  */

  // Whether STORCLI acknowleges write request on inverse or forward STORIO responses.
  uint32_t    wr_ack_on_inverse;
  // To activate rozofsmount reply fuse threads.
  uint32_t    rozofsmount_fuse_reply_thread;

  /*
  ** storage scope configuration elements
  */

  // Number of disk threads in the STORIO.
  uint32_t    nb_disk_thread;
  // Whether STORIO is in multiple (1 STORIO per cluster) 
  // or single mode (only 1 STORIO).
  uint32_t    storio_multiple_mode;
  // Whether CRC32 MUST be checked by STORIO.
  uint32_t    crc32c_check;
  // Whether CRC32 MUST be computed by STORIO.
  uint32_t    crc32c_generate;
  // Whether CRC32 MUST be absolutly hardware computed by STORIO.
  uint32_t    crc32c_hw_forced;
  // Whether STORIO device monitoring should avoid reading from 
  // devices when no access have occured for read or write. This
  // enables disk spin down to occur.
  uint32_t    allow_disk_spin_down;
  // Over which device usage threashold should the STORIO log the event. 
  uint32_t    disk_usage_threshold;
  // Over which device read delay threashold should the STORIO log the event. 
  uint32_t    disk_read_threshold;
  // Over which device write delay threashold should the STORIO log the event. 
  uint32_t    disk_write_threshold;
  // Number of STORIO receive buffer.
  uint32_t    storio_buf_cnt;
  // Number of block to which the chunk files should be truncated on storage 
  // node at the time it is recycled.
  uint32_t    recycle_truncate_blocks;
} common_config_t;

extern common_config_t common_config;
#endif