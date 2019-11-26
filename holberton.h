#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);

void prompt(char *buffer);
void own_shell(char **env);
char **parse_line(char *buffer);
int execution_line(char **args, char *buffer);
int process_path(char **args, char **env);
void insert_path(char *in_path, char *arg);
void enviroment(char **env);
#endif /* HEADERS */
