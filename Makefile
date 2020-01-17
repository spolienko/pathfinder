NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

INCLIB = libmx/libmx.a

SRC = \
	./main.c \
      ./mx_atoi.c \
      ./mx_count_path.c \
      ./mx_dup_path.c \
      ./mx_cmp_count.c \
      ./mx_first_line.c \
      ./mx_isdigit.c \
      ./mx_matrix.c \
      ./mx_pars_path.c \
      ./mx_print_error.c \
      ./mx_split_path.c \
      ./mx_sum_path.c \
      ./mx_uniq_path.c \
      ./mx_error_symbol.c \
      ./mx_pars_arr.c \
      ./mx_error_path.c \
      ./mx_isletter.c \
      ./mx_print_error_str.c \
      ./mx_check_num.c \
      ./mx_end_line.c \
      ./mx_mem_matrix.c \
      ./mx_matrix_path.c \
      ./mx_main_algo.c \
      ./mx_destroy_null.c \
      ./mx_backtrack.c \
      ./mx_all_routes.c \
      ./mx_mem_int_arr.c \
      ./mx_check_availability.c \
      ./mx_new_graph.c \
      ./mx_del_intarr.c \
      ./mx_error_handling_2.c \
      ./mx_error_handling_1.c

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INCLIB) $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(NAME) $(INCLIB)

clean:
	@rm -rf $(SRC) $(OBJ) $(INC)
	@rm -rf ./obj

reinstall: uninstall all
