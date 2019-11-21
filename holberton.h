#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *findenv(char *path);
char **tokens(char *str);
int _putchar(char c);
void printenv(char **env);

#endif
