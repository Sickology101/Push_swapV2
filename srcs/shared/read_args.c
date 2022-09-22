/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:25:08 by mangheli          #+#    #+#             */
/*   Updated: 2022/09/14 11:31:02 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d sorted = %d   lis = %d\n",stack->num, stack->sorted, stack->lis);
		stack = stack->next;
	}
}
int	get_num(char *str, int	*index)
{
	int	n;
	int sign;

	n = 0;
	sign = 1;
	if (str[*index] == '-')
	{
		sign = -1;
		(*index)++;
	}
	while (ft_isdigit(str[*index]))
	{
		n = n * 10 + str[*index] - '0';
		(*index)++;
	}
	n = n * sign;
	return (n);
}

void	create_stack(char *str, t_stack **stack)
{
	int		index;
	t_stack	*temp;
	t_stack *head;

	index = 0;
	while (str[index] != '\0')
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		temp->next = NULL;
		temp->num = get_num(str, &index);
		temp->sorted = -1;
		temp->final = 0;
		temp->lis = 0;
		if (str[index] != '\0')
			index++;
		if ((*stack) == NULL)
		{
			*stack = temp;
			head = *stack;
		}
		else
		{
			(*stack)->next = temp;
			(*stack) = (*stack)->next;
		}
	}
	*stack = head;
}