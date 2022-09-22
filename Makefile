
#Variables

CHECKER_EXECUTABLE		= checker
PUSH_SWAP_EXECUTABLE	= push_swap
INCLUDE					= -I include
LIBFT					= libft
SRC_DIR					= src/
OBJ_DIR					= src/
TEST_DIR				= test/
TEST_EXE				= run_test
CC						= gcc
CFLAGS					= -Wall -Werror -Wextra -O3
RM						= rm -f
AR						= ar rcs

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

CHECKER_SRC_FILES	=
PUSHSWAP_SRC_FILES	=
TEST_FILES	=	*

CHECKER_SRC 	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CHECKER_SRC_FILES)))
PUSH_SWAP_SRC 	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(PUSHSWAP_SRC_FILES)))
CHECKER_OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CHECKER_SRC_FILES)))
PUSHSWAP_OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(PUSHSWAP_SRC_FILES)))
TEST 			= 	$(addprefix $(TEST_DIR), $(addsuffix .test.c, $(TEST_FILES)))

all:			$(CHECKER) $(PUSH_SWAP)

$(CHECKER):		$(CHECKER_OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(CHECKER)
				@make -C $(CHECKER) $(CHECKER_OBJ)
				@echo "$(GREEN)checker compiled!$(DEF_COLOR)"

$(PUSHSWAP):	$(PUSHSWAP_OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(PUSHSWAP)
				@make -C $(PUSHSWAP) $(PUSHSWAP_OBJ)
				@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(PUSHSWAP_OBJ)
			@echo "$(BLUE) push_swap object files cleaned!$(DEF_COLOR)"
			@$(RM) -rf $(CHECKER_OBJ)
			@echo "$(BLUE) checker object files cleaned!$(DEF_COLOR)"
			@make clean -C $(LIBFT)
			@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(CHECKER)
			@echo "$(CYAN)checker binary files cleaned!$(DEF_COLOR)"
			@$(RM) -f $(PUSH_SWAP)
			@echo "$(CYAN)push_swap binary files cleaned!$(DEF_COLOR)"
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)libft binary files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Rebuilt ft_printf!$(DEF_COLOR)"

test:		re
			${CC} -L . -l ${LIBFT} -o ${TEST_EXE} -fsanitize=address -g
			./${TEST_EXE}
			
.PHONY:		all clean fclean re