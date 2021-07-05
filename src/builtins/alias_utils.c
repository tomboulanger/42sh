/*
** EPITECH PROJECT, 2021
** alias
** File description:
** utils
*/

#include "../../include/my.h"

int find_one(char *word, char *buf, t_envp *envp)
{
    char **tmp = str_to_tab(buf, '~');
    char *cmd = NULL;
    char **argv;

    for (int i = 0; tmp[i] != NULL; i += 1) {
        if (str_cmp(word, tmp[i]) == 0) {
            cmd = my_strdup(tmp[i+1]);
            argv = str_to_tab(cmd, ' ');
            launch_redir(envp, argv);
            return (1);
        }
    }
    return (0);
}

int putchar_one(char *word, char *buf)
{
    char **tmp = str_to_tab(buf, '~');
    char *cmd = NULL;

    for (int i = 0; tmp[i] != NULL; i += 1) {
        if (str_cmp(word, tmp[i]) == 0) {
            cmd = my_strdup(tmp[i+1]);
            printf("%s\n", cmd);
            return (1);
        }
    }
    return (0);
}

int where_alias(char *word, char *buf)
{
    char **tmp = str_to_tab(buf, '~');
    char *cmd = NULL;

    for (int i = 0; tmp[i] != NULL; i += 1) {
        if (str_cmp(word, tmp[i]) == 0) {
            cmd = my_strdup(tmp[i+1]);
            printf("%s is aliased to %s\n", tmp[i], cmd);
            return (1);
        }
    }
    return (0);
}

int wich_one(char **av, t_envp *envp, int redir, char *buf)
{
    if (redir == 0) {
        if (find_one(av[0], buf, envp) == 1)
            return (1);
    }
    if (redir == 1)
        putchar_one(av[1], buf);
    if (redir == 2) {
        where_alias(av[1], buf);
    }
    return (0);
}

int find_alias(char **av, t_envp *envp, int redir)
{
    struct stat fp;
    int fd;
    int ret;
    char *buf;

    fd = open(".alias", O_RDONLY);
    if (fd == -1) {
        return (0);
    }
    stat(".alias", &fp);
    buf = malloc(sizeof(char *) * (fp.st_size));
    ret = read(fd, buf, fp.st_size);
    if (ret == 0)
        my_puterror(av, envp, redir, buf);
    buf[ret] = '\0';
    close(fd);
    return (wich_one(av, envp, redir, buf));
}