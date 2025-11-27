all:	ft_printf
	./test_printf.sh

bonus:	ft_printf
	./test_printf.sh -DBONUS

extra:	ft_printf
	./test_printf.sh test_printf_pos.c 

ft_printf:
	make -C ..

clean:
	make -C .. clean

fclean:
	make -C .. fclean

re:		fclean all

.PHONY: all ft_printf bonus clean fclean all
