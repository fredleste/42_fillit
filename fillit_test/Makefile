NAME				=		fillit_test

DIR					=		./src

DIR_FILLIT			=		..

DIR_FILLIT_SRC		=		$(DIR_FILLIT)

DIR_LIB				=		$(DIR_FILLIT)/libft

DIR_HEADERS			=		./inc

DIR_HEADERS_FILLIT	=		$(DIR_FILLIT)

DIR_HEADERS_LIB		=		$(DIR_LIB)

LIB					=		-L$(DIR_LIB) -lft

HEADERS				=		-I$(DIR_HEADERS)		\
							-I$(DIR_HEADERS_FILLIT)	\
							-I$(DIR_HEADERS_LIB)

SRCS				=		$(DIR)/main_test.c 				\
							$(DIR)/helper_test.c 			\
							$(DIR)/output_test.c 			\
							$(DIR_FILLIT_SRC)/test.c		\
							$(DIR_FILLIT_SRC)/solver.c		\
							$(DIR_FILLIT_SRC)/solver_add.c		\
							$(DIR_FILLIT_SRC)/output.c

OBJS				=		$(SRCS:.c=.o)

CC					=		gcc

CFLAGS				=		-Wall -Wextra -Werror

RM					=		rm -f

all					:		$(NAME)

$(NAME)				:		$(OBJS)
							$(MAKE) -C $(DIR_LIB)
							$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(HEADERS) $(LIB)

%.o					:		%.c
							$(CC) -o $@ -c $< $(CFLAGS) $(HEADERS)

clean				:
							$(MAKE) -C $(DIR_LIB) clean
							$(RM) $(OBJS)

fclean				:		clean
							$(MAKE) -C $(DIR_LIB) fclean
							$(RM) $(NAME)

re					:		fclean all
