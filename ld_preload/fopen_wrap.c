/*
 * =====================================================================================
 *
 *       Filename:  fopen_wrap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2013 11:41:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

FILE *fopen(const char *path, const char *mode)
{
    printf("In our own fopen, opening %s\n", path);

    FILE *(*original_fopen)(const char *, const char *);
    original_fopen = dlsym(RTLD_NEXT, "fopen");
    return (*original_fopen)(path, mode);
}
