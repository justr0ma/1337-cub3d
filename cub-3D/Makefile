NAME = cub3D

AR = ar -rc

CFLAGS =  -Wall -Wextra -Werror

RM = rm -f

CC = cc

SRCS = ./chekmap/mouse.c ./chekmap/ft_chekmap.c ./chekmap/ft_chek.c ./chekmap/ft_justchek.c \
		./justutil/ft_get_next_line.c ./justutil/ft_util.c ./justutil/libft/libft.a \
		./render3d/put_pixel.c ./render3d/just.c ./render3d/just_far_from_map.c \
		main.c

all : $(NAME)
$(NAME) : $(SRCS)
	@${CC} ${CFLAGS} ${SRCS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} $(NAME)

re : fclean all
