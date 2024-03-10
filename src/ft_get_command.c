/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/09 12:06:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_get_prompt(void)
{
	char	*prompt;
	char	*text;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		ft_print_error();
	text = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	prompt = ft_strjoin(text, DELIMITATOR);
	free(text);
	return (prompt);
}

char	*ft_get_command(void)
{
	char	*command;
	char	*input;
	char	*prompt;

	prompt = ft_get_prompt();
	input = readline(prompt);
	free(prompt);
	if (!input)
		return (NULL);
	command = ft_strtrim(input, NON_PRINT);
	free(input);
	if (*command)
		add_history(command);
	return (command);
}
