SRCS = fractol.c initiation.c maths_utils.c render.c events.c
SRCS_BONUS = fractol_bonus.c initiation_bonus.c maths_utils_bonus.c render_bonus.c events_bonus.c
OBJS = ${SRCS:%.c=%.o}
OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}
FLAGS = -Wall -Wextra -Werror
CC = gcc -g
RM = rm -f
NAME = fractol
NAME_BONUS = fractol_bonus
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

bonus:		$(OBJS_BONUS) $(LIBFT) $(MLX)
			$(CC) $(FLAGS)  $(OBJS_BONUS) $(MLX) $(LIBFT) -o $(NAME_BONUS) -lXext -lX11 -lm

$(LIBFT):
			$(MAKE) -C ./libft

$(MLX):
			$(MAKE) -C ./minilibx-linux

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(FLAGS)  $(OBJS) $(MLX) $(LIBFT) -o $(NAME) -lXext -lX11 -lm

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)
			$(RM) $(NAME_BONUS)

re:			fclean all
			
