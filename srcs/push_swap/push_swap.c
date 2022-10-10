/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:05:19 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/10 16:04:28 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc != 2)
	{
		ft_printf("Please use ./push_swap {""$ARGS""} to run Push_swap\n");
		return (0);
	}
	create_stack(argv[1], &a);
	if (!check_unique(a))
	{
		clearlist(a);
		printf("Sequence containing duplicate numbers!");
		return (0);
	}
	if (a->next != NULL)
		generate(&a, &b);
	clearlist(a);
	return (0);
}

//system("leaks push_swap");