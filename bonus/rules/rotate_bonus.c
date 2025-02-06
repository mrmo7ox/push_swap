/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:27 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/19 12:22:05 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra_bonus(t_node **a, int print)
{
	t_node	*first;
	t_node	*last;

	if (ft_lstsize_bonus(*a) < 2)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

void	rb_bonus(t_node **b, int print)
{
	t_node	*b1;
	t_node	*b2;

	if (ft_lstsize_bonus(*b) < 2)
		return ;
	b1 = *b;
	b2 = *b;
	while (b2->next)
		b2 = b2->next;
	*b = b1->next;
	b1->next = NULL;
	b2->next = b1;
	if (print)
		write(1, "rb\n", 3);
}

void	rr_bonus(t_node **a, t_node **b, int print)
{
	ra_bonus(a, 0);
	rb_bonus(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
