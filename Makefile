# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mangheli <mangheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 08:10:42 by marius            #+#    #+#              #
#    Updated: 2022/10/06 11:45:58 by mangheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
VISUALIZER = visualizer
NAME = $(PUSH_SWAP) $(CHECKER) $(VISUALIZER)
LIBFT_A = libftprintf.a

COMP = gcc -Wall -Werror -Wextra -I includes -I libft/includes -I libft/libft
COMP_V = gcc -Wall -Werror -Wextra -I includes -I libft/includes -I libft/libft -lmlx -framework OpenGL -framework AppKit -o

OBJ_DIR = obj/
S_SRC_DIR = srcs/shared/
P_SRC_DIR = srcs/push_swap/
C_SRC_DIR = srcs/checker/
V_SRC_DIR = srcs/visualizer/
LIBFT = libft/

S_SRC = $(S_SRC_DIR)read_args.c $(S_SRC_DIR)pa_pb.c $(S_SRC_DIR)ra_rb_rr.c $(S_SRC_DIR)rra_rrb_rrr.c $(S_SRC_DIR)sa_sb_ss.c $(S_SRC_DIR)utils.c
P_SRC = $(P_SRC_DIR)push_swap.c $(P_SRC_DIR)generate.c
C_SRC = $(C_SRC_DIR)checker.c
V_SRC = 

S_OBJ = $(S_SRC:%.c=%.o)
P_OBJ = $(P_SRC:%.c=%.o)
C_OBJ = $(C_SRC:%.c=%.o)
OBJ = $(S_OBJ) $(P_OBJ) $(C_OBJ)


S_SRC_PATH = $(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH = $(P_SRC:%=$(P_SRC_DIR)%)
C_SRC_PATH = $(C_SRC:%=$(C_SRC_DIR)%)
SRC_PATH = $(S_SRC_PATH) $(P_SRC_PATH) $(C_SRC_PATH)

S_OBJ_PATH = $(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH = $(addprefix $(OBJ_DIR), $(P_OBJ))
C_OBJ_PATH = $(addprefix $(OBJ_DIR), $(C_OBJ))
OBJ_PATH = $(S_OBJ_PATH) $(P_OBJ_PATH) $(C_OBJ_PATH)

all: colour do_libft $(NAME)
			@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE \033[0m \\n"
$(NAME):
			$(COMP) -o $(CHECKER) $(C_SRC) $(S_SRC) $(LIBFT_A) -g
			$(COMP) -o $(PUSH_SWAP) $(P_SRC) $(S_SRC) $(LIBFT_A) -g
			#$(COMP_V) $(VISUALIZER) $(V_SRC) $(S_SRC) $(LIBFT_A)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	$(COMP) -c $< -o $@

do_libft:
			@make -C $(LIBFT)
			@cp $(LIBFT)/$(LIBFT_A) .

colour:
			@echo "\x1b[36m""\x1b[1A\x1b[M"

clean: colour
			@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
			@make -C $(LIBFT) clean
			@echo "\\n\033[32;1m Cleaned libft object files \033[0m"

fclean: clean
			@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
			/bin/rm -f $(NAME)
			@make -C $(LIBFT) clean
			@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: fclean all

.PHONY: all clean fclean re colour 