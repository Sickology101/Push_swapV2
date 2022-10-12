/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:07:31 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/12 12:30:03 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ok(t_stack *a, t_stack *b)
{
	if (check_sorted(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	check_unique_help(t_stack *a)
{
	if (!check_unique(a))
	{
		clearlist(a);
		printf("ERROR: Sequence containing duplicate numbers!");
		exit (1);
	}
	if (!a)
	{
		clearlist(a);
		exit (1);
	}
}

static void	check_arg(int argc)
{
	if (argc < 2)
	{
		ft_printf("Please use ./checker {""$ARGS""} to run Checker\n");
		exit (1);
	}
}

static void	check_line(char *line)
{
	if (ft_strcmp(line, ""))
	{
		ft_printf("ERROR ");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	check_arg(argc);
	if (argc == 2)
		create_stack(argv[1], &a);
	else
		create_stack2(argc, argv, &a);
	check_unique_help(a);
	while (get_next_line(0, &line))
	{
		if (read_inst(line, &a, &b))
		{
			check_line(line);
			break ;
		}
		free(line);
	}
	check_ok(a, b);
	clearlist(a);
	return (0);
}
