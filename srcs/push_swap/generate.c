/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:38:55 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/12 11:56:57 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// don't forget leaks on error exit

void	push_ahelp(t_stack **a, t_stack **b, t_data *data, t_dist dist)
{
	if (dist.countsmall < dist.countsmallrev)
	{
		push_av2(a, b, data->smallest);
		data->smallest = data->smallest + 1;
		rotate_a2(a);
	}
	else
	{
		push_av2_rev(a, b, data->smallest);
		data->smallest = data->smallest + 1;
		rotate_a2(a);
	}
}

void	push_a(t_stack **a, t_stack **b, t_data *data)
{
	t_dist	dist;

	dist = init_dist(b, data);
	if (dist.smalldist < dist.bigdist)
	{
		push_ahelp(a, b, data, dist);
	}
	else
	{
		if (dist.countbig < dist.countbigrev)
		{
			push_av2(a, b, data->biggest);
			data->biggest = data->biggest - 1;
		}
		else
		{
			push_av2_rev(a, b, data->biggest);
			data->biggest = data->biggest - 1;
		}
	}
}

void	generate_big(t_stack **a, t_stack **b)
{
	t_data		data;
	t_chunkData	chunk;

	chunk.chunk = calculate_chunks(*a);
	assign_chunks(*a, chunk.chunk);
	chunk.chunksmall = chunk.chunk / 2;
	chunk.chunkbig = chunk.chunksmall + 1;
	data.biggest = count_stack(*a) - 1;
	while (chunk.chunksmall != 1)
	{
		push_b_chunks(a, b, chunk.chunksmall, chunk.chunkbig);
		chunk.chunksmall--;
		chunk.chunkbig++;
	}
	data.smallest = 0;
	push_b_chunksv2(a, b, chunk.chunkbig, data);
	data.smallest++;
	data.biggest--;
	while (*b)
	{
		push_a(a, b, &data);
	}
	while ((*a)->sorted != 0)
		rotate_a2(a);
}

void	generate_help(t_stack **a, t_stack **b, int num)
{
	if (num == 2)
	{
		sa_sb(a);
		ft_printf("sa\n");
	}
	else if (num == 3)
		generate_3(a);
	else if (num == 4)
		generate_4(a, b);
	else if (num == 5)
		generate_5(a, b);
	else if (check_sorted_inv(*a))
		generate_inv(a, b);
	else
		generate_big(a, b);
}

void	generate(t_stack **a, t_stack **b)
{
	int	median;

	median = 0;
	sort(*a, &median);
	while (!check_sorted_stack(*a))
	{
		generate_help(a, b, median);
	}
}

/*ft_printf("Stack a: \n");
	print_stack(*a);
	ft_printf("\nStack b:\n");
	print_stack(*b);*/