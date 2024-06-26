/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 19:58:54 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	failure(t_shell *data)
{
	data->exit_code = EXIT_FAILURE;
}

void	ft_parser(t_shell *data)
{
	if (ft_validate_input(data->input))
		return (failure(data));
	data->com = ft_div_com(data->input, &data->com_len);
	if (!data->com)
	{
		perror("malloc");
		return (failure(data));
	}
	if (ft_check_redirection(data))
		return (failure(data));
	if (ft_expansor(data))
		return (failure(data));
	if (ft_div_argv(data))
		return (failure(data));
	if (data->com_len > 1)
		ft_pipex(data);
	else
		ft_exec_one(data);
}
