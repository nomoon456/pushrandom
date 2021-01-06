/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:20:27 by nomoon            #+#    #+#             */
/*   Updated: 2020/12/29 00:36:10 by nomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int     count_argv(char **argv)
{
    int i;

    i = -1;
    while (argv[++i])
        ;
    return (i);
}

int		builtin_exec(char *path, t_command *cmd, char **argv, t_env *env)
{
    if (!ft_strcmp(path, "pwd") && count_argv(argv) == 1)
        ft_pwd();
    else if (!ft_strcmp(path, "pwd") && count_argv(argv) > 1)
        ft_putstr_fd("pwd: too many arguments\n", 1);
    if (!ft_strcmp(path, "env"))
        print_env(env, 0);
    if (!ft_strcmp(path, "export"))
        export_check(env, argv);
    if (!ft_strcmp(path, "unset"))
        unset(env, argv);
    if (!ft_strcmp(path, "echo"))
        ft_echo(env, argv);
    // if (!ft_strcmp(path, "cd"))
    //     ft_echo(argv, env);
    return (1);
}