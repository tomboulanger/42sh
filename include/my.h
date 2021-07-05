/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_ls
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_envp
{
    char **env;
    char *pre_dir;
    char *actual_dir;
    int f_pre_dir;
    int f_actual_dir;
    int pipe;
    char *argv;
    int my_pipe;
    bool cd_;
    int return_value;
    int redirection_right;
    int c_tinue;
    int end;
} t_envp;

/*      Basic Functions     */
void my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char *src);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
void my_putexit(void);

/*      all_arg.c           */

char **all_arg(char *str, int *ab);
char **malloc_result(int nb, char *str);
int nb_arg(char *str);
int check_end(char *str, int i);
int space_case(char *str, int i);

/*      getline.c           */

char **my_getline(t_envp *envp, int *nb);
void free_result(char **result, int nb);
char *end_word(char *string, int i);
int check_allowed_command(char *str);
int str_cmp(char *sa, char *sb);
int check_redir_left(t_envp *envp);

/*      minishell.c         */

int minishell(char **env);
int nb_semicolons(char **res);
char **get_arg(char **res, int nb);
void all_cases(char **av, t_envp *envp, int nb_arg);
char *get_user(char **env);
void echo_cases(char **av, t_envp *envp, int nb_arg);

/*      exit_case.c         */

void exit_case(char **av, int nb_arg, t_envp *envp);
void my_redir_left(char **av, t_envp *envp);

/*      env.c               */

void env(t_envp *envp);

/*      binaries.c      */

int binaries_case(char **av, char **env_p, t_envp *envp);

/*      get_env.c           */

char **get_env(char **env);

/*      check_issaty.c      */

void check_issaty(void);

/*  setenv.c            */

void setenv_case(t_envp *envp, char **av, int nb);

/*      tab.cas.c          */

char *space_first(char *str);
int check_end_tab(char *str, int i);
char *reduc_end(char *src);

/*  unsetenv.               */

void unsetenv_case(char **envp, char **av, int nb);

/*  cd.c            */

void cd(char **av, int nb_arg, t_envp *envp, char *user);

/*      all_arg_b.c     */

char **all_arg_b(int c, int d, char **result);

/*      bin.c       */

void all_binaries_cases(t_envp *envp, char *cmd, char **env, char **av);
char *verify_bin(char **res, char *cmd, t_envp *envp);
char **bin_find(char **env);
char *my_str_find(char **env);
int detect_bin(char *str);

/*          bin_b.c     */

char *my_str_bin(char *src);
void not_found_case(char *cmd, t_envp *envp);

/*      semi_colons.c       */
void semi_colons_cases(t_envp *envp);

/*      pipe       */
int pipe_case(t_envp *envp, char **av);
int detect_pipe(t_envp *envp, char **av);
int take_argv_pipe(t_envp *envp, char **av);

/*      get_pwd.c       */
char *get_pwd(char **env, bool old);
int check_doub_lef(char **av);

char *removing_spaces(char *str);
char *removing_spaces_middle(char *str);
char **str_to_tab(char *str, char divisor);
char **malloc_res(char **res, int nb_arg, int lg);

char *take_off_space(char *argv);
void my_engine(char **pro, int pfd[2], int pid);
int check_fd_pid(int pfd[2], int pid);
void lunch_binary_pipe(t_envp *envp, char **pro);
int get_nb_args(char **tmp);

/*      signal_handling     */
void signal_handling(int status,  t_envp *envp);

/*      and_or_cases.c      */
int and_handling(t_envp *envp);
void engine_or_and(char **tmp, int *inst, t_envp *envp);
/*      >    >> symbols     */
int gest_redirections_right(char **av, t_envp *envp);
char **str_to_tab_redir(char *str, char divisor);
char **fill_res_redir(char **res, char *str, char divisor);
void redirections_right(char **av, t_envp *envp);
void my_redirections_right(char **av, t_envp *envp);
int detect_rafter(char **av, t_envp *envp);
void launch_redir(t_envp *envp, char **pro);
void my_which(char **av, t_envp *envp);
/*      doub_red_left.c     */
char **double_red_lef(char **av, int *nb_arg, t_envp *envp);
bool are_redit(char *str);
/*      env_handling    */
void env_handling(char **av, t_envp *envp, int nb_arg);
void minishell_b(char **result, t_envp *envp, int nb_arg);
/* alias */
void my_puterror();
int my_where(char **av, t_envp *envp);
int my_alias(char **av, t_envp *envp);
int find_alias(char **av, t_envp *envp, int redir);
void open_alias(void);
bool verify_cmd(char *cmd);
int my_repeat(char **av, t_envp *envp);
int my_repeat_create_tab(char **av, char **tab, int nb_arg);
char **my_repeat_tab(char **av);
int exec_repeat(char **av, t_envp *envp);
int check_nb_repeat(char **av);
void display_env(char *cmd, t_envp *envp);

#endif