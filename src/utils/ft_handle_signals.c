/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:21:51 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/13 18:26:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_handle_signals(void)
{
	if (signal(SIGINT, ft_signal) == SIG_ERR)
		perror("signal");
}
