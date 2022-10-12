/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_helper3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:56 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/12 12:05:48 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_chunkData	init_chunk(t_stack *a, int chunks)
{
	t_chunkData	chunk;

	chunk.size = count_stack(a);
	chunk.chunk_size = chunk.size / chunks;
	chunk.chunk = 1;
	return (chunk);
}

static void	fill_a(t_stack *a, t_chunkData chunk)
{
	chunk.chunk--;
	while (a)
	{
		if (a->chunk == 0)
			a->chunk = chunk.chunk;
		a = a->next;
	}
}

void	assign_chunks(t_stack *a, int chunks)
{
	t_index		index;
	t_chunkData	chunk;
	t_stack		*temp;

	chunk = init_chunk(a, chunks);
	index.index = 0;
	temp = a;
	while (index.index < chunk.size && chunk.chunk <= chunks && temp)
	{
		index.counter = 0;
		while (index.counter < chunk.chunk_size)
		{
			if (temp->sorted == index.index)
			{
				temp->chunk = chunk.chunk;
				index.counter++;
				temp = a;
				index.index++;
			}
			else
				temp = temp->next;
		}
		chunk.chunk++;
	}
	fill_a(a, chunk);
}

void	push_b_chunks(t_stack **a, t_stack **b, int chunksmall, int chunkbig)
{
	while (check_chunk_in_stack(*a, chunksmall, chunkbig))
	{
		if ((*a)->chunk == chunksmall || (*a)->chunk == chunkbig)
		{
			pa_pb(a, b);
			ft_printf("pb\n");
		}
		else if (*b && (*b)->next && (*b)->chunk == chunkbig)
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

int	check_in_a(t_stack *a, int smallest, int biggest)
{
	while (a)
	{
		if (a->sorted != smallest && a->sorted != biggest)
			return (1);
		a = a->next;
	}
	return (0);
}
