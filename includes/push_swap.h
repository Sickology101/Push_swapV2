/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:09:15 by marius            #+#    #+#             */
/*   Updated: 2022/09/14 11:23:24 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				sorted;
	int				current;
	int				final;
	int				lis;
	struct s_stack	*next;
}		t_stack;

void	create_stack(char *str, t_stack **stack);
void	print_stack(t_stack *stack);
void	pa_pb(t_stack **stack1, t_stack **stack2);
void	ra_rb(t_stack **stack);
void	rr(t_stack **stack1, t_stack **stack2);
void	rrr(t_stack **stack1, t_stack **stack2);
void	rra_rrb(t_stack **stack);
void	sa_sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	generate(t_stack **a, t_stack **b);
int		check_sorted(t_stack *a, t_stack *b);
int		check_unique(t_stack *stack);

#endif