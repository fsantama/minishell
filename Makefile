# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 10:02:17 by fsantama          #+#    #+#              #
#    Updated: 2024/02/05 10:25:32 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

# PROGRAM FOR COMPILING C PROGRAMS
CC 		=	gcc
# C COMPILER FLAGS
CFLAGS =	-Werror -Wall -Wextra

NAME 	=	minishell
LIBFT 	=	./inc/Libft/libft.a


# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRCS	=	src/minishell.c \
			src/utils/general_utils/ft_error.c \
			src/utils/manage_array_utils/ft_arraydup.c \
			src/utils/manage_array_utils/ft_arrayfree.c \
			src/utils/manage_array_utils/ft_arraylen.c \
			src/utils/manage_array_utils/ft_printarray.c \
			src/utils/parser_utils/ft_getpath.c \
			src/utils/pipe_utils/ft_initpipex.c \
			src/utils/readline_utils/ft_getline.c \
			
			
OBJS	=	$(SRCS:.c=.o)

# =============================================================================#
#                                  RULES                                       #  
# =============================================================================#


all : $(NAME) $(LIBFT)

$(LIBFT) : 
	@make  -C inc/Libft > /dev/null

$(NAME) : $(LIBFT) $(OBJS)
	@echo "$(CYAN) ======================================================="
	@echo "| 	           _       _     _          _ _ 	|"
	@echo "| 	 _ __ ___ (_)_ __ (_)___| |__   ___| | |	|"
	@echo "| 	|  _   _ \| |  _ \| / __|  _ \ / _ \ | |	|"
	@echo "| 	| | | | | | | | | | \__ \ | | |  __/ | |	|"
	@echo "| 	|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|	|"
	@echo "|                                          		|"
	@echo " ======================================================="
	@echo " ========== Develop by ajurado- && fsantama ============"
	@echo " ======================================================="
	@echo "                                                       $(DEFAULT)"
	@echo "$(GREEN) $(NAME) make done ✅ $(DEFAULT)"
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) -L"/Users/$(USER)/.brew/opt/readline/lib/" -o $(NAME) -lreadline

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@make -C inc/Libft clean > /dev/null
	@echo "$(RED) $(NAME) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) objects clean done 🧹 $(DEFAULT)"

fclean : clean
	@rm -f $(NAME)
	@make -C inc/Libft fclean > /dev/null
	@echo "$(RED) $(NAME) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) clean done 🧹 $(DEFAULT)"

re: fclean all

#bonus : $(NAME_BONUS)

# PERSONAL USE

git:
	git add *
	git commit -m "Some changes made"
	git push
	git ls-files

# =============================================================================#
#                                 COLORS                                       #
# =============================================================================#

BOLD	:=	\033[1m
BLACK	:=	\033[30;1m
RED		:=	\033[31;1m
GREEN	:=	\033[32;1m
YELLOW	:=	\033[33;1m
BLUE	:=	\033[34;1m
MAGENTA	:=	\033[35;1m
CYAN	:=	\033[36;1m
WHITE	:=	\033[37;1m
DEFAULT	:=	\033[0m

.PHONY: all clean fclean re