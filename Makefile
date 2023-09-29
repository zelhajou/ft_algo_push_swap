# Compiler and compiler flags
CC := gcc 
CFLAGS := -Wall -Wextra -Werror

# Directories
SRC_DIR := src
INCDIR := include
BUILDDIR := build
LIBDIR := lib
TESTDIR := test
UTILSDIR := utils

# Source files
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# Libraries (if you have any)
LIBS := -lft_printf -lm  # Replace with actual libraries

# Executable name
EXEC := push_swap

# Targets and Phony Targets
.PHONY: all clean fclean re