/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:16 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:37:42 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_print_node(void *node)
{
	char	*env;

	env = (char *)node;
	ft_putstr_fd(env, STDOUT);
	ft_putchar_fd('\n', STDOUT);
}

void	ft_env(char **argv, t_shell *data)
{
	if (argv[1])
	{
		ft_putstr_fd("env: too many arguments\n", STDERR);
		ft_set_exit(data, EXIT_FAILURE);
	}
	else
	{
		ft_lstiter(data->env, ft_print_node);
		data->exit_code = EXIT_SUCCESS;
	}
}
