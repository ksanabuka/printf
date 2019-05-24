#include "ft_printf.h"


int main(int ac, char **av)
{
    ac = 0;
    av = 0;


//ft_printf("19%#.x, %#.0x|\n", 0, 0);


ft_printf("1%x|\n", 42);
ft_printf("2before %x after|\n", 42);
ft_printf("3%x, %x|\n", 0, 4294967295);
ft_printf("4{%030x}\n", 0xFFFF);
ft_printf("5{%030X}\n", 0xFFFF);
ft_printf("6%#x|\n", 42);
ft_printf("7%#X|\n", 42);
ft_printf("8%#x|\n", 0);
ft_printf("9%#x|\n", 2147483647);
ft_printf("10%.4x|\n", 42);
ft_printf("11%.4x|\n", 424242);
ft_printf("12%15.4x|\n", 42);
ft_printf("13%15.4x|\n", 424242);
ft_printf("14%8.4x|\n", 424242424);
ft_printf("15%4.15x|\n", 42);
ft_printf("16%4.15x|\n", 42424242);
ft_printf("17%4.8x|\n", 424242424);
ft_printf("18%.x, %.0x|\n", 0, 0);
ft_printf("19%#.x, %#.0x|\n", 0, 0);
ft_printf("20{%#.5x}|\n", 1);
ft_printf("21% x|%+x|\n", 42, 42);
 


// ft_printf("%o|\n", 42);
// ft_printf("before %o after|\n", 42);
// ft_printf("%#o|\n", 42);
// ft_printf("%#o|\n", 0);
// ft_printf("%#o|\n", 2147483647);
// ft_printf("%+o|\n", 0);
// ft_printf("%+o|\n", 42);
// ft_printf("%.4o|\n", 42);
// ft_printf("%.4o|\n", 424242);
// ft_printf("%15.4o|\n", 42);
// ft_printf("%15.4o|\n", 424242);
// ft_printf("%8.4o|\n", 424242424);
// ft_printf("%4.15o|\n", 42);
// ft_printf("%4.15o|\n", 424242);
// ft_printf("%4.8o|\n", 424242424);
// ft_printf("1%.o, %.0o|", 0, 0);
// //ft_printf("2%.o, %.0O|", 0, 0);
// ft_printf("3%#.o, %#.0o|\n", 0, 0);
// ft_printf("%#.3o|\n", 1);
// ft_printf("%o|\n", -42);
// ft_printf("%o|\n", 2147483647);
// ft_printf("% o|%+o|\n", 42, 42);
// ft_printf("%#.o|\n", 42);


// ft_printf("\nPASSED\n");

// ft_printf("%+d", 42);
// ft_printf("%+d", -42);
// ft_printf("% d", 9999);
// ft_printf("% d", -9999);
// ft_printf("{% +d}", 42);
// ft_printf("{%+ d}\n", 42);
// ft_printf("{%+03d}", 0);
// ft_printf("{% 03d}", 0);
// ft_printf("{%0-3d}\n", 0);
// ft_printf("{%+03d}", 12);
// ft_printf("{%+03d}", 123456);
// ft_printf("{%03.2d}", 0);
//   ft_printf("%.4d|\n", 42);
//   ft_printf("%.4d|\n", 424242);
//   ft_printf("%.4d|\n", -424242);
//   ft_printf("%15.4d|\n", 42);
//    ft_printf("%15.4d|\n", 424242);
// ft_printf("%8.4d|\n", 424242424);
// ft_printf("%15.4d|\n", -42);
// ft_printf("%15.4d|\n", -424242);
// ft_printf("%8.4d|\n", -424242424);
// ft_printf("%4.15d|\n", 42);
// ft_printf("%4.15d|\n", 424242);
// ft_printf("%4.8d|\n", 424242424);
// ft_printf("%4.15d|\n", -42);
// ft_printf("%4.15d|\n", -424242);
// ft_printf("%4.8d|\n", -424242424);
// ft_printf("%.d, %15.0d|\n", 0, 0);
// ft_printf("%.10d|\n", -42);


    return 0;
    // t_arg * head_arg = 0;
    // ac = 0;

    // int status = parseStr(av[1], &head_arg);
    
    

    
    // printf("\n%d\n", status);

    // //intptr_t d = -123456789;
    
    // char * str =  d_repr(head_arg->chunk_params, (void*) d);
    // printf("%s\n", str); 

    // //+000000123456789    %
    // return 0;
}
