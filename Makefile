NAME			=	push_swap

SRC				=	src/error_handling.c src/init_pile.c src/main.c src/reverse_rotate.c src/rotate.c \
					src/sort3.c src/swap.c src/turkish_algo.c src/upload_data.c src/utils.c src/utils2.c \
					src/utils_lst.c src/utils3.c src/push.c

OBJS			=	${SRC:.c=.o}

CC				=	cc

LIBS 			= libs/printf/libftprintf.a

HEAD 			= -Isrc/push_swap.h

CFLAGS			= -Wall -Wextra -Werror -g3

all				:	${NAME}

%.o: %.c push_swap.h
	@${CC} ${CFLAGS} ${HEAD} -c $< -o $@ >/dev/null 2>&1

$(NAME)			:	${OBJS}
	@make -C libs/printf >/dev/null 2>&1
	@${CC} ${CFLAGS} -g3 ${OBJS} -o ${NAME} ${LIBS} >/dev/null 2>&1
	@echo "\nPUSH_SWAP IS CREATED"

clean			:
	@make clean -C libs/printf >/dev/null 2>&1
	@rm -rf ${OBJS}

fclean			:	clean
	@make fclean -C libs/printf >/dev/null 2>&1
	@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
