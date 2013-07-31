/*
 * =====================================================================================
 *
 *       Filename:  xcb_writev_wrap.c
 *
 *    Description:  wrap xcb_out.c file xcb_writev function.
 *
 *        Version:  1.0
 *        Created:  07/31/2013 02:00:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#define _GNU_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

#include <xcb/xcb.h>
#include <xcb/xcbext.h>
#include <xcb/bigreq.h>

int xcb_writev(xcb_connection_t *c, struct iovec *vector, int count, uint64_t requests)
{
    printf("count:%d, requests:%ld\n", count, requests);

    int *(*original_xcb_writev)(xcb_connection_t *, struct iovec *, int, uint64_t);
    original_xcb_writev = dlsym(RTLD_NEXT, "xcb_writev");

    return (*original_xcb_writev)(c, vector, count, requests);
}

