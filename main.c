//
//  main.c
//  printf
//
//  Created by Oksana Buksha on 6/8/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.


//gcc -Wall -Wextra -Werror -g  -I. -I/helpers helpers/*.c *print_type_info.c main.c parser.c


// gcc -Wall -Wextra -g -fsanitize=address -L. -I./helpers -lftprintf *print_type_info.c main.c parser.c -o aa


//valgrind --leak-check=full --log-file="fillit_test_log/log_errorfile$i.txt"
// -fsanitize=address

#include <fcntl.h>



#include <stdio.h>
#include "parser.h"
#include <limits.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    argc = 0;
    argv = 0;

 //  int *array = (int *)malloc(sizeof(int) * 100);
 //  free(array);

 //  array[4] = 7;
 // // system("leaks a.out");

    printf("%#c\n\n", 0);
    ft_printf("%#c\n\n", 0);

   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);

   printf ("floats: %4.2    %f  %.f     %5.6f   %.0f    %.0f   %f \n", 3.1416, 3.1416, 3.1416, 0, 0.01, 0, 1416);
   ft_printf ("floats: %4.2    %f  %.f     %5.6f   %.0f    %.0f   %f \n", 3.1416, 3.1416, 3.1416, 0, 0.01, 0, 1416);
 // system("leaks a.out");

  // ft_printf("%f\n", 4.3);
//    char *string = "hello worlds";
    

//printf("0%   %\n", "test");
//printf("1%jx\n", 4294967296);
//printf("2%jx\n", -4294967296);
//printf("3%jx\n", -4294967297);
//printf("4%.2s is a string\n", "this");
//printf("5%5.2s is a string\n", "this");
//printf("6%-.2s is a string\n", "this");
//printf("7%-5.2s is a string\n", "this");
//printf("8@moulitest: %s\n", NULL);
//printf("9%s %s\n", NULL, string);
//printf("11%5c\n", 42);
//printf("12%-5c\n", 42);
//printf("13%2c\n", 0);
//printf("14%jd\n", 9223372036854775807);
//printf("15%jd\n", -9223372036854775808);
//printf("16%zd\n", 4294967295);
//printf("17%zd\n", 4294967296);
//printf("18% u\n", 4294967295);
//printf("21%ju\n", 4999999999);
//printf("22%ju\n", 4294967296);
//printf("23%hU\n", 4294967296);
//printf("24%U\n", 4294967296);
//printf("25%5%\n\n");
//printf("26%-5%\n\n");
//printf("27%.0%\n\n");

//ft_printf("0%   %\n", "test");
//ft_printf("1%jx\n", 4294967296);
//ft_printf("2%jx\n", -4294967296);
//ft_printf("3%jx\n", -4294967297);
//ft_printf("4%.2s is a string\n", "this");
//ft_printf("5%5.2s is a string\n", "this");
//ft_printf("6%-.2s is a string\n", "this");
//ft_printf("7%-5.2s is a string\n", "this");
//ft_printf("8@moulitest: %s\n", NULL);
//ft_printf("9%s %s\n", NULL, string); 
//ft_printf("11%5c\n", 42);
//ft_printf("12%-5c\n", 42);
//ft_printf("13%2c\n", 0);
//ft_printf("14%jd\n", 9223372036854775807);
//ft_printf("15%jd\n", -9223372036854775808);
//ft_printf("16%zd\n", 4294967295);
//ft_printf("17%zd\n", 4294967296);
//ft_printf("18% u\n", 4294967295);
//ft_printf("21%ju\n", 4999999999);
//ft_printf("22%ju\n", 4294967296);
//ft_printf("23%hU\n", 4294967296);
//ft_printf("24%U\n", 4294967296);
//ft_printf("25%5%\n");
//ft_printf("26%-5%\n");
//ft_printf("27%.0%\n");


    return 0; 
    // ft_printf("1%x|\n", 42);
    // printf("1%x|\n\n", 42);

    // ft_printf("2before %x after|\n", 42);
    // printf("2before %x after|\n\n", 42);

    // ft_printf("3%x, %x|\n", 0, 4294967295u);
    // printf("3%x, %x|\n\n", 0, 4294967295u);

    // ft_printf("3%x, %o|\n", 0, 4294967295u);
    // printf("3%x, %o|\n\n", 0, 4294967295u);

    // ft_printf("4{%030x}\n", 0xFFFF);
    // printf("4{%030x}\n\n", 0xFFFF);

    // ft_printf("5{%030X}\n", 0xFFFF);
    // printf("5{%030X}\n\n", 0xFFFF);

    // ft_printf("6%#x|\n", 42);
    // printf("6%#x|\n\n", 42);

    // ft_printf("7%#X|\n", 42);
    // printf("7%#X|\n\n", 42);

    // ft_printf("8%#x|\n", 0);
    // printf("8%#x|\n\n", 0);

    // ft_printf("9%#x|\n", 2147483647);
    // printf("9%#x|\n\n", 2147483647);

    // ft_printf("10%.4x|\n", 42);
    // printf("10%.4x|\n\n", 42);

    // ft_printf("11%.4x|\n", 424242);
    // printf("11%.4x|\n\n", 424242);

    // ft_printf("12%15.4x|\n", 42);
    // printf("12%15.4x|\n\n", 42);

    // ft_printf("13%15.4x|\n", 424242);
    // printf("13%15.4x|\n\n", 424242);

    // ft_printf("14%8.4x|\n", 424242424);
    // printf("14%8.4x|\n\n", 424242424);

    // ft_printf("15%4.15x|\n", 42);
    // printf("15%4.15x|\n\n", 42);

    // ft_printf("16%4.15x|\n", 42424242);
    // printf("16%4.15x|\n\n", 42424242);

    // ft_printf("17%4.8x|\n", 424242424);
    // printf("17%4.8x|\n\n", 424242424);

    // ft_printf("18%.x, %.0x|\n", 0, 0);
    // printf("18%.x, %.0x|\n\n", 0, 0);

    // ft_printf("19%#.x, %#.0x|\n", 0, 0);
    // printf("19%#.x, %#.0x|\n\n", 0, 0);

    // ft_printf("20{%#.5x}|\n", 1);
    // printf("20{%#.5x}|\n\n", 1);

    // ft_printf("21% x|%+x|\n", 42, 42);
    // printf("21% x|%+x|\n\n", 42, 42);


    // ft_printf("%o|\n", 42);
    // printf("%o|\n\n", 42);

    // ft_printf("before %o after|\n", 42);
    // printf("before %o after|\n\n", 42);

    // ft_printf("%#o|\n", 42);
    // printf("%#o|\n\n", 42);

    // ft_printf("%#o|\n", 0);
    // printf("%#o|\n\n", 0);

    // ft_printf("%#o|\n", 2147483647);
    // printf("%#o|\n\n", 2147483647);

    // ft_printf("%+o|\n", 0);
    // printf("%+o|\n\n", 0);

    // ft_printf("%+o|\n", 42);
    // printf("%+o|\n\n", 42);

    // ft_printf("%.4o|\n", 42);
    // printf("%.4o|\n\n", 42);

    // ft_printf("%.4o|\n", 424242);
    // printf("%.4o|\n\n", 424242);

    // ft_printf("%15.4o|\n", 42);
    // printf("%15.4o|\n\n", 42);

    // ft_printf("%15.4o|\n", 424242);
    // printf("%15.4o|\n\n", 424242);

    // ft_printf("%8.4o|\n", 424242424);
    // printf("%8.4o|\n\n", 424242424);

    // ft_printf("%4.15o|\n", 42);
    // printf("%4.15o|\n\n", 42);

    // ft_printf("%4.15o|\n", 424242);
    // printf("%4.15o|\n\n", 424242);

    // ft_printf("%4.8o|\n", 424242424);
    // printf("%4.8o|\n\n", 424242424);

    // ft_printf("1%.o, %.0o|\n", 0, 0);
    // printf("1%.o, %.0o|\n\n", 0, 0);

    // ft_printf("2%.o, %.0O|\n", 0, 0);
    // printf("2%.o, %.0O|\n\n", 0, 0);

    // ft_printf("3%#.o, %#.0o|\n", 0, 0);
    // printf("3%#.o, %#.0o|\n\n", 0, 0);

    // ft_printf("%#.3o|\n", 1);
    // printf("%#.3o|\n\n", 1);

    // ft_printf("%o|\n", -42);
    // printf("%o|\n\n", -42);

    // ft_printf("%o|\n", 2147483647);
    // printf("%o|\n\n", 2147483647);

    // ft_printf("% o|%+o|\n", 42, 42);
    // printf("% o|%+o|\n\n", 42, 42);

    // ft_printf("%#.o|\n", 42);
    // printf("%#.o|\n\n", 42);


    // ft_printf("\nPASSED\n");

    // ft_printf("{%  03d}\n", 0);
    // printf("{%  03d}\n\n", 0);
    
    // ft_printf("{%  03d}\n", 5);
    // printf("{%  03d}\n\n", 5);
    
    // ft_printf("%+d\n", 42);
    // printf("%+d\n\n", 42);
    
    // ft_printf("%+d\n", -42);
    // printf("%+d\n\n", -42);
    
    // ft_printf("% d\n", 9999);
    // printf("% d\n\n", 9999);
    
    // ft_printf("% d\n", -9999);
    // printf("% d\n\n", -9999);
    
    // ft_printf("{% +d}\n", 42);
    // printf("{% +d}\n\n", 42);
    
    // ft_printf("{%+ d}\n", 42);
    // printf("{%+ d}\n\n", 42);
    
    // ft_printf("{%+03d}\n", 0);
    // printf("{%+03d}\n\n", 0);
    
    // ft_printf("{% 03d}\n", 0);
    // printf("{% 03d}\n\n", 0);
    
    // ft_printf("{%0-3d}\n", 0);
    // printf("{%0-3d}\n\n", 0);
    
    // ft_printf("{%+03d}\n", 12);
    // printf("{%+03d}\n\n", 12);
    
    // ft_printf("{%+03d}\n", 123456);
    // printf("{%+03d}\n\n", 123456);
    
    // ft_printf("{%03.2d}\n", 0);
    // printf("{%03.2d}\n\n", 0);
    
    // ft_printf("%.4d|\n", 42);
    // printf("%.4d|\n\n", 42);
    
    // ft_printf("%.4d|\n", 424242);
    // printf("%.4d|\n\n", 424242);
    
    // ft_printf("%.4d|\n", -424242);
    // printf("%.4d|\n\n", -424242);
    
    // ft_printf("%15.4d|\n", 42);
    // printf("%15.4d|\n\n", 42);
    
    // ft_printf("%15.4d|\n", 424242);
    // printf("%15.4d|\n\n", 424242);
    
    // ft_printf("%8.4d|\n", 424242424);
    // printf("%8.4d|\n\n", 424242424);
    
    // ft_printf("%15.4d|\n", -42);
    // printf("%15.4d|\n\n", -42);
    
    // ft_printf("%15.4d|\n", -424242);
    // printf("%15.4d|\n\n", -424242);
    
    // ft_printf("%8.4d|\n", -424242424);
    // printf("%8.4d|\n\n", -424242424);
    
    // ft_printf("%4.15d|\n", 42);
    // printf("%4.15d|\n\n", 42);
    
    // ft_printf("%4.15d|\n", 424242);
    // printf("%4.15d|\n\n", 424242);
    
    // ft_printf("%4.8d|\n", 424242424);
    // printf("%4.8d|\n\n", 424242424);
    
    // ft_printf("%4.15d|\n", -42);
    // printf("%4.15d|\n\n", -42);
    
    // ft_printf("%4.15d|\n", -424242);
    // printf("%4.15d|\n\n", -424242);
    
    // ft_printf("%4.8d|\n", -424242424);
    // printf("%4.8d|\n\n", -424242424);
    
    // ft_printf("%.d, %15.0d|\n", 0, 0);
    // printf("%.d, %15.0d|\n\n", 0, 0);
    
    // ft_printf("%.10d|\n", -42);
    // printf("%.10d|\n\n", -42);
    
    // ft_printf("%ld%ld\n", 0, 42);
    // printf("%ld%ld\n\n", 0, 42);
    
    // ft_printf("%ld\n", (long)INT_MAX + 1);
    // printf("%ld\n\n", (long)INT_MAX + 1);
    
    // ft_printf("%ld\n", (long)INT_MIN - 1);
    // printf("%ld\n\n", (long)INT_MIN - 1);
    
    // ft_printf("%ld\n", LONG_MAX);
    // printf("%ld\n\n", LONG_MAX);
    
    // ft_printf("%ld\n", LONG_MIN);
    // printf("%ld\n\n", LONG_MIN);
    
    // ft_printf("%lld\n", LLONG_MAX);
    // printf("%lld\n\n", LLONG_MAX);
    
    // ft_printf("%lld\n", LLONG_MIN);
    // printf("%lld\n\n", LLONG_MIN);
    
    // ft_printf("%hd%hd\n", (short int)0, (short int)42);
    // printf("%hd%hd\n\n", (short int)0, (short int)42);
    
    // ft_printf("%hd\n", SHRT_MAX);
    // printf("%hd\n\n", SHRT_MAX);
    
    // ft_printf("%hd\n", SHRT_MIN);
    // printf("%hd\n\n", SHRT_MIN);
    
    // ft_printf("%hhd%hhdv\n", 1, 42);
    // printf("%hhd%hhdv\n\n", 1, 42);
    
    // ft_printf("%hhd\n", CHAR_MAX);
    // printf("%hhd\n\n", CHAR_MAX);
    
    // ft_printf("%hhd\n", CHAR_MAX + 42);
    // printf("%hhd\n\n", CHAR_MAX + 42);
    
    // ft_printf("%hhd\n", CHAR_MIN);
    // printf("%hhd\n\n", CHAR_MIN);
    
    // ft_printf("%hhd\n", CHAR_MIN - 42);
    // printf("%hhd\n\n", CHAR_MIN - 42);
    
    // ft_printf("%hhd\n", CHAR_MAX);
    // printf("%hhd\n\n", CHAR_MAX);
    
    // ft_printf("%hhd\n", CHAR_MAX + 42);
    // printf("%hhd\n\n", CHAR_MAX + 42);

    // ft_printf("%-50s--\n", "Hello, world!");
    // printf("%-50s--\n\n", "Hello, world!");
    
    // ft_printf("%-#050.40p %05d\n", main, 7);
    // printf("%-#050.40p %05d\n\n", main, 7);

    // ft_printf("%+u\n", 41);
    // printf("%+u\n\n", 41);
    
    return 0;
}
