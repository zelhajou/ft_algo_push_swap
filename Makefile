# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft
FT_PRINTFDIR = lib/ft_printf

# Executable name
NAME = push_swap

# Source files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

# Includes
INCLUDES = -I$(INCDIR) -I$(LIBFTDIR) -I$(FT_PRINTFDIR)

# Build rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTFDIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_PRINTFDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re