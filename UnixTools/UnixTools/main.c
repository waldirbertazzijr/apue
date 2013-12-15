//
//  main.c
//  UnixTools
//
//  Created by Waldir Bertazzi Junior on 12/14/13.
//  Copyright (c) 2013 Waldir Bertazzi Junior. All rights reserved.
//

#include <stdio.h>
#include <dirent.h>
#include "tools.h"


int main(int argc, const char * argv[])
{

    DIR                 *dp;
    struct dirent       *dirp;
    
    if (argc != 2) {
        err_quit("Usage: unixtools <command> [<arguments>]");
    }
    
    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("Can't open %s",  argv[1]);
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    
    closedir(dp);
    exit(0);
}

