/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:07:31 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/13 12:45:03 by mangheli         ###   ########.fr       */
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
		my_exit();
	}
	if (!a)
	{
		clearlist(a);
		my_exit();
	}
}

static void	check_arg(int argc)
{
	if (argc < 2)
	{
		my_exit();
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	*str;

	check_arg(argc);
	if (argc == 2)
		create_stack(argv[1], &a);
	else
		create_stack2(argc, argv, &a);
	check_unique_help(a);
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	while (get_next_line(0, &line))
	{
		str = ft_strupdate(str, line);
		str = ft_strupdate(str, "\n");
		free(line);
	}
	string_split(str, &a, &b);
	free(str);
	check_ok(a, b);
	clearlist(a);
	clearlist(b);
	return (0);
}
