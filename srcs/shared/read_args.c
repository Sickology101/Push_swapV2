/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:25:08 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 16:07:24 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//function used to print the stacks
/*void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d sorted = %d   chunk = %d\n",stack->num,
			 stack->sorted, stack->chunk);
		stack = stack->next;
	}
}*/

int	get_num(t_stack *temp, char *str, int	*index)
{
	long long	n;
	long long	sign;

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
		clearlist(temp);
		ft_printf("ERROR! argument over MAX_INT / MIN_INT");
		exit (1);
	}
	return (n);
}

static t_stack	*init_temp(void)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	temp->next = NULL;
	temp->sorted = -1;
	temp->final = 0;
	temp->chunk = 0;
	return (temp);
}

void	create_stack(char *str, t_stack **stack)
{
	int		index;
	t_stack	*temp;
	t_stack	*head;

	index = 0;
	while (str[index] != '\0')
	{
		temp = init_temp();
		temp->num = get_num(temp, str, &index);
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
