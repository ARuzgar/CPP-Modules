NAME = FormUp

OBJ_DIR = ./trash/

SRCS = $(wildcard *.cpp)

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

git:
	@make fclean
	@git add .
	@read -p "Enter commit message: " message; \
	git commit -m "$$message"
	@git push

gitall:
	@make fclean
	cd ..
	@git add .
	@read -p "Enter commit message: " message; \
	git commit -m "$$message"
	@git push

re: fclean all

.PHONY: all clean fclean re