/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:32 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/14 18:05:33 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*biggest_t_node;

	biggest_t_node = get_max(*a);
	if (*a == biggest_t_node)
		ra(a, 1);
	else if ((*a)->next == biggest_t_node)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min_t_node;

	min_t_node = get_min(*a);
	if (not_sorted(a))
	{
		while (1)
		{
			if (min_t_node->value != (*a)->value)
				rra(a, 1);
			else
				break ;
		}
		pb(b, a, 1);
		sort_three(a);
		pa(a, b, 1);
		return ;
	}
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_t_node;

	if (not_sorted(a))
	{
		min_t_node = get_min(*a);
		while (1)
		{
			if ((*a)->next == min_t_node)
				ra(a, 1);
			else if (min_t_node->value != (*a)->value)
				rra(a, 1);
			else
				break ;
		}
		pb(b, a, 1);
		sort_four(a, b);
		pa(a, b, 1);
		return ;
	}
}

void	handle_five(t_node **a, t_node **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a, 1);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	ft_lstclear(a);
	return ;
}
