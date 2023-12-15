#ifndef JCSHELL_H
#define JCSHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void custom_print(const char *str);
void execute_command(const char *command);

#endif /* JCSHELL_H */
