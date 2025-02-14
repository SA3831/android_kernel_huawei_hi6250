﻿/*!
 *****************************************************************************
 *
 * @File       hevcfw_data_shared.h
 * @Title      Public data structures for the HEVC parser firmware module
 * @Description    Public data structures for the HEVC parser firmware module
 * ---------------------------------------------------------------------------
 *
 * Copyright (c) Imagination Technologies Ltd.
 * 
 * The contents of this file are subject to the MIT license as set out below.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 * 
 * Alternatively, the contents of this file may be used under the terms of the 
 * GNU General Public License Version 2 ("GPL")in which case the provisions of
 * GPL are applicable instead of those above. 
 * 
 * If you wish to allow use of your version of this file only under the terms 
 * of GPL, and not to allow others to use your version of this file under the 
 * terms of the MIT license, indicate your decision by deleting the provisions 
 * above and replace them with the notice and other provisions required by GPL 
 * as set out in the file called "GPLHEADER" included in this distribution. If 
 * you do not delete the provisions above, a recipient may use your version of 
 * this file under the terms of either the MIT license or GPL.
 * 
 * This License is also included in this distribution in the file called 
 * "MIT_COPYING".
 *
 *****************************************************************************/

#ifdef USE_SHARING
#endif

#ifndef _HEVCFW_DATA_H_
#define _HEVCFW_DATA_H_

#include "vdecfw_share.h"

#include "img_types.h"
#include "vdecfw.h"

#define HEVC_MAX_VPS_COUNT         16
#define HEVC_MAX_SPS_COUNT         16
#define HEVC_MAX_PPS_COUNT         64


#define HEVCFW_MAX_NUM_PROFILE_IDC 32
#define HEVCFW_MAX_VPS_OP_SETS_PLUS1 1024
#define HEVCFW_MAX_VPS_NUH_RESERVED_ZERO_LAYER_ID_PLUS1 1

#define HEVCFW_MAX_NUM_REF_PICS 16
#define HEVCFW_MAX_NUM_ST_REF_PIC_SETS 65
#define HEVCFW_MAX_NUM_LT_REF_PICS 32
#define HEVCFW_MAX_NUM_SUBLAYERS 7
#define HEVCFW_SCALING_LISTS_BUFSIZE 256
#define HEVCFW_MAX_TILE_COLS 20
#define HEVCFW_MAX_TILE_ROWS 22

#define HEVCFW_MAX_CHROMA_QP 6

#define HEVCFW_MAX_DPB_SIZE HEVCFW_MAX_NUM_REF_PICS
#define HEVCFW_REF_PIC_LIST0 0
#define HEVCFW_REF_PIC_LIST1 1
#define HEVCFW_NUM_REF_PIC_LISTS 2
#define HEVCFW_NUM_DPB_DIFF_REGS 4

/* non-critical errors*/
#define HEVC_ERR_INVALID_VALUE (20)
#define HEVC_ERR_CORRECTION_VALIDVALUE (21)

#define HEVC_IS_ERR_CRITICAL(err) (err > HEVC_ERR_CORRECTION_VALIDVALUE ? IMG_TRUE : IMG_FALSE)

/* critical errors*/
#define HEVC_ERR_INV_VIDEO_DIMENSION (22)
#define HEVC_ERR_NO_SEQUENCE_HDR (23)
#define HEVC_ERR_SPS_EXT_UNSUPP (24 | VDECFW_UNSUPPORTED_CODE_BASE)
#define HEVC_ERR_PPS_EXT_UNSUPP (25 | VDECFW_UNSUPPORTED_CODE_BASE)

#define HEVC_ERR_FAILED_TO_STORE_VPS (100)
#define HEVC_ERR_FAILED_TO_STORE_SPS (101)
#define HEVC_ERR_FAILED_TO_STORE_PPS (102)

#define HEVC_ERR_FAILED_TO_FETCH_VPS (103)
#define HEVC_ERR_FAILED_TO_FETCH_SPS (104)
#define HEVC_ERR_FAILED_TO_FETCH_PPS (105)
// HEVC Scaling Lists (all values are maximum possible ones)
#define HEVCFW_SCALING_LIST_NUM_SIZES 4
#define HEVCFW_SCALING_LIST_NUM_MATRICES 6
#define HEVCFW_SCALING_LIST_MATRIX_SIZE 64

/*!
******************************************************************************
    HEVC Scaling Lists
******************************************************************************/
typedef struct
{
    IMG_UINT8 aui8DcCoeffs
        [HEVCFW_SCALING_LIST_NUM_SIZES - 2]
        [HEVCFW_SCALING_LIST_NUM_MATRICES];

    IMG_UINT8 aui8Lists
        [HEVCFW_SCALING_LIST_NUM_SIZES]
        [HEVCFW_SCALING_LIST_NUM_MATRICES]
        [HEVCFW_SCALING_LIST_MATRIX_SIZE];

} HEVCFW_sScalingListData;

/*!
******************************************************************************
    HEVC Video Profile_Tier_Level
******************************************************************************/
typedef struct
{
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_profile_space);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_tier_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_profile_idc);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_profile_compatibility_flag[HEVCFW_MAX_NUM_PROFILE_IDC]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_progressive_source_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_interlaced_source_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_non_packed_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_frame_only_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_12bit_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_10bit_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_8bit_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_422chroma_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_420chroma_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_max_monochrome_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_intra_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_one_picture_only_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_lower_bit_rate_constraint_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, general_level_idc);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_profile_present_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_level_present_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_profile_space[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_tier_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_profile_idc[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_profile_compatibility_flag[HEVCFW_MAX_NUM_SUBLAYERS-1][HEVCFW_MAX_NUM_PROFILE_IDC]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_progressive_source_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_interlaced_source_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_non_packed_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_frame_only_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_12bit_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_10bit_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_8bit_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_422chroma_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_420chroma_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_max_monochrome_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_intra_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_one_picture_only_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_lower_bit_rate_constraint_flag[HEVCFW_MAX_NUM_SUBLAYERS-1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sub_layer_level_idc[HEVCFW_MAX_NUM_SUBLAYERS-1]);
} HEVCFW_sProfileTierLevel;

typedef struct
{
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL, bIsDifferent);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL, bIsSent);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL, bIsAvailable);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_video_parameter_set_id);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_reserved_three_2bits);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_layers_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_sub_layers_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_temporal_id_nesting_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, vps_reserved_0xffff_16bits);
    HEVCFW_sProfileTierLevel sProfileTierLevel;

/*  we do not use this flags
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_dec_pic_buffering_minus1[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_num_reorder_pics[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_latency_increase_plus1[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_sub_layer_ordering_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_max_layer_id);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_num_layer_sets_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, layer_id_included_flag[HEVCFW_MAX_VPS_OP_SETS_PLUS1][HEVCFW_MAX_VPS_NUH_RESERVED_ZERO_LAYER_ID_PLUS1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_timing_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, vps_num_units_in_tick);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, vps_time_scale);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_poc_proportional_to_timing_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_num_ticks_poc_diff_one_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_num_hrd_parameters);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_extension_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vps_extension_data_flag);
*/
} HEVCFW_sVideoPS;

/*!
******************************************************************************
    HEVC Video Usability Information
******************************************************************************/
typedef struct
{
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, aspect_ratio_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, aspect_ratio_idc);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, sar_width);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, sar_height);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, overscan_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, overscan_appropriate_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, video_signal_type_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, video_format);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, video_full_range_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, colour_description_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, colour_primaries);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, transfer_characteristics);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, matrix_coeffs);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_loc_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_sample_loc_type_top_field);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_sample_loc_type_bottom_field);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, neutral_chroma_indication_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, field_seq_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, frame_field_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, default_display_window_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, def_disp_win_left_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, def_disp_win_right_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, def_disp_win_top_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, def_disp_win_bottom_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vui_timing_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, vui_num_units_in_tick);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, vui_time_scale);

/*  we do not need this flags
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vui_poc_proportional_to_timing_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, vui_num_ticks_poc_diff_one_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vui_hrd_parameters_present_flag);
    BSPP_sHEVCHrdParameters sVUIHRDParams;
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, bitstream_restriction_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, tiles_fixed_structure_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, motion_vectors_over_pic_boundaries_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, restricted_ref_pic_lists_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, min_spatial_segmentation_idc);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, max_bytes_per_pic_denom);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, max_bits_per_min_cu_denom);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_max_mv_length_horizontal);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_max_mv_length_vertical);
    */
} HEVCFW_sVuiParams;

/*!
******************************************************************************
    HEVC Short Term Reference Picture Set
******************************************************************************/
typedef struct
{
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, NumNegativePics);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, NumPositivePics);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT16, DeltaPocS0[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT16, DeltaPocS1[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, UsedByCurrPicS0[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, UsedByCurrPicS1[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, NumDeltaPocs);
} HEVCFW_sShortTermRefPicSet;

/*!
******************************************************************************
 This describes the SPS header data required by the HEVC firmware that should
 be supplied by the Host.
******************************************************************************/
typedef struct
{
    /* syntax elements from SPS */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, pic_width_in_luma_samples);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, pic_height_in_luma_samples);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_short_term_ref_pic_sets);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_long_term_ref_pics_sps);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, lt_ref_pic_poc_lsb_sps[HEVCFW_MAX_NUM_LT_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, used_by_curr_pic_lt_sps_flag[HEVCFW_MAX_NUM_LT_REF_PICS]);
    HEVCFW_sShortTermRefPicSet asStRpsList[HEVCFW_MAX_NUM_ST_REF_PIC_SETS];
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_max_sub_layers_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_max_dec_pic_buffering_minus1[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_max_num_reorder_pics[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, sps_max_latency_increase_plus1[HEVCFW_MAX_NUM_SUBLAYERS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, max_transform_hierarchy_depth_inter);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, max_transform_hierarchy_depth_intra);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_diff_max_min_transform_block_size);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_min_transform_block_size_minus2);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_diff_max_min_luma_coding_block_size);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_min_luma_coding_block_size_minus3);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_format_idc);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, separate_colour_plane_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_extra_slice_header_bits);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_max_pic_order_cnt_lsb_minus4);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, long_term_ref_pics_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sample_adaptive_offset_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_temporal_mvp_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, bit_depth_luma_minus8);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, bit_depth_chroma_minus8);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pcm_sample_bit_depth_luma_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pcm_sample_bit_depth_chroma_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_min_pcm_luma_coding_block_size_minus3);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_diff_max_min_pcm_luma_coding_block_size);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pcm_loop_filter_disabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, amp_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pcm_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, strong_intra_smoothing_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, scaling_list_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, transform_skip_rotation_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, transform_skip_context_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, implicit_rdpcm_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, explicit_rdpcm_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, extended_precision_processing_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, intra_smoothing_disabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, high_precision_offsets_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, persistent_rice_adaptation_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, cabac_bypass_alignment_enabled_flag);

    /* derived elements */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32PicSizeInCtbsY);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, ui16PicHeightInCtbsY);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, ui16PicWidthInCtbsY);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8CtbSizeY);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8CtbLog2SizeY);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT32, i32MaxPicOrderCntLsb);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32SpsMaxLatencyPictures[HEVCFW_MAX_NUM_SUBLAYERS]);

//#ifdef VDEC_USE_PVDEC_SEC
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_seq_parameter_set_id);                                                   //!< syntax element from bitstream
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_video_parameter_set_id);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_temporal_id_nesting_flag);//local?
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_seq_parameter_set_id);
    
    //local?
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, conformance_window_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, conf_win_left_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, conf_win_right_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, conf_win_top_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, conf_win_bottom_offset);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_sub_layer_ordering_info_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_scaling_list_data_present_flag);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, vui_parameters_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sps_extension_present_flag);

    HEVCFW_sVuiParams sVUIParams;

    /* derived elements */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8SubWidthC);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8SubHeightC);

    HEVCFW_sProfileTierLevel sProfileTierLevel;
    HEVCFW_sScalingListData sScalingListData;
//#endif /* VDEC_USE_PVDEC_SEC */


} HEVCFW_sSequencePS;

/*!
******************************************************************************
 This describes the HEVC parser component "Header data", shown in the
 Firmware Memory Layout diagram. This data is required by the HEVC firmware
 and should be supplied by the Host.
******************************************************************************/
typedef struct
{
    /* Decode buffers and output control for the current picture */
    VDECFW_sImageBuffer sPrimary; //!< Primary decode buffer base addresses
    VDECFW_sImageBuffer sAlternate; //!< buffer base addresses for alternate output

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32TemporalOutAddr); //!< address of buffer for temporal mv params

} HEVCFW_sHeaderData;

/*!
******************************************************************************
 This describes the PPS header data required by the HEVC firmware that should
 be supplied by the Host.
******************************************************************************/
typedef struct
{
    /* syntax elements from the PPS */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_pic_parameter_set_id);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_tile_columns_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_tile_rows_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, diff_cu_qp_delta_depth);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, init_qp_minus26);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, pps_beta_offset_div2);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, pps_tc_offset_div2);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, pps_cb_qp_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, pps_cr_qp_offset);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_parallel_merge_level_minus2);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, dependent_slice_segments_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, output_flag_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_extra_slice_header_bits);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, lists_modification_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, cabac_init_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, weighted_pred_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, weighted_bipred_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_slice_chroma_qp_offsets_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, deblocking_filter_override_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, tiles_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, entropy_coding_sync_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, slice_segment_header_extension_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, transquant_bypass_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, cu_qp_delta_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, transform_skip_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, sign_data_hiding_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_ref_idx_l0_default_active_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, num_ref_idx_l1_default_active_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, constrained_intra_pred_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_deblocking_filter_disabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_loop_filter_across_slices_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, loop_filter_across_tiles_enabled_flag);
    /* rewritten from SPS, maybe at some point we could get rid of this */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, scaling_list_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, log2_max_transform_skip_block_size_minus2);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, cross_component_prediction_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_qp_offset_list_enabled_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, diff_cu_chroma_qp_offset_depth);

    /* PVDEC derived elements. HEVCFW_SCALING_LISTS_BUFSIZE is multiplied by 2
     * to ensure that there will be space for address of each element. 
     * These addresses are completed in lower layer. */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, aui32ScalingLists[HEVCFW_SCALING_LISTS_BUFSIZE * 2]);

    /* derived elements */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, aui16ColBd[HEVCFW_MAX_TILE_COLS + 1]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, aui16RowBd[HEVCFW_MAX_TILE_ROWS + 1]);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, chroma_qp_offset_list_len_minus1);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, cb_qp_offset_list[HEVCFW_MAX_CHROMA_QP]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, cr_qp_offset_list[HEVCFW_MAX_CHROMA_QP]);

//#ifdef VDEC_USE_PVDEC_SEC
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, uniform_spacing_flag );
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, column_width_minus1[HEVCFW_MAX_TILE_COLS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, row_height_minus1[HEVCFW_MAX_TILE_ROWS]);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_seq_parameter_set_id);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, deblocking_filter_control_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_scaling_list_data_present_flag);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, pps_extension_present_flag);
	
    HEVCFW_sScalingListData sScalingList;	
//#endif /* VDEC_USE_PVDEC_SEC */

} HEVCFW_sPicturePS;

/*!
******************************************************************************
 This enum determines reference picture status
******************************************************************************/
typedef enum
{
    HEVCFW_REF_UNUSED = 0,
    HEVCFW_REF_SHORTTERM,
    HEVCFW_REF_LONGTERM
} HEVCFW_eReferenceType;

/*!
******************************************************************************
 This describes an HEVC picture. It is part of the Context data
******************************************************************************/
typedef IMG_INT32 HEVCFW_Poc;
typedef struct
{
    VDECFW_sImageBuffer sPrimary; //!< Primary (reconstructed) picture buffers
    VDECFW_sImageBuffer sAlternate; //!< Secondary (alternative) picture buffers

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32TransactionId); //!< Unique ID for this picture

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NalUnitType); //!< nut of first ssh of picture, determines picture type
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, iPicOrderCntVal); //!< Picture Order Count (frame number)
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, iSlicePicOrderCntLsb); //!< Slice Picture Order Count Lsb
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, bPicOutputFlag); //!< PicOutputFlag

    /* information for collocated pictures */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT16, ui16DpbLongtermFlags); //!< information about long-term pictures
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, aui32DpbPicOrderDiff[HEVCFW_NUM_DPB_DIFF_REGS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32TemporalOutAddr); //!< address of buffer for temporal mv params
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32DpbDiff); //!<  worst case Dpb diff for the current pic
} HEVCFW_sPicture;

/*!
******************************************************************************
 This is a wrapper for a picture to hold it in a Decoded Picture Buffer
 for further reference
******************************************************************************/
typedef struct
{
    /* DPB data about the picture */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_eReferenceType, eRefType);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, bValid);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, bNeededForOutput);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_INT8, i16PicLatencyCount);

    /* Picture itself */
    HEVCFW_sPicture sPicture;
} HEVCFW_sPictureInDpb;

/*!
******************************************************************************
 This describes an HEVC's Decoded Picture Buffer (DPB).
 It is part of the Context data
******************************************************************************/
typedef IMG_INT8 HEVCFW_DpbIdx;
#define HEVCFW_DPB_IDX_INVALID -1
typedef struct
{
    /* reference pictures */
    HEVCFW_sPictureInDpb asPictures[HEVCFW_MAX_DPB_SIZE];

    /* organizational data of DPB */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32Fullness);
} HEVCFW_sDecodedPictureBuffer;

/*!
******************************************************************************
 This describes an HEVC's Reference Picture Set (RPS).
 It is part of the Context data
******************************************************************************/
typedef struct
{
    /* sizes of poc lists */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NumPocStCurrBefore);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NumPocStCurrAfter);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NumPocStFoll);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NumPocLtCurr);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, ui8NumPocLtFoll);

    /* poc lists */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, aiPocStCurrBefore[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, aiPocStCurrAfter[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, aiPocStFoll[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, aiPocLtCurr[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, aiPocLtFoll[HEVCFW_MAX_NUM_REF_PICS]);

    /* derived elements */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, abCurrDeltaPocMsbPresentFlag[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, abFollDeltaPocMsbPresentFlag[HEVCFW_MAX_NUM_REF_PICS]);

    /* reference picture sets: indices in DPB */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, iRefPicSetLtCurr[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, iRefPicSetLtFoll[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, iRefPicSetStCurrBefore[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, iRefPicSetStCurrAfter[HEVCFW_MAX_NUM_REF_PICS]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, iRefPicSetStFoll[HEVCFW_MAX_NUM_REF_PICS]);

} HEVCFW_sReferencePictureSet;

/*!
******************************************************************************
 This describes the HEVC parser component "Context data", shown in the
 Firmware Memory Layout diagram. This data is the state preserved across
 pictures. It is loaded and saved by the Firmware, but requires the host to
 provide buffer(s) for this.
******************************************************************************/
typedef struct
{
    HEVCFW_sSequencePS sSps;
    HEVCFW_sPicturePS  sPps;

    /* data from last picture with TemporalId = 0 that is not a RASL, RADL
     * or sub-layer non-reference picture */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, iPrevPicOrderCntLsb);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_Poc, iPrevPicOrderCntMsb);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL8, bLastIrapNoRaslOutputFlag);

    /* Decoded Pictures Buffer holds information about decoded pictures
     * needed for further INTER decoding */
    HEVCFW_sDecodedPictureBuffer sDpb;
    /* Reference Picture Set is determined on per-picture basis */
    HEVCFW_sReferencePictureSet sRps;
    /* Reference Picture List is determined using data from Reference Picture
     * Set and from Slice (Segment) Header on per-slice basis */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, HEVCFW_DpbIdx, aiRefPicList[HEVCFW_NUM_REF_PIC_LISTS][HEVCFW_MAX_NUM_REF_PICS]);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32PicCount);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT32, ui32SliceSegmentCount);

    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL, bEOSdetected); /* There was EOS NAL detected and no new picture yet */
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_BOOL, bFirstAfterEOS); /* This is first picture after EOS NAL */

#ifdef VDEC_USE_PVDEC_SEC
    HEVCFW_sVideoPS    sVps;
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, aSPSValid[HEVC_MAX_SPS_COUNT/8]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, aPPSValid[HEVC_MAX_PPS_COUNT/8]);
    IMG_ALIGN_FIELD(VDECFW_SHARE_DEFAULT_ALIGNMENT, IMG_UINT8, aVPSValid[HEVC_MAX_VPS_COUNT/8]);
#endif /* VDEC_USE_PVDEC_SEC */

} HEVCFW_sContextData;


#endif /* _HEVCFW_DATA_H_ */

