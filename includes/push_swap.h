/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:09:15 by marius            #+#    #+#             */
/*   Updated: 2022/10/13 11:58:26 by mangheli         ###   ########.fr       */
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
	int				chunk;
	struct s_stack	*next;
}		t_stack;

typedef struct s_chunkData
{
	int	size;
	int	chunk_size;
	int	chunk;
	int	chunksmall;
	int	chunkbig;
}		t_chunkData;

typedef struct s_index
{
	int	index;
	int	counter;
}		t_index;

typedef struct s_data
{
	int	smallest;
	int	biggest;
}		t_data;

typedef struct s_dist
{
	int	countsmall;
	int	countsmallrev;
	int	countbig;
	int	countbigrev;
	int	smalldist;
	int	bigdist;
}		t_dist;

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
void	clearlist(t_stack *a);
int		check_sorted_stack(t_stack *a);
void	sort(t_stack *a, int *index);
int		check_sorted_inv(t_stack *a);
void	generate_inv(t_stack **a, t_stack **b);
int		count_stack(t_stack *a);
void	push_b(t_stack **a, t_stack **b, int median);
void	generate_3(t_stack **a);
void	generate_4(t_stack **a, t_stack **b);
void	empty_b(t_stack **b, t_stack **a);
void	generate_5(t_stack **a, t_stack **b);
int		calculate_chunks(t_stack *a);
int		check_chunk_in_stack(t_stack *a, int chunksmall, int chunkbig);
void	assign_chunks(t_stack *a, int chunks);
void	push_b_chunks(t_stack **a, t_stack **b, int chunksmall, int chunkbig);
int		check_in_a(t_stack *a, int smallest, int biggest);
void	push_b_chunksv2(t_stack **a, t_stack **b, int chunkbig, t_data data);
int		count_dist(t_stack *b, int smallest);
int		count_dist_rev(t_stack *b, int smallest);
int		calculate_dist(int count, int countrev);
void	push_av2(t_stack **a, t_stack **b, int breakpoint);
void	push_av2_rev(t_stack **a, t_stack **b, int breakpoint);
void	rotate_a2(t_stack **a);
t_dist	init_dist(t_stack **b, t_data *data);
void	generate_5_help(t_stack **a, t_stack **b);
int		get_num2(t_stack *temp, char *str);
void	check_valid(long long n, char *str, int index, t_stack *temp);
void	create_stack2(int argc, char **argv, t_stack **stack);
int		read_inst(char *line, t_stack **a, t_stack **b);
void	check_line(char *line);
void	string_split(char *str, t_stack **a, t_stack **b);
void	check_line(char *line);
void	my_exit(void);

#endif