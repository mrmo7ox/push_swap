/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:06:26 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/19 12:21:53 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_lstadd_back_bonus(t_node **stack, t_node *new)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	while (tmp)
	{
		if (tmp->value > new->value)
			tmp->rank++;
		else
			new->rank++;
		tmp = tmp->next;
	}
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast_bonus(*stack);
	last->next = new;
}
