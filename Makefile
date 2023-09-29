# Binary target
BINARY_NAME	 = ft_printf
BINARY_SOURCES  = $(shell echo srcs/exam.c)
BINARY_OBJECTS  = $(addprefix objects/,$(notdir $(BINARY_SOURCES:.c=.o)))

# Library target
LIB_NAME		= libftprintf.a
LIB_SRCS		= $(shell echo srcs/exam.c)
LIB_OBJS		= $(LIB_SRCS:.c=.o)

# Compiler and flags
CC			  = gcc
CFLAGS		  = -Wall -Wextra -Werror

# --- COLORS ---

NONE=\033[0m
GRAY=\033[2;37m
RED=\033[31m
GREEN=\033[32m

# --- RULES ---

all: library

binary: $(BINARY_NAME)

$(BINARY_NAME): $(BINARY_OBJECTS)
	@echo  "$(GRAY)----Compiling $(BINARY_NAME)----$(NONE)"
	$(CC) $(CFLAGS) -o $@ $(BINARY_OBJECTS)
	@echo "$(GREEN)$(BINARY_NAME) Compiled! ᕦ(♥_♥)ᕤ$(NONE)\n"

objects/%.o: srcs/%.c | objects
	$(CC) -c $< -o $@

library: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $@ $(LIB_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Common rules
clean:
	@echo "$(GREEN)Deleting objects! ( ͡° ͜ʖ ͡°) $(NONE)"
	rm -f $(BINARY_OBJECTS) $(LIB_OBJS)

fclean: clean
	@echo "$(RED)Deleting everything! ( ͡° ͜ʖ ͡°) $(NONE)"
	rm -f $(BINARY_NAME) $(LIB_NAME)

re: fclean binary library

.PHONY: binary library clean fclean re