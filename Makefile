# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 12:33:55 by mangheli          #+#    #+#              #
#    Updated: 2022/10/13 12:40:53 by mangheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
PUSHSWAP	=	push_swap
LIBFT		=	libft/libftprintf.a
FLAGS		=	-Wall -Wextra -Werror -I includes -I libft/includes -I libft/libft

CHK_SRC		=	checker.c
PS_SRC		=	generate_helper1.c generate_helper2.c generate_helper3.c generate_helper4.c generate_helper5.c generate.c push_swap.c utils2.c
COMMON_SRC	=	pa_pb.c ra_rb_rr.c read_args.c rra_rrb_rrr.c utils.c utils3.c sa_sb_ss.c

LIBFT_DIR	=	libft/
CHK_DIR		=	srcs/checker/
PS_DIR		=	srcs/push_swap/
COMMON_DIR	=	srcs/shared/

CHK_SRCS	=	$(addprefix $(CHK_DIR), $(CHK_SRC))
PS_SRCS		=	$(addprefix $(PS_DIR), $(PS_SRC))
COMMON_SRCS	=	$(addprefix $(COMMON_DIR), $(COMMON_SRC))

OBJ_DIR		=	obj/
OBJS		= 	$(CHK_OBJS) $(PS_OBJS) $(COMMON_OBJS)
CHK_OBJS	=	$(patsubst %, $(OBJ_DIR)%, $(CHK_SRC:.c=.o))
PS_OBJS		=	$(patsubst %, $(OBJ_DIR)%, $(PS_SRC:.c=.o))
COMMON_OBJS	=	$(patsubst %, $(OBJ_DIR)%, $(COMMON_SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(CHK_OBJS) $(PS_OBJS) $(COMMON_OBJS)
	@gcc $(FLAGS) $(LIBFT) $(COMMON_OBJS) $(CHK_OBJS) -o $(NAME)
	@gcc $(FLAGS) $(LIBFT) $(COMMON_OBJS) $(PS_OBJS) -o $(PUSHSWAP)
	@printf "Compilation complete.\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(CHK_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Checker compiled.\n"

$(OBJ_DIR)%.o: $(PS_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Push_swap compiled.\n"

$(OBJ_DIR)%.o: $(COMMON_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<
	@printf "Common files compiled.\n"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS) $(SURPL_O)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME) $(PUSHSWAP) *.out

re: fclean all