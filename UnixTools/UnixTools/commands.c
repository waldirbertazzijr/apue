//
//  commands.c
//  UnixTools
//
//  Created by Waldir Bertazzi Junior on 12/15/13.
//  Copyright (c) 2013 Waldir Bertazzi Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "tools.h"

// Boolean definition
#define bool int
#define true 1
#define false 0

// Commands implementations
bool ls(const char * args[]){
    DIR                 *dp;
    struct dirent       *dirp;
    
    dp = opendir(args[2]);
    
    if (dp == NULL) {
        err_sys("Can't open '%s'.",  args[2]);
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    
    closedir(dp);
    
    return true;
}