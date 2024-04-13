/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:43:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/13 19:22:19 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_input(t_shell *data)
{
	int	i;

	i = 0;
	free(data->input);
	while (data->com && data->com[i])
	{
		free(data->com[i].com);
		ft_free_array(data->com->argv);
		free(data->com[i].input.com);
		free(data->com[i].input.file_name);
		free(data->com[i].output.com);
		free(data->com[i].output.file_name);
	}
	free(data->com);
	data->input = 0;
	data->com = 0;
}
