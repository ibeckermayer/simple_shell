#ifndef _SS_HEADER__
#define _SS_HEADER__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
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

#endif
