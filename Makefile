NAME = pipex

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -g 

SRC = 


OBJS_DIR = objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))


all: $(OBJS_DIR) $(NAME)


$(NAME): $(OBJS)
	@make -C libft-42 --silent
	@make -C printf42 --silent
	@$(COMPILER) -o $(NAME) $(OBJS) $(CFLAGS) libft-42/libft.a printf42/libftprintf.a


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