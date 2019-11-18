#ifndef HEADERS
#define HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFERSIZE 1024
char *prompt(void);
void own_shell(void);
#endif /* HEADERS */
