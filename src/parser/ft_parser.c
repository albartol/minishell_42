/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/15 15:41:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_parser(t_shell *data)
{
	if (ft_validate_input(data->input))
		return ;
	data->com = ft_div_com(data->input);
	if (!data->com)
	{
		perror("malloc");
		return ;
	}
	if (ft_expansor(data))
		return ;
	if (data->com_len > 1)
		ft_pipex(data);
	else
		ft_exec_one(data);
}

/* void	ft_parser(t_shell *data)
{
	if (ft_trim_input(data) == EXIT_FAILURE)
		return ;
	if (ft_val_input(data->input, '|', '&') 
		|| ft_val_input(data->input, '<', '>'))
		return ;
	data->com = ft_split_pipes(data->input);
	if (!data->com)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	if (ft_expansor(data) == EXIT_FAILURE)
		return ;
	if (data->com_len > 1)
		ft_pipex(data);
	else
		ft_exec_one(data);
} */
