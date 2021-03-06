/*
 * Copyright (C) 2002 Brent N. Chun <bnc@caltech.edu>
 */
#ifndef __MSG_H
#define __MSG_H

#include "gexec_lib.h"

/* Message types (down) */
#define GEXEC_TREE_CREATE_MSG        0
#define GEXEC_JOB_MSG                1
#define GEXEC_STDIN_MSG              2
#define GEXEC_SIGNAL_MSG             3

/* Message types (up) */
#define GEXEC_STDOUT_MSG            10
#define GEXEC_STDERR_MSG            11
#define GEXEC_HEARTBEAT_MSG         12

/* Reply message types (up) */
#define GEXEC_TREE_CREATE_REPLY_MSG 20
#define GEXEC_JOB_REPLY_MSG         21

/* Error message types (up) */
#define GEXEC_TREE_CREATE_ERROR_MSG 30
#define GEXEC_JOB_ERROR_MSG         31

/* Header */
typedef struct {
    int type;
    int src;
    int dst;
    int bdy_len;
} gexec_hdr;

/* All nodes in the tree */
#define GEXEC_DST_ALL               -1

#define GEXEC_HDR_BUILD(__hdr, __type, __src, __dst, __bdy_len) \
        (__hdr)->type    = __type;    \
        (__hdr)->src     = __src;     \
        (__hdr)->dst     = __dst;     \
        (__hdr)->bdy_len = __bdy_len;

/* Body for fixed message types */

typedef struct {
    int sig;
} gexec_signal_bdy;

typedef struct {
    int xxx;
} gexec_hb_bdy;

typedef struct {
    int rval;
} gexec_tc_reply_bdy;

typedef struct {
    int rval;
} gexec_job_reply_bdy;

typedef struct {
    int rval;
    int bad_nodes[GEXEC_BITMASK_SIZE];
} gexec_tc_error_bdy;

typedef struct {
    int rval;
} gexec_job_error_bdy;

/* Max size for stdout, stdout, stderr msg bodies */
#define GEXEC_IO_CHUNK   4096

#endif /* __MSG_H */
