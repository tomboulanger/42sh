/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

int check_redir_left(t_envp *envp)
{
    for (int i = 0; envp->argv[i] != '\0'; i += 1) {
        if (envp->argv[i] == '<' && envp->argv[i+1] != '<'
        && envp->argv[i-1] != '<')
            return (1);
    }
    return (0);
}

char *open_dir_left(char *str)
{
    struct stat fp;
    int fd;
    int ret;
    char *buf;

    fd = open(str, O_RDONLY);
    if (fd == -1) {
        return (NULL);
    }
    stat(str, &fp);
    buf = malloc(sizeof(char *) * (fp.st_size));
    ret = read(fd, buf, fp.st_size);
    if (ret == 0) {
        printf("error");
        exit (84);
    }
    buf[ret] = '\0';
    close(fd);
    return (buf);
}

char **take_av(char **av, int z)
{
    char **res = NULL;
    int i = 0;

    res = malloc(sizeof(char *) * z);
    for (int b = 0; av[b] != NULL; b += 1) {
        if (av[b][0] == '<' && av[b][1] == '\0')
            b += 1;
        res[i] = my_strdup(av[b]);
        i += 1;
    }
    res[i] = NULL;
    return (res);
}

void my_redir_left(char **av, t_envp *envp)
{
    char **res = NULL;
    int z = 0;

    for (int i = 0; av[i] != NULL; i += 1) {
        z = i;
    }
    res = take_av(av, z);
    all_binaries_cases(envp, res[0], envp->env, res);
}