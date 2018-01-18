NAME = get.exe

SRCS = *.c

OBJ = *.o

#INC = includes/

#FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)