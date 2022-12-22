
Link main.c with libftprintf.a  and output to main

compile main:
gcc main.c libftprintf.a -o main & ./main

compile lldb debug
gcc -g main.c ft_printf.c ft_printf_utils.c ft_printf_functions.c libftprintf.a -o debug
lldb debug
b 'function name'
r
gui