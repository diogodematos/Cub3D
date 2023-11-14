NAME = cub

SRC = cub.c checks.c utils.c check_type.c\

CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
								$(MAKE) -C ./Libft
								@$(CC) $(CFLAGS) $(OBJ) ./Libft/libft.a -o $(NAME)
		
clean:
		$(MAKE) clean -C ./Libft
		@$(RM) $(OBJ)
		
fclean: clean
		$(MAKE) fclean -C ./Libft
		@$(RM) $(NAME) 
		
re: fclean all
		$(MAKE) re -C ./Libft
