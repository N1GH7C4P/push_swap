#Variables

NAME					= checker push_swap
CHECKER					= checker
PUSHSWAP				= push_swap
INCLUDE					= -I include
LIBFT_LIB				= -L ./libft -lft
LIBFT					= libft
SRC_DIR					= src/
OBJ_DIR					= src/
TEST_DIR				= test/
TEST_EXE				= run_test
CC						= gcc
CFLAGS					= -Wall -Werror -Wextra -O3
TEST_FLAGS				= -fsanitize=address -g
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

CHECKER_SRC_FILES	= checker utils commands parser higher_commands preparation getters analysis command_parser
PUSHSWAP_SRC_FILES	= push_swap parser utils commands higher_commands preparation complex_commands getters analysis command_parser
TEST_FILES	=	*

CHECKER_SRC 	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CHECKER_SRC_FILES)))
PUSHSWAP_SRC 	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(PUSHSWAP_SRC_FILES)))
CHECKER_OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CHECKER_SRC_FILES)))
PUSHSWAP_OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(PUSHSWAP_SRC_FILES)))
TEST 			= 	$(addprefix $(TEST_DIR), $(addsuffix .test.c, $(TEST_FILES)))

all:			$(NAME)

$(NAME):		$(CHECKER) $(PUSHSWAP)

memory_test:	$(PUSHSWAP_OBJ) $(CHECKER_OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				${CC} $(CFLAGS) $(TEST_FLAGS) $(INCLUDE) $(LIBFT_LIB) $(PUSHSWAP_SRC) -o $(PUSHSWAP)
				@echo "$(GREEN)memory test push_swap compiled!$(DEF_COLOR)"
				@make -C $(LIBFT)
				@cp libft/libft.a .
				${CC} $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(CHECKER_SRC) -o $(CHECKER)
				@echo "$(GREEN)memory test checker compiled!$(DEF_COLOR)"
				@rm -f libft.a

$(CHECKER):		$(CHECKER_OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				${CC} $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(CHECKER_SRC) -o $(CHECKER)
				@rm -f libft.a
				@echo "$(GREEN)checker compiled!$(DEF_COLOR)"

$(PUSHSWAP):	$(PUSHSWAP_OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				${CC} $(CFLAGS) $(INCLUDE) $(LIBFT_LIB) $(PUSHSWAP_SRC) -o $(PUSHSWAP)
				@rm -f libft.a
				@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

clean:
				@$(RM) -rf $(PUSHSWAP_OBJ)
				@echo "$(BLUE) push_swap object files cleaned!$(DEF_COLOR)"
				@$(RM) -rf $(CHECKER_OBJ)
				@echo "$(BLUE) checker object files cleaned!$(DEF_COLOR)"
				@make clean -C $(LIBFT)
				@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:			clean
				@$(RM) -f $(CHECKER)
				@echo "$(CYAN)checker binary files cleaned!$(DEF_COLOR)"
				@$(RM) -f $(PUSHSWAP)
				@echo "$(CYAN)push_swap binary files cleaned!$(DEF_COLOR)"
				@make fclean -C $(LIBFT)
				@echo "$(CYAN)libft binary files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Rebuilt all!$(DEF_COLOR)"

visualize:		re
				@cp ./push_swap ../push_swap_visualizer/build
				../push_swap_visualizer/build/bin/visualizer
			
.PHONY:			all clean fclean re