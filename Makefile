#Variables

NAME					= checker push_swap
CHECKER					= checker
PUSHSWAP				= push_swap
INCLUDE					= -I ./include
LIBFT_DIR				= ./libft
LIBFT					= -L ./libft -lft
SRC_DIR					= src/
CC						= gcc
CFLAGS					= -Wall -Werror -Wextra -O3
RM						= rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CHECKER_SRC		=	checker utils commands parser higher_commands \
					preparation getters analysis command_parser

PUSHSWAP_SRC	=	push_swap parser utils commands higher_commands \
					preparation complex_commands getters analysis \
					command_parser

CHECKER_PATH	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CHECKER_SRC)))
PUSHSWAP_PATH	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(PUSHSWAP_SRC)))
CHECKER_OBJ 	=	$(addsuffix .o, $(CHECKER_SRC))
PUSHSWAP_OBJ	=	$(addsuffix .o, $(PUSHSWAP_SRC))

all:			$(NAME)

$(CHECKER):
				@make -C $(LIBFT_DIR)
				${CC} $(CFLAGS) -c $(CHECKER_PATH) $(INCLUDE)
				${CC} -o $(CHECKER) $(CHECKER_OBJ) $(LIBFT)
				@echo "$(GREEN)checker compiled!$(DEF_COLOR)"

$(PUSHSWAP):
				@make -C $(LIBFT_DIR)
				${CC} $(CFLAGS) -c $(PUSHSWAP_PATH) $(INCLUDE)
				${CC} -o $(PUSHSWAP) $(PUSHSWAP_OBJ) $(LIBFT)
				@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

clean:
				@$(RM) -rf $(PUSHSWAP_OBJ)
				@echo "$(BLUE) push_swap object files cleaned!$(DEF_COLOR)"
				@$(RM) -rf $(CHECKER_OBJ)
				@echo "$(BLUE) checker object files cleaned!$(DEF_COLOR)"
				@make clean -C $(LIBFT_DIR)
				@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:			clean
				@$(RM) -f $(CHECKER)
				@echo "$(CYAN)checker binary files cleaned!$(DEF_COLOR)"
				@$(RM) -f $(PUSHSWAP)
				@echo "$(CYAN)push_swap binary files cleaned!$(DEF_COLOR)"
				@make fclean -C $(LIBFT_DIR)
				@echo "$(CYAN)libft binary files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Rebuilt all!$(DEF_COLOR)"

visualize:		re
				@cp ./push_swap ../push_swap_visualizer/build
				../push_swap_visualizer/build/bin/visualizer
			
.PHONY:			all clean fclean re visuallize