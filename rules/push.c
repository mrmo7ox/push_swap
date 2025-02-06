/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:22 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/18 16:05:25 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **a, t_node **b, int print)
{
	t_node	*first_a;
	t_node	*first_b;

	if (*b == NULL)
		return ;
	first_a = *a;
	first_b = *b;
	*b = first_b->next;
	first_b->next = first_a;
	*a = first_b;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, int print)
{
	t_node	*first;
	t_node	*first_b;

	if (*a == NULL)
		return ;
	first = *a;
	first_b = *b;
	*a = first->next;
	first->next = first_b;
	*b = first;
	if (print)
		write(1, "pb\n", 3);
}
