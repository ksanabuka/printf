//
//  main.c
//  printf
//
//  Created by Oksana Buksha on 6/8/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include <stdio.h>
#include "Parser.h"
#include <limits.h>


int main(int argc, const char * argv[]) {
    ft_printf("1%x|\n", 42);
    printf("1%x|\n\n", 42);

    ft_printf("2before %x after|\n", 42);
    printf("2before %x after|\n\n", 42);

    ft_printf("3%x, %x|\n", 0, 4294967295u);
    printf("3%x, %x|\n\n", 0, 4294967295u);

    ft_printf("3%x, %o|\n", 0, 4294967295u);
    printf("3%x, %o|\n\n", 0, 4294967295u);

    ft_printf("4{%030x}\n", 0xFFFF);
    printf("4{%030x}\n\n", 0xFFFF);

    ft_printf("5{%030X}\n", 0xFFFF);
    printf("5{%030X}\n\n", 0xFFFF);

    ft_printf("6%#x|\n", 42);
    printf("6%#x|\n\n", 42);

    ft_printf("7%#X|\n", 42);
    printf("7%#X|\n\n", 42);

    ft_printf("8%#x|\n", 0);
    printf("8%#x|\n\n", 0);

    ft_printf("9%#x|\n", 2147483647);
    printf("9%#x|\n\n", 2147483647);

    ft_printf("10%.4x|\n", 42);
    printf("10%.4x|\n\n", 42);

    ft_printf("11%.4x|\n", 424242);
    printf("11%.4x|\n\n", 424242);

    ft_printf("12%15.4x|\n", 42);
    printf("12%15.4x|\n\n", 42);

    ft_printf("13%15.4x|\n", 424242);
    printf("13%15.4x|\n\n", 424242);

    ft_printf("14%8.4x|\n", 424242424);
    printf("14%8.4x|\n\n", 424242424);

    ft_printf("15%4.15x|\n", 42);
    printf("15%4.15x|\n\n", 42);

    ft_printf("16%4.15x|\n", 42424242);
    printf("16%4.15x|\n\n", 42424242);

    ft_printf("17%4.8x|\n", 424242424);
    printf("17%4.8x|\n\n", 424242424);

    ft_printf("18%.x, %.0x|\n", 0, 0);
    printf("18%.x, %.0x|\n\n", 0, 0);

    ft_printf("19%#.x, %#.0x|\n", 0, 0);
    printf("19%#.x, %#.0x|\n\n", 0, 0);

    ft_printf("20{%#.5x}|\n", 1);
    printf("20{%#.5x}|\n\n", 1);

    ft_printf("21% x|%+x|\n", 42, 42);
    printf("21% x|%+x|\n\n", 42, 42);


    ft_printf("%o|\n", 42);
    printf("%o|\n\n", 42);

    ft_printf("before %o after|\n", 42);
    printf("before %o after|\n\n", 42);

    ft_printf("%#o|\n", 42);
    printf("%#o|\n\n", 42);

    ft_printf("%#o|\n", 0);
    printf("%#o|\n\n", 0);

    ft_printf("%#o|\n", 2147483647);
    printf("%#o|\n\n", 2147483647);

    ft_printf("%+o|\n", 0);
    printf("%+o|\n\n", 0);

    ft_printf("%+o|\n", 42);
    printf("%+o|\n\n", 42);

    ft_printf("%.4o|\n", 42);
    printf("%.4o|\n\n", 42);

    ft_printf("%.4o|\n", 424242);
    printf("%.4o|\n\n", 424242);

    ft_printf("%15.4o|\n", 42);
    printf("%15.4o|\n\n", 42);

    ft_printf("%15.4o|\n", 424242);
    printf("%15.4o|\n\n", 424242);

    ft_printf("%8.4o|\n", 424242424);
    printf("%8.4o|\n\n", 424242424);

    ft_printf("%4.15o|\n", 42);
    printf("%4.15o|\n\n", 42);

    ft_printf("%4.15o|\n", 424242);
    printf("%4.15o|\n\n", 424242);

    ft_printf("%4.8o|\n", 424242424);
    printf("%4.8o|\n\n", 424242424);

    ft_printf("1%.o, %.0o|\n", 0, 0);
    printf("1%.o, %.0o|\n\n", 0, 0);

    ft_printf("2%.o, %.0O|\n", 0, 0);
    printf("2%.o, %.0O|\n\n", 0, 0);

    ft_printf("3%#.o, %#.0o|\n", 0, 0);
    printf("3%#.o, %#.0o|\n\n", 0, 0);

    ft_printf("%#.3o|\n", 1);
    printf("%#.3o|\n\n", 1);

    ft_printf("%o|\n", -42);
    printf("%o|\n\n", -42);

    ft_printf("%o|\n", 2147483647);
    printf("%o|\n\n", 2147483647);

    ft_printf("% o|%+o|\n", 42, 42);
    printf("% o|%+o|\n\n", 42, 42);

    ft_printf("%#.o|\n", 42);
    printf("%#.o|\n\n", 42);


    ft_printf("\nPASSED\n");

    ft_printf("{%  03d}\n", 0);
    printf("{%  03d}\n\n", 0);
    
    ft_printf("{%  03d}\n", 5);
    printf("{%  03d}\n\n", 5);
    
    ft_printf("%+d\n", 42);
    printf("%+d\n\n", 42);
    
    ft_printf("%+d\n", -42);
    printf("%+d\n\n", -42);
    
    ft_printf("% d\n", 9999);
    printf("% d\n\n", 9999);
    
    ft_printf("% d\n", -9999);
    printf("% d\n\n", -9999);
    
    ft_printf("{% +d}\n", 42);
    printf("{% +d}\n\n", 42);
    
    ft_printf("{%+ d}\n", 42);
    printf("{%+ d}\n\n", 42);
    
    ft_printf("{%+03d}\n", 0);
    printf("{%+03d}\n\n", 0);
    
    ft_printf("{% 03d}\n", 0);
    printf("{% 03d}\n\n", 0);
    
    ft_printf("{%0-3d}\n", 0);
    printf("{%0-3d}\n\n", 0);
    
    ft_printf("{%+03d}\n", 12);
    printf("{%+03d}\n\n", 12);
    
    ft_printf("{%+03d}\n", 123456);
    printf("{%+03d}\n\n", 123456);
    
    ft_printf("{%03.2d}\n", 0);
    printf("{%03.2d}\n\n", 0);
    
    ft_printf("%.4d|\n", 42);
    printf("%.4d|\n\n", 42);
    
    ft_printf("%.4d|\n", 424242);
    printf("%.4d|\n\n", 424242);
    
    ft_printf("%.4d|\n", -424242);
    printf("%.4d|\n\n", -424242);
    
    ft_printf("%15.4d|\n", 42);
    printf("%15.4d|\n\n", 42);
    
    ft_printf("%15.4d|\n", 424242);
    printf("%15.4d|\n\n", 424242);
    
    ft_printf("%8.4d|\n", 424242424);
    printf("%8.4d|\n\n", 424242424);
    
    ft_printf("%15.4d|\n", -42);
    printf("%15.4d|\n\n", -42);
    
    ft_printf("%15.4d|\n", -424242);
    printf("%15.4d|\n\n", -424242);
    
    ft_printf("%8.4d|\n", -424242424);
    printf("%8.4d|\n\n", -424242424);
    
    ft_printf("%4.15d|\n", 42);
    printf("%4.15d|\n\n", 42);
    
    ft_printf("%4.15d|\n", 424242);
    printf("%4.15d|\n\n", 424242);
    
    ft_printf("%4.8d|\n", 424242424);
    printf("%4.8d|\n\n", 424242424);
    
    ft_printf("%4.15d|\n", -42);
    printf("%4.15d|\n\n", -42);
    
    ft_printf("%4.15d|\n", -424242);
    printf("%4.15d|\n\n", -424242);
    
    ft_printf("%4.8d|\n", -424242424);
    printf("%4.8d|\n\n", -424242424);
    
    ft_printf("%.d, %15.0d|\n", 0, 0);
    printf("%.d, %15.0d|\n\n", 0, 0);
    
    ft_printf("%.10d|\n", -42);
    printf("%.10d|\n\n", -42);
    
    ft_printf("%ld%ld\n", 0, 42);
    printf("%ld%ld\n\n", 0, 42);
    
    ft_printf("%ld\n", (long)INT_MAX + 1);
    printf("%ld\n\n", (long)INT_MAX + 1);
    
    ft_printf("%ld\n", (long)INT_MIN - 1);
    printf("%ld\n\n", (long)INT_MIN - 1);
    
    ft_printf("%ld\n", LONG_MAX);
    printf("%ld\n\n", LONG_MAX);
    
    ft_printf("%ld\n", LONG_MIN);
    printf("%ld\n\n", LONG_MIN);
    
    ft_printf("%lld\n", LLONG_MAX);
    printf("%lld\n\n", LLONG_MAX);
    
    ft_printf("%lld\n", LLONG_MIN);
    printf("%lld\n\n", LLONG_MIN);
    
    ft_printf("%hd%hd\n", (short int)0, (short int)42);
    printf("%hd%hd\n\n", (short int)0, (short int)42);
    
    ft_printf("%hd\n", SHRT_MAX);
    printf("%hd\n\n", SHRT_MAX);
    
    ft_printf("%hd\n", SHRT_MIN);
    printf("%hd\n\n", SHRT_MIN);
    
    ft_printf("%hhd%hhdv\n", 1, 42);
    printf("%hhd%hhdv\n\n", 1, 42);
    
    ft_printf("%hhd\n", CHAR_MAX);
    printf("%hhd\n\n", CHAR_MAX);
    
    ft_printf("%hhd\n", CHAR_MAX + 42);
    printf("%hhd\n\n", CHAR_MAX + 42);
    
    ft_printf("%hhd\n", CHAR_MIN);
    printf("%hhd\n\n", CHAR_MIN);
    
    ft_printf("%hhd\n", CHAR_MIN - 42);
    printf("%hhd\n\n", CHAR_MIN - 42);
    
    ft_printf("%hhd\n", CHAR_MAX);
    printf("%hhd\n\n", CHAR_MAX);
    
    ft_printf("%hhd\n", CHAR_MAX + 42);
    printf("%hhd\n\n", CHAR_MAX + 42);

    ft_printf("%-50s--\n", "Hello, world!");
    printf("%-50s--\n\n", "Hello, world!");
    
    ft_printf("%-#050.40p %05d\n", main, 7);
    printf("%-#050.40p %05d\n\n", main, 7);

    ft_printf("%+u\n", 41);
    printf("%+u\n\n", 41);
    
    return 0;
}
