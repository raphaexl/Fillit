# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 04:35:43 by ebatchas          #+#    #+#              #
#    Updated: 2018/11/22 21:31:04 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -L$(LIBDIR)/libft -lft

SRC=$(SRCDIR)/ft_fillit_valide.c\
	$(SRCDIR)/ft_tetriminos.c\
	$(SRCDIR)/ft_puzzle_solver.c\
	$(SRCDIR)/ft_utils.c\
	$(SRCDIR)/fillit.c\
	$(SRCDIR)/main.c

OBJ=$(LIBDIR)/ft_fillit_valide.o\
	$(LIBDIR)/ft_tetriminos.o\
	$(LIBDIR)/ft_puzzle_solver.o\
	$(LIBDIR)/ft_utils.o\
	$(LIBDIR)/fillit.o\
	$(LIBDIR)/main.o

NAME= fillit

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft/ 
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR)/libft fclean

re: fclean all

