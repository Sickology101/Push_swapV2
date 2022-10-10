/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:25:08 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/06 11:46:57 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d sorted = %d   chunk = %d\n",stack->num, stack->sorted, stack->chunk);
		stack = stack->next;
	}
}
int	get_num(char *str, int	*index)
{
	long long	n;
	long long sign;

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
	if (n > 2147483647 || n < -2147483648)
	{
		ft_printf("ERROR! argument over MAX_INT / MIN_INT");
		exit (1);
	}
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
		temp->chunk = 0;
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