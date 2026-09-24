#ifndef _LHDCV5BT_H_
#define _LHDCV5BT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "lhdcv5_api.h"

int32_t lhdcv5BT_free_handle 
(
    HANDLE_LHDCV5_BT	handle
);

int32_t lhdcv5BT_get_handle 
(
    uint32_t			version,
    HANDLE_LHDCV5_BT	*handle
);

int32_t lhdcv5BT_set_lossless_raw_enable
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t          enabled
);

int32_t lhdcv5BT_get_bitrate
(
    HANDLE_LHDCV5_BT	handle,
    uint32_t			* bitrate
);

int32_t lhdcv5BT_set_bitrate
(
    HANDLE_LHDCV5_BT 	handle,
    uint32_t			bitrate_inx
);

int32_t lhdcv5BT_set_max_bitrate
(
    HANDLE_LHDCV5_BT	handle,
    uint32_t			max_bitrate_inx
);

int32_t lhdcv5BT_set_min_bitrate
(
    HANDLE_LHDCV5_BT 	handle,
    uint32_t			min_bitrate_inx
);

int32_t lhdcv5BT_adjust_bitrate
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t          queueLen
);

int32_t lhdcv5BT_init_encoder
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t      sampling_freq,
    uint32_t      bits_per_sample,
    uint32_t      frame_len,
    uint32_t      bitrate_inx,
    uint32_t      mtu,
    uint32_t      interval,
    uint32_t      is_lossless_enable,
    uint32_t      is_br128_enable
);

int32_t lhdcv5BT_get_block_Size
(
    HANDLE_LHDCV5_BT	handle,
    uint32_t			* samples_per_frame
);

int32_t lhdcv5BT_encode
(
    HANDLE_LHDCV5_BT 	handle,
    void				* p_in_pcm,
    uint32_t			pcm_bytes,
    uint8_t				* p_out_buf,
    uint32_t			out_buf_bytes,
    uint32_t 			* p_out_bytes,
    uint32_t 			* p_out_frames
);

#ifdef __cplusplus
}
#endif

#endif /* _LHDCV5BT_H_ */
