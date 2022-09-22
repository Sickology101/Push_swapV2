/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:24:15 by mangheli          #+#    #+#             */
/*   Updated: 2022/08/31 14:46:49 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_unique(t_stack *stack)
{
	t_stack *temp;
	int	n;

	while (stack)
	{
		temp = stack->next;
		n = stack->num;
		while (temp)
		{
			if (temp->num == n)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_sorted(t_stack *a, t_stack *b)
{
	int	n;

	if (b != NULL)
		return (0);
	n = a->num;
	a = a->next;
	while (a->num > n && a->next != NULL)
	{
		n = a->num;
		a = a->next;
	}
	if (a->next == NULL && a->num > n)
		return (1);
	return (0);
}