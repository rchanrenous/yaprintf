#!/usr/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

dir_lib_ft_printf=".."
lib_ft_printf="ftprintf"
include_ft_printf="../include"
include_libft="../libft"

dir_c_files="src/"
c_files="test_printf_c.c test_printf_s.c test_printf_p.c test_printf_d.c test_printf_u.c test_printf_x.c test_printf_upper_x.c"

if [ $# -eq 1 ] && [ $1 = '-DBONUS' ]
then
	BFLAG=$1
elif [ $# -eq 1 ] && [ $1 = 'test_printf_pos.c' ]
then
	c_files=$1
fi

for file in $c_files
do
	file=$dir_c_files$file
	echo ----------------------------------
	echo -e "$YELLOW $file $NC"
	exec_ft_printf="exec_ft_printf"
	exec_printf="exec_printf"
	cc -Wall -Wextra -Werror $file $BFLAG -L $dir_lib_ft_printf -l $lib_ft_printf -I $include_ft_printf -I $include_libft -o $exec_ft_printf
	cc -Wall -Wextra -Werror $file $BFLAG -DPRINTF -L $dir_lib_ft_printf -l $lib_ft_printf -I $include_ft_printf -I $include_libft -o $exec_printf
	output_ft_printf="output_ft_printf"
	output_printf="output_printf"
	res_ft_printf="res_ft_printf"
	res_printf="res_printf"
	./$exec_ft_printf $res_ft_printf > $output_ft_printf
	./$exec_printf $res_printf > $output_printf
	diff_file="diff_file"
	diff_res_file="diff_res_file"
	diff $output_ft_printf $output_printf > $diff_file
	diff $res_ft_printf $res_printf > $diff_res_file
	if [ -s $diff_file ]
	then
		echo -e "diff output: $RED KO $NC"
		cat $diff_file
	else
		echo -e "diff output: $GREEN OK $NC"
	fi
	if [ -s $diff_res_file ]
	then
		echo -e "diff res: $RED KO $NC"
		cat $diff_res_file
	else
		echo -e "diff res: $GREEN OK $NC"
	fi
	rm -rf $exec_ft_printf $exec_printf $res_ft_printf $res_printf $output_ft_printf $output_printf $diff_file $diff_res_file
done
