//
//  main.c
//  UnixTools
//
//  Created by Waldir Bertazzi Junior on 12/14/13.
//  Copyright (c) 2013 Waldir Bertazzi Junior. All rights reserved.
//
// Boolean definition
#define bool int
#define true 1
#define false 0


#include <string.h>
#include "commands.h"
#include "tools.h"

// Accepted commands
#define LS 0


// Headers
int get_command(const char * command);
bool run_command(int code, const char * args[]);

int main(int argc, const char * argv[])
{
    
    if (argc <= 2) {
        err_quit("Usage: unixtools <command> [<arguments>]");
    }

    // Checks and run the command
    run_command(get_command(argv[1]), argv);
    
    return 0;
}

int get_command(const char * command){
    if (strcmp(command, "ls")) {
        return LS;
    }
    
    return false;
}

bool run_command(int code, const char * args[]){
    switch (code) {
        case LS:
            return ls(args);
            break;
            
        default:
            err_quit("Error: Command not found.");
    }
    
    return false;
}