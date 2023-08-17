NAME = miniRT_library

all: $(NAME)

$(NAME):
	make -C libft
	make -C minilibx_mms_20210621
	make -C libminirt

bonus:
	make -C libft
	make -C minilibx_mms_20210621
	make bonus -C libminirt

clean:
	make clean -C libft
	make clean -C minilibx_mms_20210621
	make clean -C libminirt

fclean: clean

re:
	make fclean
	make all

.PHONY: $(NAME) all clean fclean re bonus
