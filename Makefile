NAME = cub3d
BONUS = cub3d_bonus

MINILIBX = minilibx-linux/libmlx.a

SRC = m/cub.c m/checks.c m/utils.c m/check_type.c m/utils2.c m/utils3.c\
		m/game.c m/rayCasting.c m/ft_events.c m/mlx_handle.c m/movement.c m/initialize.c\
		m/rayCastingFirst.c m/rayCastingSecond.c m/tex_handle.c m/rotation.c

BONUS_SRCS = b/cub.c b/checks.c b/utils.c b/check_type.c b/utils2.c b/utils3.c\
		b/game.c b/rayCasting.c b/ft_events.c b/mlx_handle.c b/movement.c b/initialize.c\
		b/rayCastingFirst.c b/rayCastingSecond.c b/tex_handle.c b/rotation.c b/minimap.c\

CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -lX11 -lXext
AR = ar rcs

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
								$(MAKE) -C minilibx-linux
								$(MAKE) -C Libft
								@$(CC) $(CFLAGS) $(OBJ) minilibx-linux/libmlx.a Libft/libft.a -o $(NAME) $(LIBXFLAGS) -lm
bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
								$(MAKE) -C minilibx-linux
								$(MAKE) -C Libft
								@$(CC) $(CFLAGS) $(BONUS_OBJ) minilibx-linux/libmlx.a Libft/libft.a -o $(BONUS) $(LIBXFLAGS) -lm

clean:
		$(MAKE) clean -C Libft
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
		$(MAKE) fclean -C Libft
		@$(RM) $(NAME) $(BONUS)

re: fclean all
		$(MAKE) re -C Libft
