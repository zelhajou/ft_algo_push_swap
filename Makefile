# Compiler and compiler flags
CC := gcc 
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -Iinclude

# Libraries
LIBS := -lft_printf

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
INC_DIR := include
LIB_DIR := lib
UTILS_DIR := utils
TEST_DIR := test

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Executable name
EXECUTABLE := $(BIN_DIR)/push_swap

# Test files
TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_EXECUTABLES := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRC_FILES))


# Targets and Phony Targets
.PHONY: all clean fclean re

# Default target
all: $(EXECUTABLE)

test: $(TEST_EXECUTABLES)

# Build executable
$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(OBJ_FILES) $(LIBS)

# Clean generated files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Clean everything, including the executable
fclean: clean
	rm -f $(EXEC)

# Rebuild everything
re: fclean all

