# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 17:21:32 by zelhajou          #+#    #+#              #
#    Updated: 2023/11/02 19:39:21 by zelhajou         ###   ########.fr        #
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
TESTDIR = ./test
LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/ft_printf

# Source files
SRCS = \
	$(SRCDIR)/push_swap.c \
	$(SRCDIR)/operations/push/ft_push.c \
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
	$(UTILSDIR)/sorting/ft_sort_utils.c \
	$(UTILSDIR)/sorting/ft_sort_utils2.c \
	$(UTILSDIR)/sorting/ft_sort_algo.c \
	$(UTILSDIR)/utils.c \
	$(UTILSDIR)/parsing/ft_parse_args_utils.c

CHECKER_SRCS = \
    $(TESTDIR)/checker.c \
    $(TESTDIR)/get_next_line.c \
    $(TESTDIR)/get_next_line_utils.c \
    $(TESTDIR)/checker_utils.c \
	$(SRCDIR)/operations/push/ft_push.c \
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
	$(UTILSDIR)/sorting/ft_sort_utils.c \
	$(UTILSDIR)/sorting/ft_sort_utils2.c \
	$(UTILSDIR)/sorting/ft_sort_algo.c \
	$(UTILSDIR)/utils.c \
	$(UTILSDIR)/parsing/ft_parse_args_utils.c

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
PRINTF = $(PRINTFDIR)/libftprintf.a

# Object files
OBJ = $(SRCS:%.c=$(OBJDIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRCS:%.c=$(OBJDIR)/%.o)

# Executable
TARGET = push_swap
CHECKER_TARGET = checker

all: $(TARGET)

$(TARGET): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(INCLUDES) -o $@

$(CHECKER_TARGET): $(LIBFT) $(PRINTF) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) $(PRINTF) $(INCLUDES) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(PRINTF):
	make -C $(PRINTFDIR)

bonus: $(CHECKER_TARGET)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean

fclean: clean
	rm -f $(TARGET)
	rm -f $(CHECKER_TARGET)
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re