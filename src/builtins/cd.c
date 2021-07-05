/*
** EPITECH PROJECT, 2021
** cd
** File description:
** case
*/

#include "../../include/my.h"

void hyphen_minus_case(t_envp *envp)
{
    char *copy = my_strdup(envp->actual_dir);

    if (strcmp(envp->actual_dir, envp->pre_dir) != 0) {
        chdir(envp->pre_dir);
        envp->actual_dir = my_strdup(envp->pre_dir);
        envp->pre_dir = my_strdup(copy);
        envp->return_value = 0;
    } else {
        fprintf(stderr, ": No such file or directory.\n");
        envp->return_value = 1;
    }
}

char *get_last(char *str, t_envp *envp)
{
    char *res = my_strdup(str);
    int lg = my_strlen(res) - 1;

    for (int i = lg; i != 0; i -= 1) {
        if (res[i] == '/') {
            res[i] = '\0';
            return (res);
        }
        res[i] = '\0';
    }
    return (get_user(envp->env));
}

void pre_dir_changes(t_envp *envp, char *next)
{
    envp->cd_ = true;
    if (next[0] == '.' && next[1] == '.') {
        envp->pre_dir = my_strdup(envp->actual_dir);
        envp->actual_dir = get_last(envp->pre_dir, envp);
    } else {
        envp->pre_dir = my_strdup(envp->actual_dir);
        envp->actual_dir = my_strdup(next);
    }
}

void all_cd_cases(struct stat buf, char **av, t_envp *envp)
{
    if (S_ISDIR(buf.st_mode)) {
        envp->pre_dir = getcwd(NULL, 0);
        chdir(av[1]);
        envp->actual_dir = getcwd(NULL, 0);
    } else if (access(av[1], F_OK)) {
        fprintf(stderr, "%s", av[1]);
        fprintf(stderr, ": No such file or directory.\n");
        envp->return_value = 1;
    } else {
        fprintf(stderr, "%s", av[1]);
        fprintf(stderr, ": Not a directory.\n");
        envp->return_value = 1;
    }
}

void cd(char **av, int nb_arg, t_envp *envp, char *user)
{
    struct stat buf;

    stat(av[1], &buf);
    if (str_cmp(av[0], "cd") == 0 && nb_arg > 2)
        fprintf(stderr, "cd: Too many arguments.\n");
    if (str_cmp(av[0], "cd") == 0 && nb_arg == 2) {
        if (av[1][0] == '-' && av[1][1] == '\0') {
            hyphen_minus_case(envp);
            return;
        }
        all_cd_cases(buf, av, envp);
    }
    if (str_cmp(av[0], "cd") == 0 && nb_arg == 1) {
        envp->cd_ = true;
        envp->pre_dir = getcwd(NULL, 0);
        chdir (my_strcat("/home/", user));
        envp->actual_dir = getcwd(NULL, 0);
        envp->return_value = 0;
    }
}