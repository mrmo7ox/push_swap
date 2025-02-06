/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:32 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/06 15:17:58 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	make_stack_bonus(t_node **a, char **dc, int i)
{
	int		j;
	long	nbr;
	char	**str;

	i = 1;
	while (dc[i])
	{
		str = ft_split_bonus(dc[i], ' ', 0, 0);
		if (!str)
			handle_error_bonus(a, str);
		j = 0;
		while (str[j])
		{
			nbr = ft_atoi_bonus(str[j], 0, str, a);
			if (dup_checker_bonus(*a, (int)nbr))
				handle_error_bonus(a, str);
			(ft_lstadd_back_bonus(a, ft_lstnew_bonus((int)nbr, 0)));
			j++;
		}
		if (j == 0)
			(write(2, "Error\n", 6), exit(1));
		free_the_split_v2_bonus(str);
		i++;
	}
}

int	verify_bonus(char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "sa\n", 3)
		|| !ft_strncmp(str, "sb\n", 3)
		|| !ft_strncmp(str, "ss\n", 3))
		i = 1;
	else if (!ft_strncmp(str, "pa\n", 3)
		|| !ft_strncmp(str, "pb\n", 3))
		i = 1;
	else if (!ft_strncmp(str, "ra\n", 3)
		|| !ft_strncmp(str, "rb\n", 3)
		|| !ft_strncmp(str, "rr\n", 3))
		i = 1;
	else if (!ft_strncmp(str, "rra\n", 4)
		|| !ft_strncmp(str, "rrb\n", 4)
		|| !ft_strncmp(str, "rrr\n", 4))
		i = 1;
	return (i);
}

void	execute(char *str, t_node **a, t_node **b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa_bonus(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb_bonus(b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss_bonus(a, b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa_bonus(a, b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb_bonus(b, a, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra_bonus(a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb_bonus(b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr_bonus(a, b, 0);
	else if (!ft_strncmp(str, "rra\n", 3))
		rra_bonus(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 3))
		rrb_bonus(b, 0);
	else if (!ft_strncmp(str, "rrr\n", 3))
		rrr_bonus(a, b, 0);
}

void	while_loop(t_node **a, t_node **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		else if (!verify_bonus(str))
		{
			free(str);
			write(1, "Error\n", 6);
			ft_lstclear_bonus(a);
			ft_lstclear_bonus(b);
			exit(1);
		}
		else
			execute(str, a, b);
		free(str);
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
	make_stack_bonus(&a, dc, 0);
	while_loop(&a, &b);
	if (!not_sorted_bonus(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear_bonus(&a);
	ft_lstclear_bonus(&b);
}
