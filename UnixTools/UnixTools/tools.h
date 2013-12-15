//
//  tools.h
//  UnixTools
//
//  Created by Waldir Bertazzi Junior on 12/14/13.
//  Copyright (c) 2013 Waldir Bertazzi Junior. All rights reserved.
//

#include <stdio.h>

void show_message(char type, char* message);

void err_quit(const char* message, ...);
void err_sys(const char* message, ...);