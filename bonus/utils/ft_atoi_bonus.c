/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:26:44 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 15:02:03 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

long	ft_atoi_bonus(char *str, int i, int sign, char **split, t_node **stack)
{
	long	res;

	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		handle_error_bonus(stack, split);
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN
			|| (str[i] < '0' || str[i] > '9'))
			handle_error_bonus(stack, split);
		i++;
	}
	if (str[i])
		handle_error_bonus(stack, split);
	return (res * sign);
}
