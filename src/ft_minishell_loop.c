/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 00:56:36 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// static void	ft_signal(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_replace_line("", 1);
// 		rl_redisplay();
// 	}
// }

void	ft_minishell_loop(t_shell *data)
{
	// if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	// 	perror("signal");
	ft_save_config(data);
	while (1)
	{
		// if (signal(SIGINT, ft_signal) == SIG_ERR)
		// 	perror("signal");
		ft_handle_signals();
		ft_get_input(data);
		// if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		// 	perror("signal");
		if (!data->input)
			break ;
		ft_parser(data);
		// rl_replace_line("", 1);
		// if (data->pipes[1])
		// 	ft_pipex(data);
		// else
		// 	ft_exec_one(data);
		// free_input(data);
	}
	// rl_clear_history();
	// printf("Exiting minishell\n");
}
