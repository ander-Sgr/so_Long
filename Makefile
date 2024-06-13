NAME = so_long

SRCS = ./src/main.c  \
		./src/read_map.c \
		./src/draw_map.c  \
		./src/xpm_utils.c	\
		./src/map_validations.c \
		./src/element_pos.c \
		./src/check_pathfinder.c \
		./src/init_images.c \
		./src/init_vars.c \
		./src/event_keys.c \
		./src/clear_game.c \
		./src/init_game.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

HDRS = ./include/so_long.h \
       ./include/other_header.h \
       ./gnl/get_next_line.h \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

OBJS = ${SRCS:.c=.o}

GREEN = \033[0;32m
RESET = \033[0m

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I./include
else
	INCLUDES = -I/opt/x11/include -Imlx -I$(LIBFT_DIR) -I./include
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

.c.o: $(HDRS) Makefile
	@echo "$(GREEN)Compiling $< ...$(RESET)"
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking objects ...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) $(PRINTF_LIB)
	@echo "$(GREEN)Build complete: $(NAME)$(RESET)"

$(MLX_LIB):
	@echo "$(GREEN)Building mlx library ...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)mlx library built.$(RESET)"

$(LIBFT_LIB):
	@echo "$(GREEN)Building libft library ...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)libft library built.$(RESET)"

$(PRINTF_LIB):
	@echo "$(GREEN)Building ft_printf library ...$(RESET)"
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf libreary built.$(RESET)"

clean:
	@echo "$(GREEN)Cleaning object files ...$(RESET)"
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "$(GREEN)Object files cleaned.$(RESET)"

fclean: clean
	@echo "$(GREEN)Cleaning all ...$(RESET)"
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "$(GREEN)All cleaned.$(RESET)"

re: fclean all
	@echo "$(GREEN)Rebuilding ...$(RESET)"