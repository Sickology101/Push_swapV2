/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:05:19 by mangheli          #+#    #+#             */
/*   Updated: 2022/09/12 11:11:50 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc != 2)
	{
		ft_printf("Please use ./push_swap {""$ARGS""} to run Push_swap\n");
		return (0);
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a = NULL;
	create_stack(argv[1], &a);
	if (!check_unique(a))
	{
		printf("Sequence containing duplicate numbers!");
		return (0);
	}
	b = NULL;
	if (a->next != NULL)
		generate(&a, &b);
	return (0);
}