#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <unisrd.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shel_history"
#define HIST_MAX 4096

extern char **environ;

/**
  * struct liststr - __singly_liked_list__
  * @num: __number_of_fields
  * @str: __string__
  * @next: __next__pointer__
  */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t

/**
  * struct passinfo - pass info
  * @arg: args
  * @path: path
  * @argc: argc
  * @argv: argv
  * @line_count: line count
  * @err_num: error number
  * @linecount_flag: flag
  * @fname: filename
  * @env:evironment
  * @environ: enviroin
  * @history: hsitory
  * @alias: the alias
  * @env_changed: env
  * @status: status
  * @cmd_buf: cmd buf
  * @cmd_buf_type: cmd type
  * @readfd: fd
  * @histcount: history count
  */

typedef struct passinfo
{
	char *arg;
	char *path;
	int argc;
	char **argv;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t

#define INFO_INIT \
	(NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, \
	 0, 0, NULL, 0, 0, 0)

/**
  *struct builtin - cc
  *@type: type
  *@func: func
  */

typedef struct builtin
{
	char *type;
	int (*func) (info_t *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(info_t *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **); /* doesn't exist*/

void _eputs(char *);
void _eputchar(char);
int _putfd(char, int);
int _putsfd(char *, int);

int _strlen(char *);
int _strcmp(char *, char *);
char *start_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchar(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interactive(info_t *);
int is_delim(char, char*);
int _isalpha(int); /* dosent exist */
int _atoi(char *);

int erratoi(char *);
void pr_error(info_t *, char *); /* */
int pr_d(int, int); /* */
char *con_num(long int, int, int); /* */
void rm_comments(char *); /* */

int _myexit(info_t);
int _mycd(info_t);
int _myhelp(info_t *);

int _myhist(info_t); /* */
int unset_alias(info_t *, char *);
int set_alias(info_t *, char *);
int print_alias(list_t *);
int _myalias(info_t);

ssize_t input_buf(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
ssize_t read_buf(info_t *, char*, size_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

int _myenv(info_t *);
char *_getenv(info_t *, const char *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int pop_env_lst(info_t *);/* */

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_hist_file (info_t *);/* */
int write_hist(info_t *);/* */
int read_hist(info_t *);/* */
int build_hist_list(info_t *, char *, int);/* */
int renumber_hist(info_t *);/* */

list_t *add_node(list_t , const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t pr_lst_str(const list_t *);/* */
int d_node_idx(list_t **, unsigned int);/* */
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_string(list_t *);
size_t pr_lst(const list_t *);
list_t *nod_start(list_t *, char *, char);/* */
ssize_t get_idx(list_t *, list_t *);/* */

int is_chain(info_t *, char *, size_t *);/* */
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char **);

#endif
