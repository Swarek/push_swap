NAME = push_swap
BONUS_NAME = checker

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SOURCES := $(filter-out %_bonus.c, $(wildcard $(SRC_DIR)/**/*.c)) main.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS := $(OBJECTS:main.c=$(OBJ_DIR)/main.o)

BONUS_SOURCES := $(filter-out main.c, $(wildcard $(SRC_DIR)/**/*.c)) $(wildcard $(SRC_DIR)/**/_bonus.c)
BONUS_OBJECTS = $(BONUS_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -fPIC -I$(INC_DIR) -I$(LIBFT_DIR)/includes
LINKS = -L$(LIBFT_DIR) -lft

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@gcc $(OBJECTS) -o $(NAME) $(FLAGS) $(LINKS)

bonus: $(LIBFT) $(BONUS_OBJECTS)
	@gcc $(BONUS_OBJECTS) -o $(BONUS_NAME) $(FLAGS) $(LINKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@find $(OBJ_DIR) -type f -name '*.o' -delete
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f $(OBJ_DIR)/*.o
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

bonus_re: fclean bonus

debug: FLAGS += -g
debug: re
