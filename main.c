/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:51 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 14:52:29 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_node **a, char **dc, int i)
{
	int		j;
	long	nbr;
	char	**str;

	i = 1;
	while (dc[i])
	{
		str = ft_split(dc[i], ' ', 0, 0);
		if (!str)
			handle_error(a, str);
		j = 0;
		while (str[j])
		{
			nbr = ft_atoi(str[j], 0, 0, str, a);
			if (dup_checker(*a, (int)nbr))
				handle_error(a, str);
			(ft_lstadd_back(a, ft_lstnew((int)nbr)));
			j++;
		}
		if (j == 0)
			handle_error(a, str);
		free_the_split_v2(str);
		i++;
	}
}

int	main(int ac, char *dc[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && dc[1][0] == '\0')
		(write(2, "Error\n", 6), exit(1));
	make_stack(&a, dc, 0);
	if (not_sorted(&a))
	{
		optimize(&a, &b, 0, 0);
		sorting(&a, &b);
	}
	ft_lstclear(&a);
}
