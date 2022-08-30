# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nveerara <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 10:56:07 by nveerara          #+#    #+#              #
#    Updated: 2022/08/30 20:21:17 by nveerara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SRCS	=	BSQ.c \
			bm_check.c \
			bml_add_empty.c \
			read_bsq_lines.c \
			read_file.c \
			read_first_line.c \
			reduce.c \
			pointer_ft.c \
			init.c \
			error.c	\
			write_bsq.c \
			prep_first_line.c \
			read_stdin.c

INC		=	includes/

OBJS	=	$(SRCS:.c=.o)			

CC	=	gcc $(CFLAGS) -I $(INC)

CFLAGS	= -Wall -Wextra -Werror		

RM	=	rm -f				

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)	

clean	:
		$(RM) $(OBJS)				
		$(CLEAN)				 

fclean	:	clean					
		$(RM) $(NAME)				

re		:	fclean all

all		:$(NAME)
