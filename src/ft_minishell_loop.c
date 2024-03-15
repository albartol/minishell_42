/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/15 17:10:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_minishell_loop(t_shell *data)
{
	ft_handle_signals();
	while (1)
	{
		ft_get_input(data);
		if (!data->command)
			break ;
		if (*data->command)
			ft_parser(data);
		ft_exec_command(data);
		add_history(data->command);
		free(data->command);
		free(data->prompt);
	}
	rl_clear_history();
	printf("Exiting minishell\n");
}
