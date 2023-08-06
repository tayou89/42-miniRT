NAME = miniRT
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
COMMON_FILE = main
PARSING_FILE = parse_data \
			   ft_parsing_error

COMMON_SRC = $(addprefix ./common/, $(addsuffix .c, $(COMMON_FILE)))
PARSING_SRC = $(addprefix ./parsing/, $(addsuffix .c, $(PARSING_FILE)))
COMMON_OBJ = $(addprefix ./common/, $(addsuffix .o, $(COMMON_FILE)))
PARSING_OBJ = $(addprefix ./parsing/, $(addsuffix .o, $(PARSING_FILE)))

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(COMMON_OBJ) $(PARSING_OBJ)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(COMMON_OBJ) $(PARSING_OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $^

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY : all clean fclean re libft
