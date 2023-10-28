# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 17:21:32 by zelhajou          #+#    #+#              #
#    Updated: 2023/10/28 20:53:50 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./lib/libft -I./lib/ft_printf

# Directories
SRCDIR = ./src
UTILSDIR = ./utils
OBJDIR = ./bin
LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/ft_printf

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)
SRCS += $(wildcard $(SRCDIR)/operations/*/*.c)
SRCS += $(wildcard $(SRCDIR)/sorting/*.c)
SRCS += $(wildcard $(SRCDIR)/parsing/*.c)
SRCS += $(wildcard $(UTILSDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
PRINTF = $(PRINTFDIR)/libftprintf.a

# Executable
TARGET = push_swap

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFTDIR)

$(PRINTF):
	make -C $(PRINTFDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re
