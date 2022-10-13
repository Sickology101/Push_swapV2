/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:18:24 by mangheli          #+#    #+#             */
/*   Updated: 2022/10/13 11:59:53 by mangheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	read_inst(char *line, t_stack **a, t_stack **b)
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

int	get_num2(t_stack *temp, char *str)
{
	long long	n;
	long long	sign;
	int			index;

	n = 0;
	sign = 1;
	index = 0;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		n = n * 10 + str[index] - '0';
		if (n > 2147483648)
			break ;
		index++;
	}
	n = n * sign;
	check_valid(n, str, index, temp);
	return (n);
}

void	string_split(char *str, t_stack **a, t_stack **b)
{
	char	*line;
	int		index;
	int		index2;

	index = 0;
	line = (char *)malloc(sizeof(char) * 5);
	while (str[index] != '\0')
	{
		index2 = 0;
		while (str[index] != '\0' && str[index] != '\n')
		{
			line[index2++] = str[index++];
		}
		line[index2] = '\0';
		if (str[index] == '\0')
			break ;
		if (str[index] == '\n')
			index++;
		if (read_inst(line, a, b))
			my_exit();
	}
	free(line);
}
