/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:28:15 by albartol          #+#    #+#             */
/*   Updated: 2023/09/12 16:39:50 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(const int i)
{
	if ((i > 64 && i < 91) || (i > 96 && i < 123))
		return (1);
	return (0);
}
