NAME		= so_long
NAME_BONUS	= so_long_bonus

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Iminilibx-linux -Ilibft

SRCS		= src/main.c \
			  src/parse.c \
			  src/validate.c \
			  src/render.c \
			  src/player.c \
			  src/error.c \
			  src/free.c

SRCS_BONUS	= src/main_bonus.c \
			  src/parse_bonus.c \
			  src/validate_bonus.c \
			  src/render_bonus.c \
			  src/player_bonus.c \
			  src/physics_bonus.c \
			  src/error_bonus.c \
			  src/free_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

LIBFT		= libft/libft.a
LIBMLX		= minilibx-linux/libmlx_Linux.a

LDFLAGS		= -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

all: $(LIBMLX) $(LIBFT) $(NAME)

bonus: $(LIBMLX) $(LIBFT) $(NAME_BONUS)

$(LIBMLX):
	-make -C minilibx-linux
	@test -f $@ || (echo "Error: minilibx build failed" && exit 1)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(LDFLAGS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
