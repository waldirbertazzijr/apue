//
//  tools.c
//  UnixTools
//
//  Created by Waldir Bertazzi Junior on 12/14/13.
//  Copyright (c) 2013 Waldir Bertazzi Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#define MAXLINE 4096


static void err_doit(int, int, const char *, va_list);

// Function that shows an error message and quits the program.
void err_quit(const char *fmt, ...) {
    va_list ap;
    
    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}

void err_sys(const char *fmt, ...) {
    va_list ap;
    
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap) {
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, ap);
    
    if (errnoflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
    }
    
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}