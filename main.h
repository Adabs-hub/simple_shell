#ifndef _MAIN_H_
#define _MAIN_H_

#define BUF_SIZE 64

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>



/**
 * struct data - data
 * @av: main argument
 * @arg: com string
 * @args: args data
 * @_environ: environs data
 * @path: path to exercute
 * @env_pathstr: strings in env PATH
 * @lnflag: line flage
 * @lncount: line count
 * @errcount: count number of err outputs
 * @readfd: read socket descripter
 */
typedef struct data
{
	char **av;
	char *arg;
	char **args;
	char **_environ;
	char *path;
	char *env_pathstr;
	int lnflag;
	unsigned int lncount;
	int errcount;
	int readfd;
} data_t;


/**
 * struct builtInFunc - Builtin struct for command args.
 * @arg: builtin command name i.e cd, exit, env
 * @f: pointer to functions
 */
typedef struct builtInFunc
{
	char *arg;
	int (*f)(data_t *);
} buildIn_f;

	/*getline.c*/
	ssize_t _getline(char **f, size_t *f_len, FILE *fstream);

	/*main.c*/
	void getSignal(int signal);
	int setEnviron(data_t *param, char **environ);
	/*string.c*/
	size_t _strlen(char *str);
	int _strcmp(char *s1, char *s2);
	char *_strcpy(char *dest, char *src);
	char **split_tok(char *str, const char *delim);

	/*string2.c*/
	int _putchar(char c);
	int _puts(char *str);
	char *_strcat(char *dest, char *src);
	char *_strstr(char *haystack, char *needle);

	/*string3.c*/
	int _puts_err(char *str);
	char *_strdup(char *str);
	void rev_string(char *s);
	char *_strtok(char str[], const char *delim);

	/*string4.c*/
	char **_reallocdp(char **ptr, unsigned int size, unsigned int new_len);
	int cmp_chars(char str[], const char *delim);
	int isInt(char *str);
	void print_number(int num);

	/*string5.c*/
	int _putchar_err(char c);
	int word_count(char *str);

	/*shell_loop.c*/
	void freeArray(char **array);
	void shellLoop(data_t *param);
	void freeParam(data_t *param);
	int _atoi(char *s);

	/*setPath.c*/
	int handle_path(data_t *param);

	/*lunchShell.c*/
	int executeShell(data_t *param);
	void Print_N_err(data_t *param);

	/*exit.c*/
	int shellExit(data_t *param);
	char *rmComment(char *str);

	/*stdlib.c*/
	void *_realloc(char *ptr, unsigned int len, unsigned int new_len);
	void copyPtr(char **ptr, size_t *ptr_len, char *buf, size_t buf_len);

	/*buildInFunc.c */
	int cdCommand(data_t *param);
	int helpCommand(data_t *param);
	int hdlCtrlCommand(data_t *param);

	/*buildInFunc2.c*/
	int (*get_buildInFunc(data_t *param))(data_t *param);

	/*getEnv.c*/
	int printEnv(data_t *param);
	char *findEnv(const char *name, char **_environ);
	int cmp_env_name(const char *env, const char *name);
	void set_env(char *name, char *value, data_t *param);

	/*geEnv2.c*/
	char *copy_info(char *name, char *value);
	int interactive(data_t *param);

	/*cdFunc.c*/
	void cd_dot(data_t *param);
	void cd_to(data_t *param);
	void cd_previous(data_t *param);
	void cd_to_home(data_t *param);

	/*cdFunc2.c*/
	int runCdFunc(data_t *param);

	/*setPath.c*/
	char *pathSearch(data_t *param);
	char *getenvPath(char *envpath, int offset, int limit);
	int isvalidPath(char *path);
	int handle_path(data_t *param);


	/*setEnv.c*/
	int setEnv(data_t *param);
	int unsetEnv(data_t *param);



#endif /*main.h*/
