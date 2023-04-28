#ifndef SHELL_H
#define SHELL_H

#define NUMBER 20

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>


char *read_cmd(void);
char **parse_cmd(char *command);
int num_tok(char *str);
void exit_cmd(char **argu, char *buffer, int Exit);
void get_env(char **env);
int value_path(char **argu, char **env);
char *srch_pth(char **env);
int exec_fork(char **argu, char **av, char **env, char *buffer, int id, int k);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
size_t _strncmp(char *s1, char *s2, size_t n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
char *realloc_buffer(char *buf, size_t *n);
extern char **environ;

#endif /* shell.h */
