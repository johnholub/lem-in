NAME = lem-in

SRC = check_order.c\
      first_validation.c\
      main.c\
      read_file.c\
      litle_func.c\
      check_comand.c\
      check_room.c\
      err_man.c\
      get_info.c\
      node_info.c\
      init_link.c\
      put_info.c\
      find_ways.c\
      find_info.c\
      from_end.c\
      cr_traf.c\
      build_tr.c\


OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT =	ft_printf/libftprintf.a

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(LIBFT):
		make -C ./ft_printf/

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
		rm -rf $(OBJDIR)
		make clean -C ./ft_printf/

fclean: clean
		rm -f $(NAME)
		make fclean -C ./ft_printf/

re: fclean all
