/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:05:21 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 14:48:59 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*t_node;

	t_node = malloc(sizeof(t_node));
	if (t_node == NULL)
		return (NULL);
	t_node->value = value;
	t_node->rank = 0;
	t_node->next = NULL;
	return (t_node);
}
