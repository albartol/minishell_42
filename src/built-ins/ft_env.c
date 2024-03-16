/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:16 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 15:44:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_print_node(void *node)
{
	char	*env;

	env = (char *)node;
	printf("%s\n", env);
}

void	ft_env(t_shell *data)
{
	if (data->argv[1])
		printf("env: too many arguments\n");
	else
		ft_lstiter(data->env, ft_print_node);
}
