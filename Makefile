NAME = cub3d
CFLAGS =  -Wall -Wextra -Werror
FLAGS = -D BUFFER_SIZE=1
MLX = -L/path/to/minilibx -lmlx -framework OpenGL -framework AppKit

CC = cc -Wall -Wextra -Werror
SRCS = main.c  parsing/tools2.c parsing/directions_details.c parsing/directions_verification.c \
		parsing/directions_variables.c parsing/directions_store.c parsing/colors_stock.c \
		parsing/ft_split.c parsing/RGB_stock.c parsing/ciel_split.c  parsing/tools_colors.c \
		parsing/maps_working.c parsing/wall_verification.c parsing/player_param.c parsing/space_checking.c \
		parsing/real_maps_stock.c parsing/after_line.c parsing/itoi.c  text/myMain.c \
		ray_cast/clear_window.c parsing/tools3.c ray_cast/draw.c ray_cast/main_screen.c ray_cast/moves.c ray_cast/player.c ray_cast/draw_3d.c ray_cast/raycast.c ray_cast/moves_help.c


SRC1 = ft_get_next_line/get_next_line.c  \
	ft_get_next_line/ft_putchar.c ft_get_next_line/ft_putnbr.c \
	ft_get_next_line/ft_putstr.c ft_get_next_line/ft_unsigne_value.c \
	ft_get_next_line/get_next_line_utils.c


all : $(NAME)

$(NAME) : ${SRC1} ${SRCS} 
		@${CC} $(SRCS) ${FLAGS} ${MLX} ${SRC1} -o $(NAME)
		@tput setaf 2; echo "Cub3d IS READY"
clean : 
		@rm -fr  $(NAME)
		@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean
		@rm -fr $(NAME) 

re : clean all
