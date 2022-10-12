/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:42:46 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/12 12:08:03 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_av2(t_stack **a, t_stack **b, int breakpoint)
{
	while ((*b)->sorted != breakpoint)
	{
		ra_rb(b);
		ft_printf("rb\n");
	}
	pa_pb(b, a);
	ft_printf("pa\n");
}

void	push_av2_rev(t_stack **a, t_stack **b, int breakpoint)
{
	while ((*b)->sorted != breakpoint)
	{
		rra_rrb(b);
		ft_printf("rrb\n");
	}
	pa_pb(b, a);
	ft_printf("pa\n");
}

void	rotate_a2(t_stack **a)
{
	ra_rb(a);
	ft_printf("ra\n");
}

t_dist	init_dist(t_stack **b, t_data *data)
{
	t_dist	dist;

	dist.countsmall = count_dist(*b, data->smallest);
	dist.countsmallrev = count_dist_rev(*b, data->smallest);
	dist.countbig = count_dist(*b, data->biggest);
	dist.countbigrev = count_dist_rev(*b, data->biggest);
	dist.smalldist = calculate_dist(dist.countsmall, dist.countsmallrev);
	dist.bigdist = calculate_dist(dist.countbig, dist.countbigrev);
	return (dist);
}

void	empty_b(t_stack **b, t_stack **a)
{
	while (*b)
	{
		pa_pb(b, a);
		ft_printf("pa\n");
	}
}
