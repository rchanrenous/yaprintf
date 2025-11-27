all: ft_printf
	./test_printf.sh

bonus: ft_printf
	./test_printf.sh -DBONUS

extra: ft_printf
	./test_printf.sh test_printf_pos.c 

ft_printf:
	make -C ..

.PHONY: all ft_printf bonus
