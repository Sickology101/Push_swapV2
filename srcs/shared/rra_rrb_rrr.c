/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:25:03 by marius            #+#    #+#             */
/*   Updated: 2022/10/13 09:57:11 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack1, t_stack **stack2)
{
	rra_rrb(stack1);
	rra_rrb(stack2);
}

void	rra_rrb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*loop;
	t_stack	*prev;

	temp = *stack;
	loop = *stack;
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	while (loop->next)
	{
		prev = loop;
		loop = loop->next;
	}
	prev->next = NULL;
	loop->next = temp;
	*stack = loop;
}
