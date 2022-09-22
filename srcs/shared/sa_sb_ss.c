/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:24:28 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:44:44 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	sa_sb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*second;

	second = (*stack)->next;
	temp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	(*stack)->next = temp;
	*stack = second;
}
