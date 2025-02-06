/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:37 by moel-oua          #+#    #+#             */
/*   Updated: 2025/01/19 12:22:54 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	dup_checker_bonus(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_lstclear_bonus(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = (NULL);
}

char	**free_the_split_v2_bonus(char **res)
{
	int	words;

	words = 0;
	if (!res)
		return (NULL);
	while (res[words])
	{
		free (res[words]);
		words++;
	}
	free(res);
	return (NULL);
}

void	handle_error_bonus(t_node **stack, char **res)
{
	ft_lstclear_bonus(stack);
	free_the_split_v2_bonus(res);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
