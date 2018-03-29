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
void __exit(void);
int *err_code(int *code);
char *_strcpy(char *dest, char *src);
sll *gen_sll(char *str, char *delim);
int _strlen(const char *s);
char *_strdup(char *str);
char *get_input(void);
void show_prompt(void);
char *f_cmd(char *command);
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *s, char *delim);
char *_itoa(int val, int base);
/* sll **gen_in_l(sll **input_list, char *s, char *prog_name); */
sll **gen_in_l(sll **input_list, char *s);
char *_strcat(char *dest, char *src);
char *_strcat_slash(char *dest, char *src);
char *get_error(char *prog_name, int num_errors, sll *head);
void *_calloc(int size);
void free_sll(sll *head);
void free_sll_l(sll **input_list);
int check_builtins(sll *head);
/* int check_for_his(char *input, char *tocheck); */
/* void extract_env(); */
/* void free_env(); */
/* void check_exit(sll *head, sll **input_list, char *err_msg); */
/* void print_env(void); */
/* void _sexit(void); */
/* void _sclear(void); */
/* void _shistory(char *input, int add); */
/* char *expand_path(char *path); */
/* int set_unset(char *dir); */
/* void _cd(sll *head); */
/* int _getppid(void); */
/* void _control_c(int sig); */
/* extern char **environ; */
/* int num_errors; */
/* int recall_path; */
/* char *_getenv(const char *name); */
/* char *find_path(char **environ); */
/* void add2his(char *input); */
/* void print_sll(sll *head); */
/* void _setenv(char *name, char *value, int d); */
/* void _un_setenv(char *name); */
#endif
