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
#include <assert.h>
#define _BUFSIZ 4096
#define HISTORY_COUNT _BUFSIZ
#define INPUT_DELIM " "
#define PROMPT ";)$ "
#define PROMPT_LEN 4
#define UNUSED(x) (void)(x)
/**
 * struct pointers_ll - a linked list of pointers
 * @ptr: the pointer
 * @next: next in the list
 */
typedef struct pointers_ll
{
	void *ptr;
	struct pointers_ll *next;
} pll;
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
int num_errors;
int recall_path;
char *_strcpy(char *dest, char *src);
void _setenv(char *name, char *value, int d);
void _un_setenv(char *name);
sll *gen_sll(char *str, char *delim);
void add2his(char *input);
void print_sll(sll *head);
int _strlen(const char *s);
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
sll **gen_in_l(sll **input_list, char *s, char *prog_name);
void _control_c(int sig);
char *_strcat(char *dest, char *src);
void _cd(sll *head);
char *cut_off(char *to_cut, int num_to_cut);
char *_strcat_slash(char *dest, char *src);
int set_unset(char *dir);
void tests(void);
char *get_error(char *prog_name, int num_errors, sll *head);
char *expand_path(char *path);
void *_calloc(int size);
void free_sll(sll *head);
void free_sll_l(sll **input_list);
int check_for_his(char *input, char *tocheck);
void extract_env();
void free_env();
void check_exit(sll *head, sll **input_list, char *err_msg);
#endif
