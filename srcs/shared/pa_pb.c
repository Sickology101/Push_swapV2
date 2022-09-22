/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:51:33 by marius            #+#    #+#             */
/*   Updated: 2022/08/24 12:29:40 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_stack **stack1, t_stack **stack2)
{
	t_stack	*temp;

	if (*stack1 == NULL)
		ft_printf("error: tring to push from empty stack\n");
	else
	{
		temp = (*stack1)->next;
		(*stack1)->next = *stack2;
		*stack2 = *stack1;
		*stack1 = temp;
	}
}
