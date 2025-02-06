/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:25 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/19 12:21:52 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra_bonus(t_node **a, int print)
{
	t_node	*first;
	t_node	*tmp;

	if (ft_lstsize_bonus(*a) < 2)
		return ;
	first = *a;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	*a = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb_bonus(t_node **b, int print)
{
	t_node	*first;
	t_node	*tmp;

	if (ft_lstsize_bonus(*b) < 2)
		return ;
	first = *b;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = first;
	*b = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr_bonus(t_node **a, t_node **b, int print)
{
	rra_bonus(a, 0);
	rrb_bonus(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
