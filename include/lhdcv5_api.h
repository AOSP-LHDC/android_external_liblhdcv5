/*
 ******************************************************************
 LHDC 5.0 utilities API header
 ******************************************************************
 */

#ifndef __LHDCV5_API_H__
#define __LHDCV5_API_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* *
 * High quality lossless requires very high bitrate for transmission (ex:mHDT).
 * The definitions are for testing VBR or VBR-Plus mechanisms only
 * */

typedef enum __LHDCV5_SAMPLE_FREQ__
{
  LHDCV5_SR_44100HZ  =  44100,
  LHDCV5_SR_48000HZ  =  48000,
  LHDCV5_SR_96000HZ  =  96000,
  LHDCV5_SR_192000HZ = 192000,
} LHDCV5BT_SAMPLE_FREQ_T;

typedef enum __LHDCV5BT_SMPL_FMT__
{
  LHDCV5BT_SMPL_FMT_S16 = 16,
  LHDCV5BT_SMPL_FMT_S24 = 24,
  LHDCV5BT_SMPL_FMT_S32 = 32,
} LHDCV5BT_SMPL_FMT_T;

typedef enum __LHDCV5_SAMPLE_FRAME__
{
  LHDCV5_SAMPLE_FRAME_2P5MS_96000KHZ  = 240,

  LHDCV5_SAMPLE_FRAME_5MS_44100KHZ  = 240,
  LHDCV5_SAMPLE_FRAME_5MS_48000KHZ  = 240,
  LHDCV5_SAMPLE_FRAME_5MS_96000KHZ  = 480,
  LHDCV5_SAMPLE_FRAME_5MS_192000KHZ = 960,

  LHDCV5_SAMPLE_FRAME_10MS_44100KHZ  = 480,
  LHDCV5_SAMPLE_FRAME_10MS_48000KHZ  = 480,
  LHDCV5_SAMPLE_FRAME_10MS_96000KHZ  = 960,
  LHDCV5_SAMPLE_FRAME_10MS_192000KHZ = 1920,
  LHDCV5_MAX_SAMPLE_FRAME = 1920,
} LHDCV5_SAMPLE_FRAME_T;

typedef enum __LHDCV5_FRAME_DURATION__
{
  LHDCV5_FRAME_5MS   = 50,
  LHDCV5_FRAME_7P5MS = 75,
  LHDCV5_FRAME_10MS  = 100,
  LHDCV5_FRAME_1S    = 10000,
} LHDCV5_FRAME_DURATION_T;

typedef enum __LHDCV5_ENC_INTERVAL__
{
  LHDCV5_ENC_INTERVAL_10MS = 10,
  LHDCV5_ENC_INTERVAL_20MS = 20,
} LHDCV5_ENC_INTERVAL_T;

typedef enum __LHDCV5_QUALITY__
{
  // standard quality index (sync to UI)
  LHDCV5_QUALITY_LOW0 = 0,    //128k
  LHDCV5_QUALITY_LOW1,        //160k
  LHDCV5_QUALITY_LOW2,        //192K
  LHDCV5_QUALITY_LOW3,        //256K/240K(for 44.1KHz)
  LHDCV5_QUALITY_LOW4,        //320K
  LHDCV5_QUALITY_LOW,         //400K
  LHDCV5_QUALITY_MID,         //500K/480K(for 44.1KHz)
  LHDCV5_QUALITY_HIGH,        //900K
  LHDCV5_QUALITY_HIGH1,       //1000K
  LHDCV5_QUALITY_HIGH2,       //(for lossless enabled)
  LHDCV5_QUALITY_HIGH3,       //(for lossless enabled)
  LHDCV5_QUALITY_HIGH4,       //(for lossless enabled)
  LHDCV5_QUALITY_HIGH5,       //(for lossless enabled)
  LHDCV5_QUALITY_MAX_BITRATE = LHDCV5_QUALITY_HIGH5,
  // standard adaptive mode (sync to UI)
  LHDCV5_QUALITY_AUTO,
  // end of standard (not sync to UI)
  LHDCV5_QUALITY_UNLIMIT,

  // quality mode control command
  LHDCV5_QUALITY_CTRL_RESET_ABR = 128,  //base of control command
  // end of control
  LHDCV5_QUALITY_CTRL_END,

  // always at bottom of table
  LHDCV5_QUALITY_INVALID
} LHDCV5_QUALITY_T;

#define LHDCV5_ABR_DEFAULT_BITRATE_INX (LHDCV5_QUALITY_LOW)
#define LHDCV5_VBR_DEFAULT_BITRATE_INX (LHDCV5_QUALITY_HIGH2)

typedef enum __LHDCV5_MTU_SIZE__
{
  LHDCV5_MTU_MIN   = 300,
  LHDCV5_MTU_2MBPS = 660,
  LHDCV5_MTU_3MBPS = 1023,
  LHDCV5_MTU_MHDT_4DH5 = 1392,
  LHDCV5_MTU_MHDT_6DH5 = 2089,
  LHDCV5_MTU_MHDT_8DH5 = 2820,
  LHDCV5_MTU_MAX   = 8192,
} LHDCV5_MTU_SIZE_T;

typedef enum __LHDCV5_VERSION__
{
  LHDCV5_VERSION_1 = 1,
  LHDCV5_VERSION_INVALID
} LHDCV5_VERSION_T;

typedef enum __LHDCV5_ENC_TYPE__ 
{
  LHDCV5_ENC_TYPE_UNKNOWN = 0,
  LHDCV5_ENC_TYPE_LHDCV5,
  LHDCV5_ENC_TYPE_INVALID
} LHDCV5_ENC_TYPE_T;

typedef enum __LHDCV5_EXT_FUNC__
{
  LHDCV5_EXT_FUNC_AR = 0,
  LHDCV5_EXT_FUNC_LARC,
  LHDCV5_EXT_FUNC_JAS,
  LHDCV5_EXT_FUNC_META,
  LHDCV5_EXT_FUNC_INVALID
} LHDCV5_EXT_FUNC_T;

typedef enum __LHDCV5_META_PARAM__
{
  LHDCV5_META_LOOP_CNT_MAX = 100,
  LHDCV5_META_LOOP_CNT_STD = 20,
  LHDCV5_META_LEN_FIXED = 8,
  LHDCV5_META_LEN_MAX = 128
} LHDCV5_META_PARAM_T;

typedef enum __LHDCV5_ABR_TYPE__
{
  LHDCV5_ABR_44K_RES = 0,
  LHDCV5_ABR_48K_RES,
  LHDCV5_ABR_96K_RES,
  LHDCV5_ABR_192K_RES,
  LHDCV5_ABR_INVALID
} LHDCV5_ABR_TYPE_T;

typedef enum __LHDCV5_VBR_TYPE__
{
  LHDCV5_VBR_48K_RES,
  LHDCV5_VBR_96K_RES,
  LHDCV5_VBR_INVALID
} LHDCV5_VBR_TYPE_T;

typedef enum __LHDCV5_ABR_BITRATE_RANGE__
{
  LHDCV5_ABR_MIN_BITRATE = 160,
  LHDCV5_ABR_MAX_BITRATE = 900,
} LHDCV5_ABR_BITRATE_RANGE_T;

typedef enum __LHDCV5_VBR_BITRATE_RANGE__
{
  LHDCV5_VBR_MIN_BITRATE = 900,
  LHDCV5_VBR_MAX_BITRATE = 1400,
} LHDCV5_VBR_BITRATE_RANGE_T;

typedef enum __LHDCV5_VBR_LLESS24_BITRATE_RANGE__
{
  LHDCV5_VBR_LLES24_MIN_BITRATE = 1350,
  LHDCV5_VBR_LLES24_MAX_BITRATE = 2100,
  LHDCV5_VBR_LLES96K24_MIN_BITRATE = 2700,
  LHDCV5_VBR_LLES96K24_MAX_BITRATE = 4200,
} LHDCV5_VBR_LLESS24_BITRATE_RANGE_T;

typedef enum __LHDCV5_LOSSLESS_STATUS__
{
  LHDCV5_LLESS_DISABLED = 0,
  LHDCV5_LLESS_ENABLED = 1,
} LHDCV5_LOSSLESS_STATUS_T;

typedef enum __LHDCV5_LOSSLESS_ON_STATUS__
{
  LHDCV5_LLESS_OFF = 0,
  LHDCV5_LLESS_ON = 1,
} LHDCV5_LOSSLESS_ON_STATUS_T;

typedef enum __LHDCV5_LOSSLESS_RAW_STATUS__
{
  LHDCV5_LLESS_RAW_DISABLED = 0,
  LHDCV5_LLESS_RAW_ENABLED = 1,
} LHDCV5_LOSSLESS_RAW_STATUS_T;

typedef enum __LHDCV5_LOG_LEVEL__
{
  LHDCV5_LOG_LEVEL_EMERG = 0,
  LHDCV5_LOG_LEVEL_ALERT,
  LHDCV5_LOG_LEVEL_CRIT,
  LHDCV5_LOG_LEVEL_ERROR,
  LHDCV5_LOG_LEVEL_WARNING,
  LHDCV5_LOG_LEVEL_NOTICE,
  LHDCV5_LOG_LEVEL_INFO,
  LHDCV5_LOG_LEVEL_DEBUG,
} LHDCV5_LOG_LEVEL_T;

typedef enum __LHDCV5_FUNC_RET__
{
  LHDCV5_FRET_SUCCESS                   =     0,
  LHDCV5_FRET_INVALID_INPUT_PARAM       =    -1,
  LHDCV5_FRET_INVALID_HANDLE_CB         =    -2,
  LHDCV5_FRET_INVALID_HANDLE_PARA       =    -3,
  LHDCV5_FRET_INVALID_HANDLE_ENC        =    -4,
  LHDCV5_FRET_INVALID_HANDLE_CBUF       =    -5,
  LHDCV5_FRET_INVALID_HANDLE_AR         =    -6,
  LHDCV5_FRET_INVALID_CODEC             =    -7,
  LHDCV5_FRET_CODEC_NOT_READY           =    -8,
  LHDCV5_FRET_AR_NOT_READY              =    -9,
  LHDCV5_FRET_ERROR                     =   -10,
  LHDCV5_FRET_BUF_NOT_ENOUGH            =   -11,
} LHDCV5_FUNC_RET_T;

typedef struct _lhdcv5_abr_para_t 
{
  uint32_t  version;            // version of LHDC 5.0 CODEC
  uint32_t  sample_rate;        // sample rate (Hz)
  uint32_t  bits_per_sample;    // bits per sample (bit)
  uint32_t  bits_per_sample_ui; // bits per sample (bit) (from UI)

  // Lossy ABR mechanism
  uint32_t  upBitrateCnt;       // (ABR) up bitrate check parameter
  uint32_t  upBitrateSum;       // (ABR) up bitrate check parameter
  uint32_t  dnBitrateCnt;       // (ABR) down bitrate check parameter
  uint32_t  dnBitrateSum;       // (ABR) down bitrate check parameter

  // Lossless VBR parameter
  uint32_t  lless_upBitrateSum;   // (VBR) number of encoded lossy frames
  uint32_t  lless_dnBitrateSum;   // (VBR) number of encoded lossless frames
  uint32_t  lless_upBitrateCnt;   // (VBR) number of encoded frames
  uint32_t  lless_dnBitrateCnt;   // (VBR) number of encoded frames
  uint32_t  lless_upCheckBitrateCnt;    // (VBR) times of entering adjust func to exam up case
  uint32_t  lless_dnCheckBitrateCnt;    // (VBR) times of entering adjust func to exam down case

  // Lossless VBR configuration
  uint32_t lless_upRateTimeCnt;     // (VBR) param: check interval of up
  uint32_t lless_dnRateTimeCnt;     // (VBR) param: check interval of down
  uint32_t lless_upLossyRatioTh;    // (VBR) param: lossy ratio threshold of up
  uint32_t lless_dnLosslessRatioTh; // (VBR) param: lossless ratio threshold of down

  // Lossless VBR statistics
  uint32_t  lless_stat_showBitrateCnt;      // (VBR) times of entering adjust func to exam print stats
  float     lless_stat_dnBitrateCnt_all;    // (VBR) aggregate sum of lless_bitrateCnt
  float     lless_stat_dnBitrateSum_all;    // (VBR) aggregate sum of lless_dnBitrateSum
  float     lless_stat_upBitrateCnt_all;    // (VBR) aggregate sum of lless_bitrateCnt
  float     lless_stat_upBitrateSum_all;    // (VBR) aggregate sum of lless_dnBitrateSum
  bool      lless_stat_bitrateRec_done;     // (VBR) flag to determine debug print after a duration

  // function configuration
  uint32_t  lastBitrate;        // Last bit rate (kbps) set for LHDC 5.0 encoder
  uint32_t  qualityStatus;      // current bit rate (index) (LOW0 ~ AUTO) is same as UI setting
  uint32_t  is_lless_enabled;   // current lossless status: enabled(1)/disabled(0)
  uint32_t  is_lless_on;        // current lossless running status: ON(1)/OFF(0)
  uint32_t  is_lless_raw;       // lossless raw mode: enabled(1)/disabled(0)
} lhdcv5_abr_para_t;


typedef void * HANDLE_LHDCV5_BT;
/*
 ******************************************************************
 LHDCV5 encoder utilities functions group
 ******************************************************************
 */
//----------------------------------------------------------------
// lhdcv5_util_enc_register_log_cb ()
//
//  Register a logger(printing function) callback instance from external
//  Parameter
//      [in] cb: a pointer to the callback function of logger.
//      [in] msg_buff: buffer for storing the char string.
//      [in] buf_size: bytes of buffer size.
//      [in] level: an integer of log level.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Failure
//----------------------------------------------------------------
int32_t lhdcv5_util_enc_register_log_cb
(
    void  *cb,
    char  *msg_buff,
    uint32_t buf_size,
    int32_t  level
);

//----------------------------------------------------------------
// lhdcv5_util_free_handle ()
//
// Reset resources in the encoder(not free memory, call this before free handle)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Failure
//----------------------------------------------------------------
int32_t lhdcv5_util_free_handle
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_get_mem_req ()
//
// Get size of memory resources required by LHDC 5.0 Encoder
//  Parameter
//      [in] version: subversion defined in BT A2DP capability.
//      [in] mem_req_bytes: a returned pointer to size bytes required by encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_mem_req
(
    uint32_t  version,
    uint32_t  *mem_req_bytes
);

//----------------------------------------------------------------
// lhdcv5_util_get_handle ()
//
// Initialize memory resources required by LHDC 5.0 Encoder
//  Parameter
//      [in] version: version defined in BT A2DP capability.
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] mem_size: required size bytes.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_handle
(
    uint32_t  version,
    HANDLE_LHDCV5_BT  handle,
    uint32_t  mem_size
);

//----------------------------------------------------------------
// lhdcv5_util_get_target_bitrate ()
//
// Get the bit rate (bps) used during LHDC 5.0 encoding
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] bitrate: a returned pointer to the bit rate (bps).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_target_bitrate
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  *bitrate
);

//----------------------------------------------------------------
// lhdcv5_util_set_target_bitrate_inx ()
//
// Set target bit rate by index to LHDC 5.0 encoding
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] bitrate_inx: bit rate (index) to set
//           range [LHDCV5_QUALITY_LOW0, LHDCV5_QUALITY_AUTO].
//      [in] bitrate_inx_set: a returned pointer to the set bit rate (index).
//      [in] upd_qual_status: a control if update "audio quality" field by the bitrate_inx:
//           in Fixed bitrate Mode: set true to change the "audio quality" by the bitrate_inx.
//           in Auto bitrate Mode: set false to keep the "audio quality" in Auto Bitrate Mode.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_target_bitrate_inx
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  bitrate_inx,
    uint32_t  *bitrate_inx_set,
    bool  upd_qual_status
);

//----------------------------------------------------------------
// lhdcv5_util_set_max_bitrate_inx ()
//
// Set the maximum bitrate of peer device
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] max_bitrate_inx: MAX. bit rate (index) for LHDC 5.0 encoding
//           range [LHDCV5_QUALITY_LOW, LHDCV5_QUALITY_MAX_BITRATE].
//      [in] max_bitrate_inx_set: a returned pointer to MAX. set bit rate (index).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_max_bitrate_inx
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  max_bitrate_inx,
    uint32_t  *max_bitrate_inx_set
);

//----------------------------------------------------------------
// lhdcv5_util_set_min_bitrate_inx ()
//
// Set the minimum bitrate of peer device
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] min_bitrate_inx: MIN. bit rate (index) for LHDC 5.0 encoding
//           range [LHDCV5_QUALITY_LOW0, LHDCV5_QUALITY_LOW].
//      [in] min_bitrate_inx_set: a returned pointer to MIN. bit rate (index) set.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_min_bitrate_inx
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  min_bitrate_inx,
    uint32_t  *min_bitrate_inx_set
);

//----------------------------------------------------------------
// lhdcv5_util_adjust_bitrate ()
//
// Get the parameters of auto bit rate mode
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] enc_type_ptr: a returned pointer to encoder type.
//      [in] abr_para_ptr: a returned pointer to auto bitrate parameters.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_adjust_bitrate
(
    HANDLE_LHDCV5_BT  handle,
    LHDCV5_ENC_TYPE_T  *enc_type_ptr,
    lhdcv5_abr_para_t  **abr_para_ptr
);

//----------------------------------------------------------------
// lhdcv5_util_reset_up_bitrate ()
//
// Reset Auto Bitrate bit rate uptier checking parameters
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_reset_up_bitrate
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_reset_down_bitrate ()
//
// Reset Auto Bitrate bit rate donwtier checking parameters
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_reset_down_bitrate
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_init_encoder ()
//
// Initialize LHDC 5.0 encoder
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] sampling_freq: sample frequency, ex: 44100(44.1KHz).
//      [in] bits_per_sample: bits per sample, ex: 16 or 24.
//      [in] bitrate_inx: bit rate index.
//      [in] frame_duration: frame length in the unit of 0.1ms, ex: 50(5ms), 100(10ms).
//      [in] mtu: transmitting MTU size in byte.
//      [in] interval: period of encoding, ex: 20(20ms).
//      [in] is_lossless_enable: enable(1) or disable(0) lossless feature
//      [in] is_br128_enable: enable(1) or disable(0) quality improved bitrate 128kbps feature
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_init_encoder
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  sampling_freq,
    uint32_t  bits_per_sample,
    uint32_t  bitrate_inx,
    uint32_t  frame_duration,
    uint32_t  mtu,
    uint32_t  interval,
    uint32_t  is_lossless_enable,
    uint32_t  is_br128_enable
);

//----------------------------------------------------------------
// lhdcv5_util_get_block_Size ()
//
// Get number of samples per block for LHDC 5.0 encoder
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] block_size: a returned pointer to the number of samples per block(frame).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_block_Size
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  *block_size
);

//----------------------------------------------------------------
// lhdcv5_util_enc_process ()
//
// Encode pcm samples by LHDC 5.0
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] p_pcm: a pointer to the input PCM frame buffer.
//      [in] pcm_bytes: byte length of PCM frame in the input pcm buffer.
//      [in] out_put: a pointer to the output encoded frame buffer.
//      [in] out_buf_bytes: byte length of the output buffer.
//      [in] written: a returned pointer to the bytes of output encoded frames.
//      [in] out_frames: a returned pointer to the number of output encoded frames.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_enc_process
(
    HANDLE_LHDCV5_BT  handle,
    void  *p_pcm,
    uint32_t  pcm_bytes,
    uint8_t  *out_put,
    uint32_t  out_buf_bytes,
    uint32_t  *written,
    uint32_t  *out_frames
);

//----------------------------------------------------------------
// lhdcv5_util_get_bitrate ()
//
// Get bit rate (kbps) by the bit rate stage index
//  Parameter
//      [in] bitrate_inx: bit rate (index).
//      [in] bitrate: a returned pointer to bit rate (kbps).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_bitrate
(
    uint32_t  bitrate_inx,
    uint32_t  *bitrate
);

//----------------------------------------------------------------
// lhdcv5_util_get_bitrate_inx ()
//
// Get bit rate stage index by bit rate (kbps)
//  Parameter
//      [in] bitrate: bit rate (kbps).
//      [in] bitrate_inx: a returned pointer to bit rate (index).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_bitrate_inx
(
    uint32_t  bitrate,
    uint32_t  *bitrate_inx
);

//----------------------------------------------------------------
// lhdcv5_util_set_vbr_up_th ()
//
// Set VBR tier up threshold (percentage)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] value : value of percentage to configure VBR UPtier threshold.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_vbr_up_th
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  value
);

//----------------------------------------------------------------
// lhdcv5_util_set_vbr_dn_th ()
//
// Set VBR tier down threshold (percentage)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] value : value of percentage to configure VBR DOWNtier threshold.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_vbr_dn_th
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  value
);

//----------------------------------------------------------------
// lhdcv5_util_set_vbr_up_intv ()
//
// Set count of VBR tier up checking interval
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] value : number of ticks for VBR UP checking interval.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_vbr_up_intv
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  value
);

//----------------------------------------------------------------
// lhdcv5_util_set_vbr_dn_intv ()
//
// Set count of VBR tier down checking interval
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] value : number of ticks for VBR UP checking interval.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_vbr_dn_intv
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  value
);

//----------------------------------------------------------------
// lhdcv5_util_get_lossless_enabled ()
//
// Get status of lossless enabled(1)/disabled(0)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] enabled : a returned pointer to lossless enabled(1)/disabled(0).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_lossless_enabled
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  *enabled
);

//----------------------------------------------------------------
// lhdcv5_util_get_lossless_status ()
//
// Get lossless runtime status ON(1)/OFF(0)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] status: lossless runtime status: ON(1)/OFF(0).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_lossless_status
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  *status
);

//----------------------------------------------------------------
// lhdcv5_util_set_lossless_status ()
//
// Set lossless runtime status ON(1)/OFF(0)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] status_set: lossless runtime status: ON(1)/OFF(0).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_lossless_status
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  status_set
);

//----------------------------------------------------------------
// lhdcv5_util_set_lossless_raw_enabled ()
//
// Set lossless raw mode enabled(1)/disabled(0)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] enabled: lossless raw mode enabled(1)/disabled(0).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_lossless_raw_enabled
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  status_set
);

//----------------------------------------------------------------
// lhdcv5_util_vbr_process ()
//
// Perform VBR process (when lossless is enabled)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] vbr_type : selecting bitrate table of VBR.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_vbr_process
(
    HANDLE_LHDCV5_BT  handle,
    LHDCV5_VBR_TYPE_T  vbr_type
);

//----------------------------------------------------------------
// lhdcv5_util_vbr_plus_process ()
//
// Perform VBR-plus process (lossless raw enabled only)
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] vbr_type : selecting bitrate table of VBR.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_vbr_plus_process
(
    HANDLE_LHDCV5_BT  handle,
    LHDCV5_VBR_TYPE_T  vbr_type
);

//----------------------------------------------------------------
// lhdcv5_util_get_current_mtu ()
//
// Get current mtu (bytes) which configured into encoder
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] current_mtu: a returned pointer to the mtu (size bytes).
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_current_mtu
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  *current_mtu
);

//----------------------------------------------------------------
// lhdcv5_util_set_target_mtu ()
//
// Set the mtu (bytes) for LHDC 5.0 encoding
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] target_mtu: new mtu to set.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_set_target_mtu
(
    HANDLE_LHDCV5_BT  handle,
    uint32_t  target_mtu
);

//----------------------------------------------------------------
// lhdcv5_util_reset_up_bitrate_vbr ()
//
// Reset VBR bit rate tier up checking parameters
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_reset_up_bitrate_vbr
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_reset_down_bitrate_vbr ()
//
// Reset VBR bit rate tier down checking parameters
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_reset_down_bitrate_vbr
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_reset_lossless_stat ()
//
// Reset lossless statistics record
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_reset_lossless_stat
(
    HANDLE_LHDCV5_BT  handle
);

//----------------------------------------------------------------
// lhdcv5_util_get_lib_auth_string ()
//
// Get license authentication string form LHDC library
//  Parameter
//      [in] str_buf: a pointer to the buffer to store returned string
//      [in] buf_byte_size: byte size of str_buf
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_get_lib_auth_string
(
    uint8_t  *str_buf,
    uint32_t  buf_byte_size
);

/* * *********************************************************************************
 * APIs only supported when Meta feature is enabled (default: disabled)
 * * *********************************************************************************/
//----------------------------------------------------------------
// lhdcv5_util_meta_set_data ()
//
// Embed the meta data (8 BYTEs) to encoded frame
//  Parameter
//      [in] handle: a pointer to the memory resource allocated to the encoder.
//      [in] enable_embed_meta:
//          1: enable to embed meta data (8 BYTEs) to next encoded frame
//          0: disable to embed meta data
//      [in] meta_data: a pointer to a buffer contains meta data (8 BYTEs)
//      [in] embed_frame_cnt: duplicate meta data to the number of continuous encoded frames
//  Return
//      LHDCV5_FRET_SUCCESS: Succeed
//      otherwise: Fail
//----------------------------------------------------------------
int32_t lhdcv5_util_meta_set_data
(
    HANDLE_LHDCV5_BT handle,
    int32_t  enable_embed_meta,
    uint8_t  *meta_data,
    int32_t  embed_frame_cnt
);

#ifdef __cplusplus
}
#endif
#endif //End of __LHDCV5_API_H__
