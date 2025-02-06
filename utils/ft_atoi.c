/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:26:44 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 15:16:15 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(char *str, int i, char **split, t_node **stack)
{
	long	var[2];

	var[0] = 0;
	var[1] = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			var[1] = -1;
		i++;
	}
	if (!str[i])
		handle_error(stack, split);
	while (str[i])
	{
		var[0] = var[0] * 10 + (str[i] - '0');
		if ((var[0] * var[1]) > INT_MAX || (var[0] * var[1]) < INT_MIN
			|| (str[i] < '0' || str[i] > '9'))
			handle_error(stack, split);
		i++;
	}
	if (str[i])
		handle_error(stack, split);
	return (var[0] * var[1]);
}
