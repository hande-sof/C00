#!/bin/bash

testname=test_c00_main

if [[ $1 == "" ]] || [[ $1 == "n" ]]
then
	find . -name "ft_*.c" -print | xargs norminette -R CheckForbiddenSourceHeader | sed -E "s/(Warn|Err)(.*)(.)$/    \1\2\3/g" | sed 's/Norme:/^Norme:/' | tr '^' '\n'
fi


if [[ $1 == "" ]] || [[ $1 == "c" ]]
then

	sources="ex00/ft_putchar.c ex01/ft_print_alphabet.c ex02/ft_print_reverse_alphabet.c ex03/ft_print_numbers.c ex04/ft_is_negative.c ex05/ft_print_comb.c ex06/ft_print_comb2.c ex07/ft_putnbr.c ex08/ft_print_combn.c"

	flags="-Wall -Wextra -Werror"

	gcc ${flags} -o ${testname} ${testname}.c ${sources}
	./${testname}
	rm ${testname}

fi
