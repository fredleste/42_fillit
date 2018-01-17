NAME				=		fillit_test

DIR					=		./src

DIR_FILLIT			=		..

DIR_FILLIT_SRC		=		$(DIR_FILLIT)

DIR_LIB				=		$(DIR_FILLIT)/libft

DIR_HEADERS			=		./inc

DIR_HEADERS_FILLIT	=		$(DIR_FILLIT)/inc

DIR_HEADERS_LIB		=		$(DIR_LIB)/inc

LIB					=		-L$(DIR_LIB) -lft

HEADERS				=		-I$(DIR_HEADERS)		\
							-I$(DIR_HEADERS_FILLIT)	\
							-I$(DIR_HEADERS_LIB)

SRCS				=		$(DIR)/main_test.c 				\
							$(DIR_FILLIT_SRC)/mock.c		\
							$(DIR_FILLIT_SRC)/solver.c		\
							$(DIR_FILLIT_SRC)/output.c		\
							$(DIR_FILLIT_SRC)/grid.c		\
							$(DIR_FILLIT_SRC)/tetras_lib.c

OBJS				=		$(SRCS:.c=.o)

CC					=		gcc

CFLAGS				=		-Wall -Wextra

RM					=		rm -f

all					:		$(NAME)

$(NAME)				:		$(OBJS)
							$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(HEADERS) $(LIB)

%.o					:		%.c
							$(CC) -o $@ -c $< $(CFLAGS) $(HEADERS)

clean				:
							$(RM) $(OBJS)

fclean				:		clean
							$(RM) $(NAME)

re					:		fclean all
