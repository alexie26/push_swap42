NAME = push_swap

USER = $(shell whoami)
OS = $(shell uname)

COMPILER = cc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

SRC = getnextline42/get_next_line.c \
      getnextline42/get_next_line_utils.c \
      

OBJS_DIR = objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))


all: $(OBJS_DIR) MLX42 $(NAME)


$(NAME): $(OBJS)
	@make -C libft-42 --silent
	@make -C printf42 --silent


$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


clean:
	@rm -rf $(OBJS_DIR)
	@cd printf42 && make fclean && cd ..
	@cd libft-42 && make fclean && cd ..

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlxclean