/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:05:19 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/13 12:30:48 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		my_exit();
	}
	if (argc == 2)
		create_stack(argv[1], &a);
	else
		create_stack2(argc, argv, &a);
	if (!check_unique(a))
	{
		clearlist(a);
		my_exit();
	}
	if (a->next != NULL)
		generate(&a, &b);
	clearlist(a);
	return (0);
}

//system("leaks push_swap");