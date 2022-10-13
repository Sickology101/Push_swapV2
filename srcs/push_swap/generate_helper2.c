/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:20:41 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/13 12:30:10 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_3(t_stack **a)
{
	while (!check_sorted_stack(*a))
	{
		if ((*a)->sorted > (*a)->next->sorted)
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
}

void	generate_5_help(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->sorted == 4 && (*a)->next->next->next->sorted == 3)
	{
		ra_rb(a);
		ft_printf("ra\n");
		ra_rb(a);
		ft_printf("ra\n");
	}
	else if ((*a)->sorted == 4 || (*a)->sorted == 3)
	{
		pa_pb(a, b);
		ft_printf("pb\n");
	}
	else if ((*a)->next->sorted == 4 || (*a)->next->sorted == 3)
	{
		ra_rb(a);
		ft_printf("ra\n");
	}
	else
	{
		rra_rrb(a);
		ft_printf("rra\n");
	}
}

void	generate_5(t_stack **a, t_stack **b)
{
	while (count_stack(*a) > 3)
	{
		generate_5_help(a, b);
	}
	generate_3(a);
	if ((*b)->sorted > (*b)->next->sorted)
	{
		ra_rb(b);
		ft_printf("rb\n");
	}
	while ((*b))
	{
		pa_pb(b, a);
		ft_printf("pa\n");
		ra_rb(a);
		ft_printf("ra\n");
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
