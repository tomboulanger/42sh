/*
** EPITECH PROJECT, 2021
** where
** File description:
** findin
*/

#include "../../include/my.h"

char **malloc_tab(char **src)
{
    char **res = NULL;
    int i = 0;

    for (; src[i] != NULL; i += 1);
    res = malloc(sizeof(char *) * (i + 2));
    return (res);
}

int get_i(char *cmd)
{
    int i = 0;
    for (int c = 0; cmd[c] != '\0'; c += 1) {
        if (cmd[c] == '/')
            i = 1;
    }
    return (i);
}

char **fill_res_where(char **resultat, char *cmd, char **res)
{
    int z = 0;
    char *temp;

    for (int j = 0; res[j] != NULL; j += 1) {
        temp = my_strcat((my_strcat(res[j], "/")), cmd);
        if (access(temp, F_OK) == 0) {
            resultat[z] = my_strdup(temp);
            z += 1;
        }
    }
    if (resultat[0] != NULL)
        resultat[z] = NULL;
    return (resultat);
}

char **verify_bin_tab(char **res, char *cmd)
{
    int i = get_i(cmd);
    char **resultat = malloc_tab(res);

    if (i == 1) {
        if (access(cmd, F_OK) == 0) {
            resultat[0] = my_strdup(cmd);
            return (resultat);
        }
        return (NULL);
    }
    resultat = fill_res_where(resultat, cmd, res);
    if (resultat[0] != NULL)
        return (resultat);
    return (NULL);
}

void display_env(char *cmd, t_envp *envp)
{
    char **res = verify_bin_tab(bin_find(envp->env), cmd);

    if (res == NULL)
        return;
    for (int i = 0; res[i] != NULL; i += 1) {
        printf("%s\n", res[i]);
        free (res[i]);
    }
}
