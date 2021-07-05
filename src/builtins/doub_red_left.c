/*
** EPITECH PROJECT, 2021
** double
** File description:
** regirec
*/

#include "../../include/my.h"

char *get_str(void)
{
    long unsigned int size = 2;
    char *string = NULL;

    if (getline(&string, &size, stdin) == -1)
        exit (1);
    string[strlen(string) - 1] = '\0';
    return (string);
}

char *find_end_work(char **av, t_envp *envp)
{
    char *str = NULL;

    for (int i = 0; av[i] != NULL; i += 1) {
        if (av[i][0] == '<' && av[i][1] == '<' &&
        av[i + 1] != NULL && strlen(av[i]) == 2)
            return (str = my_strdup(av[i + 1]));
        if (av[i][0] == '<' && av[i][1] == '<' && strlen(av[i]) != 2) {
            str = my_strdup(av[i]);
            str += 2;
            return (str);
        }
    }
    envp->c_tinue = 1;
    envp->return_value = 1;
    fprintf(stderr, "Missing name for redirect.\n");
    return ("\0");
}

char *replace_char(char *str, int i)
{
    int c = i + 3;

    for (; str[c] != '\0' && (str[c] == ' ' || str[c] == '<') ; c += 1) {
        str[c] = ' ';
    }
    for (; str[c] != '\0' && str[c] != ' '; c += 1)
        str[c] = ' ';
    str[c] = '\0';
    str[i] = '.';
    str[i + 1] = 'd';
    str[i + 2] = 'r';
    return (str);
}

void replace_string(t_envp *envp)
{
    for (int i = 0; envp->argv[i] != '\0'; i += 1) {
        if (envp->argv[i] == '<' && envp->argv[i + 1] == '<')
            replace_char(envp->argv, i);
    }
}

char **double_red_lef(char **av, int *nb_arg, t_envp *envp)
{
    char *str = NULL;
    int fd = 0;

    if (find_end_work(av, envp)[0] == '\0')
        return (av);
    if (are_redit(envp->argv) == false)
        printf("? ");
    fd = open(".dr", O_CREAT | O_RDWR | O_TRUNC, 0777);
    while ((strcmp(find_end_work(av, envp), str = get_str()) ) != 0) {
        write(fd, strcat(str, "\n"), strlen(str) + 1);
        free (str);
        if (are_redit(envp->argv) == false)
            printf("? ");
    }
    free_result(av, (*nb_arg));
    replace_string(envp);
    av = str_to_tab(envp->argv, ' ');
    (*nb_arg) = get_nb_args(av);
    close (fd);
    return (av);
}