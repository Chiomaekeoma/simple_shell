#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern char **environ;
char **split_command(char *cmd);
int append_path(char **cmd);
void execute_cmd(char **cmd, char *buffer);
int check_builtin(char **cmd, char *buffer);
int exit_func(char **cmd);
int _strlen(const char *s);
int _unsetenv(const char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void cd_func(char *dest_Dir);
#endif
