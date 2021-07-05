/*
** EPITECH PROJECT, 2021
** signal
** File description:
** handling
*/

#include "../../include/my.h"

void signal_handling(int status,  t_envp *envp)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            fprintf(stderr, "Segmentation fault\n");
            envp->return_value = 139;
        } else if (WTERMSIG(status) == SIGFPE) {
            fprintf(stderr, "Floating exception\n");
            envp->return_value = 136;
        }
    } else {
        envp->return_value = WEXITSTATUS(status);
    }
}