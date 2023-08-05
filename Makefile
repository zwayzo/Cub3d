NAME = Cub3d
CFLAGS =  -Wall -Wextra -Werror -fsanitize=address
FLAGS = -D BUFFER_SIZE=1
MLX =  -Lmlx -framework OpenGL -framework AppKit 
CC = cc
SRCS = parsing/main.c libmlx.a parsing/directions_details.c parsing/directions_verification.c \
		parsing/directions_variables.c parsing/directions_store.c

SRC1 = ft_get_next_line/get_next_line.c ft_get_next_line/ft_hexadecimale.c \
	ft_get_next_line/ft_putchar.c ft_get_next_line/ft_putnbr.c \
	ft_get_next_line/ft_putstr.c ft_get_next_line/ft_unsigne_value.c \
	ft_get_next_line/get_next_line_utils.c

 
all : $(NAME)

$(NAME) : ${SRC1} ${SRCS} 
		@${CC} $(SRCS) ${CFALGS} $(MLX) ${FLAGS} ${SRC1} -o $(NAME)
		@tput setaf 2; echo "Cub3d IS READY"
clean : 
		@rm -fr  $(NAME)
		@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean
		@rm -fr $(NAME) 

re : clean all