/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:10:19 by marius            #+#    #+#             */
/*   Updated: 2022/08/31 14:00:49 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack1, t_stack **stack2)
{
	ra_rb(stack1);
	ra_rb(stack2);
}

void	ra_rb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*loop;
	t_stack	*insert;

	temp = *stack;
	(*stack) = (*stack)->next;
	loop = *stack;
	while (loop->next)
		loop = loop->next;
	if (loop->next)
		insert = loop->next;
	else
		insert = NULL;
	loop->next = temp;
	temp->next = insert;
}
