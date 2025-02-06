/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:30 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 15:13:15 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	optimize(t_node **a, t_node **b, int chunk, int i)
{
	t_node	*tmp;
	int		size;

	size = ft_lstsize(*a);
	chunk = ft_sqrt(size);
	while (*a)
	{
		tmp = *a;
		if (tmp->rank <= i)
		{
			pb(b, a, 1);
			i++;
		}
		else if (tmp->rank <= i + chunk)
		{
			pb(b, a, 1);
			rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

void	sorting(t_node **a, t_node **b)
{
	int	t_node_position;

	while (ft_lstsize(*b))
	{
		set_position(*b);
		t_node_position = max_t_node_positon(*b);
		if (t_node_position < (ft_lstsize(*b) / 2))
		{
			while ((*b)->index != t_node_position)
				rb(b, 1);
		}
		else
		{
			while ((*b)->index != t_node_position)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}
