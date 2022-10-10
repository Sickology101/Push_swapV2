/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:00:57 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 14:09:56 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_temp(t_stack *temp)
{
	while (temp->sorted != -1 && temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

void	sort(t_stack *a, int *index)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		count;

	temp = a;
	count = -1;
	temp = get_temp(temp);
	if (temp != NULL)
		smallest = temp;
	while (temp != NULL)
	{
		if (temp->num < smallest->num && temp->sorted == -1)
			smallest = temp;
		temp = temp->next;
		count++;
	}
	if (count == 0 && smallest->next == NULL && smallest->sorted == -1)
	{
		smallest->sorted = (*index)++;
	}
	if (count != 0)
	{
		smallest->sorted = (*index)++;
		sort(a, index);
	}
}

int	count_stack(t_stack *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}
