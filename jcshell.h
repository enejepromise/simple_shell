/* jcshell.h */
#ifndef JCSHELL_H
#define JCSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGUMENTS 64 // Maximum number of arguments
#define BUFFER_SIZE 1024 // Buffer size for custom getline
#define AND_OPERATOR 1 /* debug */

void custom_print(const char *str);
char *custom_getline(void);
char **read_line(void);
void execute_command(const char *command, char *const arguments[]);
char **tokenize(const char *line);
void execute_with_arguments(const char *line);
char *get_path(const char *command);
int command_exists(const char *command);
void execute_with_path(const char *line);
void exit_shell(void);
void print_environment(void);
void exit_with_status(const char *status);
void set_env_variable(const char *variable, const char *value);
void unset_env_variable(const char *variable);
void change_directory(const char *directory);
void handle_semicolon(const char *commands);
void handle_logical_operators(const char *commands, int operator_type);
void print_aliases(void);
void print_alias(const char *name);
void define_alias(const char *name, const char *value);
char *replace_variables(const char *input);
char *remove_comments(const char *input);
void execute_commands_from_file(const char *filename);
char **tokenize_arguments(const char *line);
char *replace_substring(const char *original, const char *pattern, const char *replacement);
pid_t get_last_exit_status(void);
extern char **environ;
char *get_path(const char *command);

#endif /* JCSHELL_H */
