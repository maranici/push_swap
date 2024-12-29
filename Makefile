# compil
COMPIL = cc
CFLAGS = -Wall -Wextra -Werror

# variables
EXE_NAME = push_swap
CHECKER_NAME = checker

MAIN_SRC = main.c
CHECKER_SRC = bonus/checker.c bonus/checker_utils.c

ALGO_DIR = algo/
ALGO_SRCS = push_swap.c check_if_sorted.c algo_two_nums.c algo_three_nums.c algo_more_nums.c set_node_index.c target_node.c init_stack_a.c ops_calcul.c \
			push_a_to_b.c push_b_to_a.c reorder_stacks.c order_a.c

MOVES_DIR = moves/
MOVES_SRCS = push.c rotate.c reverse_rotate.c swap.c

UTILS_DIR = utils/
UTILS_SRCS = check_errors.c create_stack_a.c ft_stackadd_back.c ft_stacklast.c ft_free_stack.c stack_len.c find_extremum.c \
			define_cheapest.c get_cheapest.c ft_free_splited.c

SRCS = $(addprefix ${UTILS_DIR}, ${UTILS_SRCS}) $(addprefix ${MOVES_DIR}, ${MOVES_SRCS}) $(addprefix ${ALGO_DIR}, ${ALGO_SRCS})

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT_AR = $(addprefix ${LIBFT_DIR}, ${LIBFT_NAME})

BOLD = \033[1m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m

# phony
.PHONY = all bonus clean fclean re

# rules
all: ${EXE_NAME}

${EXE_NAME}: ${LIBFT_AR}
	@ echo -e '${BOLD}Compiling the executable...${NC}'
	@ ${COMPIL} ${CFLAGS} -Iinc/ -Ilibft/inc/ -o ${EXE_NAME} ${MAIN_SRC} ${SRCS} ${LIBFT_AR}
	@ echo -e '${BOLD}${GREEN}Executable ready ✅${NC}'

bonus: ${CHECKER_NAME}

${CHECKER_NAME}: ${LIBFT_AR}
	@ echo -e '${BOLD}Compiling the checker executable...${NC}'
	@ ${COMPIL} ${CFLAGS} -Iinc/ -Ilibft/inc/ -o ${CHECKER_NAME} ${CHECKER_SRC} ${SRCS} ${LIBFT_AR}
	@ echo -e '${BOLD}${GREEN}Checker ready ✅${NC}'

${LIBFT_AR}:
	@ $(MAKE) -C ${LIBFT_DIR}

clean:
	@ echo -e '${BOLD}Cleaning objets...${NC}'
	@ $(MAKE) clean -C libft/
	@ rm -f ${OBJS}
	@ echo -e '${BOLD}${GREEN}Done!${NC}'

fclean: clean
	@ $(MAKE) fclean -C libft/
	@ echo -e '${BOLD}Removing executables...${NC}'
	@ rm -f ${EXE_NAME}
	@ rm -f ${CHECKER_NAME}
	@ echo -e '${BOLD}${GREEN}Done!${NC}'

re: fclean all
