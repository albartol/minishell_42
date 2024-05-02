/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:45:54 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/27 15:41:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_len(const char *value)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (value[i] == BLANK)
		i++;
	while (value[i])
	{
		if (value[i] != BLANK)
			len++;
		else if (value[i] == BLANK && value[i + 1] && value[i + 1] != BLANK)
			len++;
		i++;
	}
	return (len);
}

static char	*rm_blanks(const char *input, const char *value, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (value[i] == BLANK)
		i++;
	while (value[i])
	{
		if (value[i] != BLANK)
			result[j++] = input[i];
		else if (value[i] == BLANK && value[i + 1] && value[i + 1] != BLANK)
			result[j++] = input[i];
		i++;
	}
	return (result);
}

char	*trim_input(t_input *input)
{
	char	*result;

	result = (char *)ft_calloc(get_len(input->value) + 1, sizeof(char));
	if (!result)
		return (NULL);
	rm_blanks(input->str, input->value, result);
	printf("after trim: [%s]\n", result);
	return (result);
}
