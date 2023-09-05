# FLAGS
NAME = libminirt.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
RM = rm -rf

# PATH
SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/

# INC
INC = -I$(INC_PATH)

# FILES
SRC_FILES = utils_vec_calc_other.c \
			utils_vec_calc_s.c \
			utils_vec_calc_v.c \
			utils_vec.c \
			utils.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@test -d $(OBJ_PATH) || mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) $(OBJ_PATH)

fclean:
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
