/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:34 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/19 12:21:52 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa_bonus(t_node **a, int print)
{
	t_node	*a1;
	t_node	*tmp;

	if (ft_lstsize_bonus(*a) < 2)
		return ;
	a1 = *a;
	tmp = (*a)->next;
	a1->next = tmp->next;
	tmp->next = a1;
	*a = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb_bonus(t_node **b, int print)
{
	t_node	*b1;
	t_node	*tmp;

	if (ft_lstsize_bonus(*b) < 2)
		return ;
	b1 = *b;
	tmp = (*b)->next;
	b1->next = tmp->next;
	tmp->next = b1;
	*b = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss_bonus(t_node **a, t_node **b, int print)
{
	sa_bonus(a, 0);
	sb_bonus(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
