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
#include <errno.h>
#define _BUFSIZ 1024
#define HISTORY_COUNT 1024
#define INPUT_DELIM " "
#define PROMPT ";)$ "
#define PROMPT_LEN 4
#define UNUSED(x) (void)(x)
/**
 * struct string_linked_list - a linked list of strings
 * @str: the string
 * @next: next in the list
 */
typedef struct string_linked_list
{
	char *str;
	struct string_linked_list *next;
} sll;
extern char **environ;
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
void _shistory(char *input, int add);
char *_strtok(char *s, char *delim);
int check_builtins(sll *head);
char *_itoa(int val, int base);
void _control_c(int sig);
void _cd(char *input);
char *cut_off(char *to_cut, int num_to_cut);

#endif
