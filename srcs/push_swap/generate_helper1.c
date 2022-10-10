/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:31 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 14:21:38 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_inv(t_stack **a, t_stack **b)
{
	while ((*a)->next->next != NULL)
	{
		pa_pb(a, b);
		ft_printf("pb\n");
	}
	sa_sb(a);
	ft_printf("sa\n");
	while ((*b))
	{
		pa_pb(b, a);
		ft_printf("pb\n");
		ra_rb(a);
		ft_printf("ra\n");
	}
}

void	push_b(t_stack **a, t_stack **b, int median)
{
	if ((*a)->sorted <= median)
	{
		pa_pb(a, b);
		ft_printf("pb\n");
	}
	else
	{
		ra_rb(a);
		ft_printf("ra\n");
	}
}

static void	generate_4help(t_stack **a, t_stack **b)
{
	if ((*a)->next && (*a)->sorted > (*a)->next->sorted)
	{
		if ((*b) && (*b)->next && (*b)->sorted > (*b)->next->sorted)
		{
			ss(a, b);
			ft_printf("ss\n");
		}
		else
		{
			sa_sb(a);
			ft_printf("sa\n");
		}
	}
	else
	{
		sa_sb(b);
		ft_printf("sb\n");
	}
}

static void	generate4_help2(t_stack **a, t_stack **b)
{
	pa_pb(b, a);
	ft_printf("pa\n");
	ra_rb(a);
	ft_printf("ra\n");
}

void	generate_4(t_stack **a, t_stack **b)
{
	int	smallest;

	smallest = 0;
	if (check_sorted_inv(*a))
	{
		generate_inv(a, b);
	}
	else
	{
		while ((*a)->sorted == smallest)
		{
			ra_rb(a);
			ft_printf("ra\n");
			smallest++;
		}
		while ((*a)->sorted != smallest)
		{
			pa_pb(a, b);
			ft_printf("pb\n");
		}
		generate_4help(a, b);
		while ((*b))
			generate4_help2(a, b);
	}
}
