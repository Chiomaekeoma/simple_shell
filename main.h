#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
extern char **environ;
int _putchar(char c);
char **split_command(char *cmd);
int append_path(char **cmd);
void execute_cmd(char **cmd, char *buffer);
int check_builtin(char **cmd, char *buffer);
int exit_func(char **cmd);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void cd_func(char *dest_Dir);
ssize_t chioli_gtln(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
char *_getenv(const char *name);
#endif
