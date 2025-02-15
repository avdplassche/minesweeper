
NAME	=	minesweeper
FLAGS	=	-Wall -Werror -Wextra

CFILES	=	src/main.c\
			src/map_generation.c\
			src/print_map.c\
			src/init_map.c\

OBJ		:= $(CFILES:.c=.o)

all : $(NAME)


$(NAME): $(OBJ)
	@echo "$(NAME) compiled."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ) $(OBJBONUS)
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo "Executables removed."

re: fclean all

.PHONY: clean fclean all re
