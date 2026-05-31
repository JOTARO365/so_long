# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 01:45:46 by wiaon-in          #+#    #+#              #
#    Updated: 2025/08/31 14:43:56 by wiaon-in         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= 		libft.a

DOT		:= 		.c

FT		:= 		ft_

CC		:= 		cc

BONUS	:= 		_bonus

CFLAGS	:= 		-Wall -Werror -Wextra -g3

SRC		:=		isalpha isdigit isalnum isascii isprint \
				strlen memset bzero memcpy memcmp memmove strlcpy \
				strlcat toupper tolower strchr strrchr strncmp \
				memchr strnstr atoi calloc strdup substr \
				strjoin strtrim split itoa strmapi striteri putchar_fd \
				putstr_fd putendl_fd putnbr_fd

SRC_B	:=		lstnew lstadd_front lstadd_back lstsize lstlast lstdelone lstclear lstiter lstmap

SRC_PF	:=		printf printf_utils

GNL		:=		get_next_line.c get_next_line_utils.c

FILES	:=		$(addprefix $(FT), $(addsuffix $(DOT), $(SRC)))
FILES_B :=		$(addsuffix $(DOT), $(addprefix $(FT), $(addsuffix $(BONUS), $(SRC_B))))
FILES_PF :=		$(addprefix $(FT), $(addsuffix $(DOT), $(SRC_PF)))

OBJS	:=		$(FILES:.c=.o)
OBJS_B	:=		$(FILES_B:.c=.o)
OBJS_PF	:=		$(FILES_PF:.c=.o)
OBJS_GNL :=	$(GNL:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJS_PF) $(OBJS_GNL)
	ar rcs $@ $^

%.o:%.c 
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus:			$(OBJS) $(OBJS_B) $(OBJS_PF) $(OBJS_GNL)
	ar rcs $(NAME) $(OBJS) $(OBJS_B) $(OBJS_PF) $(OBJS_GNL)

clean:
	rm -rf $(OBJS) $(OBJS_B) $(OBJS_PF) $(OBJS_GNL)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all

create:
	@echo ======================== CREATE SOURCE ============================== 
	@echo $(FILES)
	@echo ===================== CREATE SOURCE BONUS =========================== 
	@echo $(FILES_B)
	
.PHONY: all clean fclean re bonus
