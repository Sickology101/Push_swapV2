/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:38:55 by mangheli          #+#    #+#             */
/*   Updated: 2022/09/20 09:15:11 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_stack(t_stack *a)
{
	int	n;

	n = a->sorted;
	if (a->next)
		a = a->next;
	else
		return (0);
	while (a->sorted > n && a->next != NULL)
	{
		n = a->sorted;
		a = a->next;
	}
	if (a->next == NULL && a->sorted > n)
		return (1);
	return (0);
}

int	check_under_median(t_stack *a, int median)
{
	int	count;

	count = 0;
	while (a)
	{
		if (a->sorted <= median)
			count++;
		a = a->next;
	}
	if (count == 0)
		return (0);
	else
		return (1);
}

void	sort(t_stack *a, int *index)
{
	t_stack	*temp;
	t_stack *smallest;
	int		count;

	temp = a;
	count = -1;
	while (temp->sorted != -1 && temp->next != NULL)
	{
		temp = temp->next;
	}
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

void	generate_3(t_stack **a)
{
	if ((*a)->next->sorted < (*a)->next->next->sorted)
	{
		sa_sb(a);
		ft_printf("sa\n");
	}
	else
	{
		rra_rrb(a);
		ft_printf("rra\n");
	}
}

int	check_sorted_2(t_stack *a)
{
	if (a->next)
		a = a->next;
	if (check_sorted_stack(a))
		return (0);
	else
		return (1);
}

int	check_sorted_inv(t_stack *a)
{
	int	n;

	n = a->sorted;
	a = a->next;
	while (a->sorted < n && a->next != NULL)
	{
		n = a->sorted;
		a = a->next;
	}
	if (a->next == NULL && a->sorted > n)
		return (1);
	return (0);
}

void generate_inv(t_stack **a, t_stack **b)
{
	while ((*a)->next->next != NULL)
	{
		pa_pb(a, b);
		ft_printf("pb\n");
	}
	sa_sb(a);
	ft_printf("sa\n");
	while ((*b))
	{
		pa_pb(b, a);
		ft_printf("pb\n");
		ra_rb(a);
		ft_printf("ra\n");
	}
}

void	generate_4(t_stack **a, t_stack **b, int median)
{
	if (median == 100)
		median = 100;
	if (!check_sorted_inv(*a))
	{
		generate_inv(a, b);
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

void	push_b(t_stack **a, t_stack **b, int median)
{
	if ((*a)->sorted <= median)
	{
		pa_pb(a, b);
		ft_printf("pb\n");
	}
	else
	{
		ra_rb(a);
		ft_printf("ra\n");
	}
}

void	generate_5(t_stack **a, t_stack **b, int median)
{
	if (check_sorted_inv(*a))
	{
		generate_inv(a, b);
	}
	else
	{
		while (count_stack(*a) > 3)
		{
			push_b(a, b, median);
		}
		while (!check_sorted_stack(*a))
		{
			generate_3(a);
		}
		if (!check_sorted_inv(*b))
		{
			while (*b)
			{
				pa_pb(b, a);
				ft_printf("pa\n");
			}
		}
		else
		{
			sa_sb(b);
			ft_printf("sb\n");
			while (*b)
			{
				pa_pb(b, a);
				ft_printf("pa\n");
			}
		}
	}
}

int	remaining_under_median(t_stack *a, int median)
{
	while (a && a->final == 0)
	{
		if (a->sorted <= median)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_smallest(t_stack *stack)
{
	int	n;

	n = stack->sorted;
	while (stack)
	{
		if (n > stack->sorted)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_b2(t_stack **a, t_stack **b, int *breakpoint)
{
	pa_pb(a, b);
	ft_printf("pb\n");
	(*b)->lis = 0;
	if ((*b)->sorted == *breakpoint)
	{
		ra_rb(b);
		ft_printf("rb\n");
		*breakpoint = *breakpoint - 1;
	}
}

int	check_next_small(t_stack *stack, int smallest)
{
	if (stack)
	{
		if (stack->next)
		{
			if (stack->next->sorted == (smallest + 1))
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
}

int	search_smallest(t_stack *a, int smallest)
{
	while (a)
	{
		if (a->sorted == smallest)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_smallest_pos(t_stack *stack, int smallest)
{
	int	index;

	index = 0;
	while (stack && stack->sorted != smallest)
	{
		index++;
		stack = stack->next;
	}
	return (index);

}

int	calculate_break(t_stack *stack, int breakpoint)
{
	t_stack *temp;

	temp = stack;
	while (temp->sorted != breakpoint)
	{
		if (temp->sorted == breakpoint + 1)
		{
			breakpoint = calculate_break(stack, breakpoint + 1);
			break;
		}
		temp = temp->next;
	}
	return (breakpoint);
}

int	calculate_break_rev(t_stack *stack, int breakpoint)
{
	t_stack *temp;
	
	while (stack && stack->sorted != breakpoint)
	{
		stack = stack->next;
	}
	breakpoint++;
	temp = stack;
	while (temp && temp->sorted != breakpoint)
	{
		if (temp->sorted == breakpoint)
		{
			breakpoint++;
			temp = stack;
		}
		temp = temp->next;
	}
	return (breakpoint);
}


int	last_b_is_small(t_stack *stack, int smallest)
{
	while(stack && stack->next)
	{
		stack = stack->next;
	}
	if (stack->sorted == smallest)
		return (1);
	else
		return (0);
}

void	calculate_lis(t_stack *stack, int	smallest)
{
	t_stack	*temp;


	temp = stack;
	while (temp && temp->sorted != smallest)
	{
		if (temp->sorted == (stack->sorted + stack->lis))
		{
			stack->lis++;
		}
		temp = temp->next;
	}
	if (stack->next && stack->sorted != smallest)
		calculate_lis(stack->next, smallest);
}

int	get_biggest_lis(t_stack *stack)
{
	int	count;

	count = 0;
	while(stack)
	{
		if (stack->lis > count)
			count = stack->lis;
		stack = stack->next;
	}
	return (count);
}

int	calculate_break2(t_stack *stack, int breakpoint)
{
	t_stack *temp;

	temp = stack;
	while (temp->sorted != breakpoint)
	{
		if (temp->sorted == breakpoint - 1)
		{
			breakpoint = calculate_break(stack, breakpoint - 1);
			break;
		}
		temp = temp->next;
	}
	return (breakpoint);
}

int	last_a_is_not_sorted(t_stack *stack)
{
	while(stack && stack->next)
	{
		stack = stack->next;
	}
	if (stack->final == 1)
		return (1);
	else
		return (0);
}

int	calculate_break2_rev2(t_stack *stack, int breakpoint)
{
	t_stack *temp;

	temp = stack;
	while(temp)
	{
		if (temp->sorted == breakpoint - 1)
		{
			breakpoint = calculate_break2_rev2(stack, breakpoint - 1);
			break;
		}
		temp = temp->next;
	}
	return (breakpoint);
}

int	calculate_break2_rev(t_stack *stack, int breakpoint)
{
	while (stack->sorted != breakpoint)
	{
		stack = stack->next;
	}
	breakpoint = calculate_break2_rev2(stack, breakpoint);
	return (breakpoint);
}

void	generate_big(t_stack **a, t_stack **b)
{
	int	smallest;
	int	breakpoint;
	int		lis;
	int		lisnext;
	int		smallpos;
	int		lispos;
	int		count;
	int		topsmall;
	int		bottomsmall;
	int		toplis;
	int		bottomlis;
	int		closesmall;
	int		closelis;

	calculate_lis(*a, 0);
	lis = get_biggest_lis(*a);
	smallest = 0;
	lisnext = 0;
	breakpoint = calculate_break(*a, 0);
	while((*a)->final == 0)
	{
		if ((*a)->sorted == smallest)
		{
			(*a)->final = 2;
			smallest++;
			ra_rb(a);
			ft_printf("ra\n");
		}
		else
		{
			if (lisnext == 0)
			{
				if ((*a)->lis == lis)
				{
					lisnext = (*a)->sorted + 1;
					(*a)->final = 1;
					ra_rb(a);
					ft_printf("ra\n");
				}
				else
				{
					push_b2(a, b, &breakpoint);
				}
			}
			else
			{
				if ((*a)->sorted == lisnext)
				{
					lisnext = (*a)->sorted + 1;
					(*a)->final = 1;
					ra_rb(a);
					ft_printf("ra\n");
				}
				else
				{
					push_b2(a, b, &breakpoint);
				}
			}
		}
	}
	while (last_b_is_small(*b, smallest))
	{
		rra_rrb(b);
		ft_printf("rrb\n");
		pa_pb(b, a);
		ft_printf("pa\n");
		(*a)->final = 2;
		ra_rb(a);
		ft_printf("ra\n");
		smallest++;
	}
	int index = 0;
	while (*b && (*a)->sorted != 0)
	{
		smallpos = get_smallest_pos(*b, smallest) + 1;
		lispos = get_smallest_pos(*b, (*a)->sorted - 1) + 1;
		count = count_stack(*b);
		topsmall = smallpos;
		bottomsmall = count - smallpos;
		if (topsmall < bottomsmall)
		{
			closesmall = topsmall;
		}
		else
		{
			closesmall = bottomsmall;
		}
		toplis = lispos;
		bottomlis = count - lispos;
		if (toplis < bottomlis)
		{
			closelis = toplis;
		}
		else
		{
			closelis = bottomlis;
		}
		if (closesmall > closelis)
		{
			if (lispos < count / 2)
			{
				breakpoint = calculate_break2(*b, (*a)->sorted - 1);
				while ((*b)->sorted != (*a)->sorted - 1)
				{
					if ((*b)->sorted == breakpoint)
					{
						pa_pb(b, a);
						ft_printf("pa\n");
						(*a)->final = 1;
						ra_rb(a);
						ft_printf("ra\n");
						breakpoint++;
					}
					if ((*b)->sorted != (*a)->sorted - 1)
					{
						ra_rb(b);
						ft_printf("rb\n");
					}
				}
			}
			else
			{
				while ((*b)->sorted != (*a)->sorted - 1)
				{
					breakpoint = calculate_break2_rev(*b, (*a)->sorted - 1);
					rra_rrb(b);
					ft_printf("rrb\n");
					if (breakpoint != (*a)->sorted - 1)
					{
						pa_pb(b,a);
						ft_printf("pa\n");
						(*a)->final = 1;
						ra_rb(a);
						ft_printf("ra\n");
						breakpoint++;
					}
				}
			}
		}
		else
		{
			if (smallpos < count / 2)
			{
				breakpoint = calculate_break(*b, smallest);
				while ((*b)->sorted != smallest)
				{
					if (breakpoint != smallest && (*b)->sorted == breakpoint)
					{
						pa_pb(b, a);
						ft_printf("pa\n");
						breakpoint--;
					}
					ra_rb(b);
					ft_printf("rb\n");
				}
			}
			else
			{
				breakpoint = calculate_break_rev(*b, smallest);
				while ((*b)->sorted != smallest)
				{
					rra_rrb(b);
					ft_printf("rrb\n");
					if (breakpoint != smallest && (*b)->sorted == breakpoint)
					{
						pa_pb(b, a);
						ft_printf("pa\n");
						breakpoint--;
					}
				}
			}
		}
		while ((*b)->sorted == (*a)->sorted - 1)
		{
			pa_pb(b, a);
			ft_printf("pa\n");
		}
		while (last_a_is_not_sorted(*a))
		{
			rra_rrb(a);
			ft_printf("rra\n");
		}
		while ((*b)->sorted == smallest)
		{
			pa_pb(b, a);
			ft_printf("pa\n");
			ra_rb(a);
			ft_printf("ra\n");
			smallest++;
		}
		while ((*a)->sorted == smallest)
		{
			ra_rb(a);
			ft_printf("ra\n");
			smallest++;
		}
		index++;
	}
	exit (1);
}

void	generate(t_stack **a, t_stack **b)
{
	int median;
	int	num;

	median = 0;
	sort(*a, &median);
	num = median;
	if ((num % 2) == 0)
		median = median / 2 - 1;
	else
		median = median / 2;
	while (!check_sorted_stack(*a))
	{
		if (num == 2)
		{
			sa_sb(a);
			ft_printf("sa\n");
		}
		else if (num == 3)
		{
			generate_3(a);
		}
		else if (num == 4)
		{
			generate_4(a, b, median);
		}
		else if (num == 5)
		{
			generate_5(a, b, median);
		}
		else if (check_sorted_inv(*a))
		{
			generate_inv(a, b);
		}
		else
		{
			generate_big(a, b);
		}
	}
	/*ft_printf("Stack a: \n");
	print_stack(*a);
	ft_printf("\nStack b:\n");
	print_stack(*b);*/
}

/*int smallest;
	int	breakpoint;
	int	breakpoint2;

	smallest = 0;
	breakpoint = calculate_break1(*a, 0, 0);
	breakpoint2 = calculate_break2(*a, 0);
	while ((*a)->sorted != smallest)
	{
		push_b2(a, b, &breakpoint2);
	}
	while ((*a)->sorted == smallest)
	{
		(*a)->final = 1;
		ra_rb(a);
		ft_printf("ra\n");
		smallest++;
	}
	while (last_b_is_small(*b, smallest))
	{
		rra_rrb(b);
		ft_printf("rrb\n");
		pa_pb(b, a);
		ft_printf("pa\n");
		ra_rb(a);
		ft_printf("ra\n");
		smallest++;
	}
	while (!check_sorted_stack(*a) && *b)
	{
		generate_big2(a, b, smallest);
		while((*a)->sorted == smallest)
		{
			ra_rb(a);
			ft_printf("ra\n");
			smallest++;
		}
	}

	int	calculate_break1(t_stack *stack, int smallest, int	breakpoint)
{
	t_stack *temp;

	temp = stack;
	while (temp->sorted != smallest)
	{
		if (temp->sorted == breakpoint + 1)
		{
			breakpoint = calculate_break1(stack, smallest, breakpoint + 1);
		}
		temp = temp->next;
	}
	return (breakpoint);
}
void	generate_big2(t_stack **a, t_stack **b, int smallest)
{
	int	breakpoint;

	ft_printf("\nsmallest = %d", smallest);
	if (search_smallest(*a, smallest))
	{
		breakpoint = calculate_break2(*a,smallest);
		push_b2(a, b, &breakpoint);
	}
	else
	{
		if (get_smallest_pos(*b, smallest))
		{
			//breakpoint = calculate_break2(*b,smallest);
			while((*b)->sorted != smallest)
			{
				ra_rb(b);
				ft_printf("rb\n");
			}
			pa_pb(b, a);
			ft_printf("pa\n");
		}
		else
		{
			breakpoint = calculate_break_rev(*b,smallest);
			while(breakpoint != smallest)
			{
				rra_rrb(b);
				ft_printf("rrb\n");
				if ((*b)->sorted == breakpoint)
				{
					pa_pb(b, a);
					ft_printf("pa\n");
					breakpoint--;
				}
			}
			while((*b)->sorted != smallest)
			{
				rra_rrb(b);
				ft_printf("rrb\n");
			}
			pa_pb(b, a);
			ft_printf("pa\n");
		}
	}
	ft_printf("Stack a: \n");
	print_stack(*a);
	ft_printf("\nStack b:\n");
	print_stack(*b);
}
*/