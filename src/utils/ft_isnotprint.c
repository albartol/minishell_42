/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 14:33:08 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnotprint(const char c)
{
	if (c == 127 || c <= 32)
		return (1);
	return (0);
}
