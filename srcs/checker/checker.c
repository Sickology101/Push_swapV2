/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:07:31 by mangheli          #+#    #+#             */
/*   Updated: 2022/08/31 14:47:31 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_inst(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		sa_sb(a);
	else if (!ft_strcmp(line, "sb"))
		sa_sb(b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa_pb(b, a);
	else if (!ft_strcmp(line, "pb"))
		pa_pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra_rb(a);
	else if (!ft_strcmp(line, "rb"))
		ra_rb(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		rra_rrb(a);
	else if (!ft_strcmp(line, "rrb"))
		rra_rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char *line;
	
	if (argc != 2)
	{
		ft_printf("Please use ./checker {""$ARGS""} to run Checker\n");
		return (0);
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a = NULL;
	create_stack(argv[1], &a);
	check_unique(a);
	b = NULL;
	//print_stack(a);
	while (get_next_line(0, &line))
	{
		//ft_printf("line = %s\n", line);
		if (read_inst(line, &a, &b))
		{
			if (ft_strcmp(line, ""))
				ft_printf("ERROR ");
			break ;
		}
	}
	if (check_sorted(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}