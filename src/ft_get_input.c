/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:12 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*	Function gets the input for user using the readline function.
	The function will asking for more inputs with a \n
	if the input its not okay */
static char	*get_input(t_shell *data)
{
	char	*new_input;

	new_input = readline("> ");
	if (!new_input)
	{
		free_input(data);
		data->input = (char *)ft_calloc(1, sizeof(char));
		if (!data->input)
			ft_exit_program(data, "malloc");
		ft_putstr_fd("unexpected EOF while looking for \"\'\n", STDERR);
		return (NULL);
	}
	return (new_input);
}

static void	get_new_input(t_shell *data)
{
	char	*aux;
	char	*new_input;

	while (check_quotes(data->input))
	{
		aux = data->input;
		data->input = ft_charjoin(data->input, '\n');
		free(aux);
		if (!data->input)
			ft_exit_program(data, "malloc");
		new_input = get_input(data);
		if (!new_input)
			return ;
		aux = data->input;
		data->input = ft_strjoin(data->input, new_input);
		free(aux);
		free(new_input);
		if (!data->input)
			ft_exit_program(data, "malloc");
	}
}

void	ft_get_input(t_shell *data)
{
	ft_update_prompt(data);
	data->input = readline(data->prompt);
	free(data->prompt);
	if (!data->input)
		return ;
	if (check_quotes(data->input))
		get_new_input(data);
}
