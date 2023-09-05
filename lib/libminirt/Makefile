# FLAGS
NAME = libminirt.a
BONUS_NAME = libminirt_bonus.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
RM = rm -rf

# PATH
SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/
BONUS_SRC_PATH = src_bonus/
BONUS_INC_PATH = inc_bonus/

# INC
INC = -I$(INC_PATH)
BONUS_INC = -I$(BONUS_INC_PATH)

# FILES
SRC_FILES = utils_vec_calc_other.c \
			utils_vec_calc_s.c \
			utils_vec_calc_v.c \
			utils_vec.c \
			utils.c

BONUS_SRC_FILES = $(SRC_FILES:.c=_bonus.c)

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))
BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC_FILES))
BONUS_OBJS = $(addprefix $(OBJ_PATH), $(BONUS_SRC_FILES:.c=.o))

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@test -d $(OBJ_PATH) || mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJ_PATH)%.o: $(BONUS_SRC_PATH)%.c
	@test -d $(OBJ_PATH) || mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(BONUS_INC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(BONUS_NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJ_PATH)

fclean:
	$(RM) $(NAME) $(BONUS_NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
