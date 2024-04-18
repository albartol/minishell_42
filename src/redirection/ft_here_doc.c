/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:56 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 18:16:25 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_input(const char *new_input, const char *limit)
{
	size_t	input_len;

	input_len = ft_strlen(new_input);
	if (input_len != ft_strlen(limit))
		return (0);
	if (ft_strncmp(new_input, limit, input_len))
		return (0);
	return (1);
}

static char	*get_limit(const char *com)
{
	char	*limit;
	int		i;

	i = 0;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			break ;
		i++;
	}
	limit = ft_substr(com, 0, i);
	if (!limit)
	{
		perror("malloc");
		return (NULL);
	}
	return (limit);
}

static int	fill_here_doc(t_redir *red, const char *limit, int fd)
{
	char	*new_input;
	char	*temp_str;

	while (1)
	{
		new_input = readline("> ");
		if (!new_input || check_input(new_input, limit))
			break ;
		temp_str = ft_charjoin(new_input, '\n');
		free(new_input);
		if (!temp_str)
		{
			close(fd);
			unlink(red->file_name);
			perror("malloc");
			return (EXIT_FAILURE);
		}
		ft_putstr_fd(temp_str, fd);
		free(temp_str);
	}
	free(new_input);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_here_doc(t_redir *red, const char *com)
{
	char	*limit;
	int		fd;

	if (create_tmp_file_name(red))
		return (EXIT_FAILURE);
	fd = open(red->file_name, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	if (fd == -1)
		return (ft_exit_funct("open", EXIT_FAILURE));
	limit = get_limit(com);
	if (!limit)
	{
		close(fd);
		unlink(red->file_name);
		perror("malloc");
		return (EXIT_FAILURE);
	}
	return (fill_here_doc(red, limit, fd));
}