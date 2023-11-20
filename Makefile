NAME = cub3d
NAME_BONUS = cub3d_bonus

SRC = Mandatory/cub.c Mandatory/checks.c Mandatory/utils.c Mandatory/check_type.c Mandatory/utils2.c\


BONUS = Bonus/cub.c Bonus/checks.c Bonus/utils.c Bonus/check_type.c Bonus/utils2.c\

CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./Libft
		@$(CC) $(CFLAGS) $(OBJ) ./Libft/libft.a -o $(NAME)
		
bonus:	$(BONUS_OBJ)
		$(MAKE) -C ./Libft
		@$(CC) $(CFLAGS) $(BONUS_OBJ) ./Libft/libft.a -o $(NAME_BONUS)

clean:
		$(MAKE) clean -C ./Libft
		@$(RM) $(OBJ) $(BONUS_OBJ)
		
fclean: clean
		$(MAKE) fclean -C ./Libft
		@$(RM) $(NAME) $(NAME_BONUS)
		
re: fclean all
		$(MAKE) re -C ./Libft
