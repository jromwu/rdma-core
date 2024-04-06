/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/*
 * Copyright 2023 Bytedance.com, Inc. or its affiliates. All rights reserved.
 */

// #if defined(LTTNG_ENABLED)

#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER rdma_core_mlx5

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "mlx5_trace.h"

#if !defined(__MLX5_TRACE_H__) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define __MLX5_TRACE_H__

#define WR_MAX_SIZE 100

#include <lttng/tracepoint.h>
#include <infiniband/verbs.h>
#include <stdlib.h>

LTTNG_UST_TRACEPOINT_EVENT(
	/* Tracepoint provider name */
	rdma_core_mlx5,

	/* Tracepoint name */
	post_send,

	/* Input arguments */
	LTTNG_UST_TP_ARGS(
		char *, dev,
		uint32_t, src_qp_num,
		char *, opcode,
		uint32_t, bytes
	),

	/* Output event fields */
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_string(dev, dev)
		lttng_ust_field_integer(uint32_t, src_qp_num, src_qp_num)
		lttng_ust_field_string(opcode, opcode)
		lttng_ust_field_integer(uint32_t, bytes, bytes)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	/* Tracepoint provider name */
	rdma_core_mlx5,

	/* Tracepoint name */
	wr,

	/* Input arguments */
	LTTNG_UST_TP_ARGS(
		uint8_t *, op_codes,
		uint32_t, length
	),

	/* Output event fields */
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_sequence(uint8_t, op_codes, op_codes, uint32_t, length)
	)
)

#define rdma_tracepoint(arg...) lttng_ust_tracepoint(arg)

#endif /* __MLX5_TRACE_H__*/

#include <lttng/tracepoint-event.h>

// #else

// #ifndef __MLX5_TRACE_H__
// #define __MLX5_TRACE_H__

// #define rdma_tracepoint(arg...)

// #endif /* __MLX5_TRACE_H__*/

// #endif /* defined(LTTNG_ENABLED) */
