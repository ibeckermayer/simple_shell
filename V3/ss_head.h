#ifndef _SS_HEADER__
#define _SS_HEADER__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#define _BUFSIZ 1024
#define MAX_CMD_LEN  128
#define HISTORY_COUNT 1 << 10
#define UNUSED(x) (void)(x)
typedef struct p_ll
{
	char *pdir;
	struct p_ll *next;
} pll;

pll *path_ll(void);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name);
char *find_path(char **environ);
char *_strdup(char *str);
char *get_input(void);
int _getppid(void);
void show_prompt(void);
char *f_cmd(char *command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(const char *s1, const char *s2);
void print_env(void);
void _sexit(void);
void _sclear(void);
void _shistory(char **history, int current);
char *_strtok(char *s, char *delim);
#endif
