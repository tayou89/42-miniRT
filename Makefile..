NAME = miniRT
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
COMMON_FILE = main
PARSING_FILE = parse_data \
			   parse_file parse_line \
			   classify_element_information \
			   ft_classify_non_object_info ft_classify_object_info \
			   get_element_data \
			   ft_get_non_object_data ft_get_object_data \
			   ft_get_data ft_make_object_node ft_add_object_node \
			   ft_parsing_util ft_check_range ft_get_number \
			   ft_parsing_error ft_parsing_free ft_free_object_list print_data

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
