# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 17:21:32 by zelhajou          #+#    #+#              #
#    Updated: 2023/10/29 12:37:58 by zelhajou         ###   ########.fr        #
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
SRCS = \
	$(SRCDIR)/push_swap.c \
	$(SRCDIR)/operations/push/ft_pa.c \
	$(SRCDIR)/operations/push/ft_pb.c \
	$(SRCDIR)/operations/reverse/ft_reverse_rotate.c \
	$(SRCDIR)/operations/reverse/ft_rra.c \
	$(SRCDIR)/operations/reverse/ft_rrb.c \
	$(SRCDIR)/operations/reverse/ft_rrr.c \
	$(SRCDIR)/operations/rotate/ft_ra.c \
	$(SRCDIR)/operations/rotate/ft_rb.c \
	$(SRCDIR)/operations/rotate/ft_rotate.c \
	$(SRCDIR)/operations/rotate/ft_rr.c \
	$(SRCDIR)/operations/swap/ft_sa.c \
	$(SRCDIR)/operations/swap/ft_sb.c \
	$(SRCDIR)/operations/swap/ft_ss.c \
	$(SRCDIR)/operations/swap/ft_swap.c \
	$(SRCDIR)/parsing/ft_parse_args.c \
	$(SRCDIR)/sorting/ft_sort.c \
	$(UTILSDIR)/ft_sort_utils.c \
	$(UTILSDIR)/utils.c \
	$(UTILSDIR)/ft_parse_args_utils.c

# Object files
OBJ = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

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

$(OBJDIR)/%.o: $(UTILSDIR)/%.c
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