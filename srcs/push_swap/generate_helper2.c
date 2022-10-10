/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:20:41 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 14:30:37 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_3(t_stack **a)
{
	if ((*a)->next->sorted < (*a)->next->next->sorted)
	{
		sa_sb(a);
		ft_printf("sa\n");
	}
	else
	{
		rra_rrb(a);
		ft_printf("rra\n");
	}
}

void	empty_b(t_stack **b, t_stack **a)
{
	while (*b)
	{
		pa_pb(b, a);
		ft_printf("pa\n");
	}
}

void	generate_5(t_stack **a, t_stack **b, int median)
{
	if (check_sorted_inv(*a))
	{
		generate_inv(a, b);
	}
	else
	{
		while (count_stack(*a) > 3)
		{
			push_b(a, b, median);
		}
		while (!check_sorted_stack(*a))
		{
			generate_3(a);
		}
		if (!check_sorted_inv(*b))
		{
			empty_b(b, a);
		}
		else
		{
			sa_sb(b);
			ft_printf("sb\n");
			empty_b(b, a);
		}
	}
}

int	calculate_chunks(t_stack *a)
{
	int	size;

	size = count_stack(a);
	if (size <= 20)
		return (4);
	else if (size <= 50)
		return (8);
	else if (size <= 100)
		return (16);
	else
		return (32);
}

int	check_chunk_in_stack(t_stack *a, int chunksmall, int chunkbig)
{
	while (a)
	{
		if (a->chunk == chunksmall || a->chunk == chunkbig)
			return (1);
		a = a->next;
	}
	return (0);
}
