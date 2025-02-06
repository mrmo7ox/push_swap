/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:49 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:30 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_max(t_node *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}

t_node	*get_min(t_node *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value < tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}

int	not_sorted(t_node **stack)
{
	t_node	*current;

	current = (*stack);
	while (current)
	{
		if (current->next != NULL)
		{
			if (current->value > current->next->value)
				return (1);
		}
		current = current->next;
	}
	return (0);
}

void	set_position(t_node *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

int	max_t_node_positon(t_node *stack)
{
	t_node	*tmp;
	t_node	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->index);
}
