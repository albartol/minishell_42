/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:54:54 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 21:06:27 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	count_len(const char *str)
{
	int		i;
	int		num_quotes;
	size_t	len;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	num_quotes = 0;
	while (str[i])
	{
		if (str[i] && quotes(str[i]))
		{
			num_quotes++;
			i++;
			while (str[i] && quotes(str[i]))
				i++;
			if (!str[i])
				break ;
		}
		i++;
	}
	return (len - (num_quotes * 2));
}

static void	fill_new_str(char *new_str, const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (quotes(str[i]))
		{
			i++;
			while (str[i] && quotes(str[i]))
				new_str[j++] = str[i++];
			if (!str[i])
				break ;
			i++;
		}
		else
			new_str[j++] = str[i++];
	}
}

char	*ft_trim_quotes(const char *str)
{
	size_t	len;
	char	*new_str;

	len = count_len(str);
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	fill_new_str(new_str, str);
	return (new_str);
}
