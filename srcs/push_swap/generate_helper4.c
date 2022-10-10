/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:49:48 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 15:00:27 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **a, t_stack **b, t_data data, int chunkbig)
{
	if ((*a)->sorted == data.smallest)
	{
		if (*b && (*b)->chunk == chunkbig)
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else
		{
			ra_rb(a);
			ft_printf("ra\n");
		}
	}
}

void	push_b_chunksv2(t_stack **a, t_stack **b, int chunkbig, t_data data)
{
	while (check_in_a(*a, data.smallest, data.biggest))
	{
		if ((*a)->sorted != data.smallest && (*a)->sorted != data.biggest)
		{
			pa_pb(a, b);
			ft_printf("pb\n");
		}
		else if (*b && (*b)->chunk == chunkbig)
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else
		{
			ra_rb(a);
			ft_printf("ra\n");
		}
	}
	rotate_a(a, b, data, chunkbig);
}

int	count_dist(t_stack *b, int smallest)
{
	int	count;

	count = 0;
	while (b && b->sorted != smallest)
	{
		count++;
		b = b->next;
	}
	return (count);
}

int	count_dist_rev(t_stack *b, int smallest)
{
	int	count;

	while (b && b->sorted != smallest)
	{
		b = b->next;
	}
	count = 0;
	while (b)
	{
		count++;
		b = b->next;
	}
	return (count);
}

int	calculate_dist(int count, int countrev)
{
	if (count < countrev)
	{
		return (count);
	}
	else
	{
		return (countrev);
	}
}
