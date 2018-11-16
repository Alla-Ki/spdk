#ifndef EC_OFFLOAD_H
#define EC_OFFLOAD_H

#include "ec_common.h"


struct ec_offload_opts {
    char    *devname;
    int     k;
    int     m;
    int     w;
    int     frame_size;
    char    *failed_blocks;
    int     max_inflight_calcs;
    int     depth;
    int     duration;
    int     sw;
    int     aff;
    int     polling;
    char    *unit;
    char    *data_updates;
    char    *code_updates;
    int     in_memory;
};


struct ec_offload_context {
	struct ibv_device   *dev;
	struct ibv_context  *context;
	struct ibv_pd       *pd;
	struct ec_context   *ec_ctx;
};


struct ec_offload_context *
ec_offload_init_ctx(struct ec_offload_opts *opts);

void
ec_offload_close_ctx(struct ec_offload_context *ctx);

int
ec_offload_decode_block_sync(struct ec_offload_context *ctx,
			     char* data,
			     char* code);
int
ec_offload_encode_block_sync(struct ec_offload_context *ctx,
			     char* data,
			     char* code);

#endif /* EC_OFFLOAD_H */
