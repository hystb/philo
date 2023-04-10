#---------------------------------------------------#
CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror #-fsanitize=thread -g3
NAME 		= philo
#---------------------------------------------------#
OBJ_DIR 	= obj/

SRCS		= \
main.c\
error.c\
game.c\
init.c\
utils.c\
control_death.c


OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES 	= /

HEADERS		= philo.h

#---------------------------------------------------#
all: 
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(INCLUDES) $(LIBFT_EXEC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

$(OBJ_DIR)/%.o : %.c Makefile $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all fclean fclean re
#---------------------------------------------------#
