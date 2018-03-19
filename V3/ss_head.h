#ifndef _SS_HEADER__
#define _SS_HEADER__

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#define _BUFSIZ 1024
#define HISTORY_COUNT 1024
#define INPUT_DELIM " "
#define PROMPT ";)$ "
#define PROMPT_LEN 4
#define UNUSED(x) (void)(x)

char *history[HISTORY_COUNT];
int cur_his;
typedef struct string_linked_list
{
	char *str;
	struct string_linked_list *next;
} sll;
sll *gen_sll(char *str, char *delim);
void add2his(char *input);
void print_sll(sll *head);
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
void _shistory(char **history);
char *_strtok(char *s, char *delim);
int check_builtins(char * input);
char *_itoa(int val, int base);
void _control_c(int sig);

#endif
