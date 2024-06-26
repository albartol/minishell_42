/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:58:05 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:09:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	quotes(const char c)
{
	static short	double_q;
	static short	simple_q;

	if (c == '\"' && !simple_q)
		double_q ^= 1;
	else if (c == '\'' && !double_q)
		simple_q ^= 1;
	return (double_q || simple_q);
}
