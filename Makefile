# FLAGS
NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# PATH
SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/
PARSING_PATH = parsing/
VIEWPORT_PATH = viewport/
RAY_TRACING_PATH = ray_tracing/
BONUS_SRC_PATH = src_bonus/
BONUS_INC_PATH = inc_bonus/

# LIB PATH
LIB_PATH = lib/
LIBFT_PATH = $(LIB_PATH)libft/
LIBRT_PATH = $(LIB_PATH)libminirt/
MLX_PATH = $(LIB_PATH)minilibx_mms_20210621/
BONUS_LIBRT_PATH = $(LIB_PATH)librt_bonus/

# INC
INC = -I$(INC_PATH)
INC_LIBFT = -I$(LIBFT_PATH)$(INC_PATH)
INC_LIBRT = -I$(LIBRT_PATH)$(INC_PATH)
INC_MLX = -I$(MLX_PATH)
BONUS_INC = -I$(BONUS_INC_PATH)
BONUS_INC_LIBRT = -I$(BONUS_LIBRT_PATH)

INC_ALL = $(INC) $(INC_LIBFT) $(INC_LIBRT) $(INC_MLX)
BONUS_INC_ALL = $(BONUS_INC) $(INC_LIBFT) $(BONUS_INC_LIBRT) $(INC_MLX)

# LINK
LINK_MLX = -lmlx -L$(MLX_PATH)
LINK_LIBFT = -lft -L$(LIBFT_PATH)
LINK_LIBRT = -lminirt -L$(LIBRT_PATH)
BONUS_LINK_LIBRT = -lrt -L$(BONUS_LIBRT_PATH)

LINK = $(LINK_LIBFT) $(LINK_MLX) $(LINK_LIBRT)
BONUS_LINK = $(LINK_LIBFT) $(BONUS_LINK_LIBRT) $(LINK_MLX)

PARSING_FILE_NAME = parse_data \
					parse_file parse_line \
					classify_element_information \
					ft_classify_non_object_info ft_classify_object_info \
					get_element_data \
					ft_get_non_object_data ft_get_object_data \
					ft_get_data ft_make_object_node ft_add_object_node \
					ft_parsing_util ft_get_number \
					ft_parsing_error ft_parsing_free print_data

VIEWPORT_FILE_NAME = get_viewport_data \
					 get_viewport_scala \
					 get_viewport_vector \
					 get_viewport_point

RAY_TRACING_FILE_NAME = draw_image_by_ray_tracing \
						ray 

PARSING_FILES = $(addprefix parsing/, $(addsuffix .c, $(PARSING_FILE_NAME)))
VIEWPORT_FILES = $(addprefix viewport/, $(addsuffix .c, $(VIEWPORT_FILE_NAME)))
RAY_TRACING_FILES = $(addprefix ray_tracing/, $(addsuffix .c, $(RAY_TRACING_FILE_NAME)))

# FILES
SRC_FILES = main.c \
			color.c \
			hook.c \
			image.c \
			initialize.c \
			$(PARSING_FILES) $(VIEWPORT_FILES) $(RAY_TRACING_FILES)

BONUS_SRC_FILES = $(SRC_FILES:.c=_bonus.c)

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))
BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC_FILES))
BONUS_OBJS = $(addprefix $(OBJ_PATH), $(BONUS_SRC_FILES:.c=.o))

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@test -d $(OBJ_PATH) || mkdir -p $(OBJ_PATH)
	@test -d $(OBJ_PATH)$(PARSING_PATH) || mkdir -p $(OBJ_PATH)$(PARSING_PATH)
	@test -d $(OBJ_PATH)$(VIEWPORT_PATH) || mkdir -p $(OBJ_PATH)$(VIEWPORT_PATH)
	@test -d $(OBJ_PATH)$(RAY_TRACING_PATH) || mkdir -p $(OBJ_PATH)$(RAY_TRACING_PATH)
	$(CC) $(CFLAGS) $(INC_ALL) -c -o $@ $<

$(OBJ_PATH)%.o : $(BONUS_SRC_PATH)%.c
	@test -d $(OBJ_PATH) || mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(BONUS_INC_ALL) -c -o $@ $<

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	@install_name_tool -id $(MLX_PATH)libmlx.dylib $(MLX_PATH)libmlx.dylib
	@make make_mandatory

bonus:
	make bonus -C $(LIB_PATH)
	@install_name_tool -id $(MLX_PATH)libmlx.dylib $(MLX_PATH)libmlx.dylib
	@make make_bonus

make_mandatory: $(OBJS)
	$(CC) $(CFLAGS) $(LINK) -o $(NAME) $(OBJS)
	touch $@

make_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_LINK) -o $(NAME) $(BONUS_OBJS)
	touch $@

clean:
	make clean -C $(LIB_PATH)
	$(RM) $(OBJ_PATH)
	$(RM) make_mandatory
	$(RM) make_bonus

fclean: clean
	make fclean -C $(LIB_PATH)
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: $(NAME) all clean fclean re bonus
