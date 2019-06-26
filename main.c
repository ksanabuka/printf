//
//  main.c
//  printf
//
//  Created by Oksana Buksha on 6/8/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.


// gcc -Wall -Wextra -g  -I. -I/helpers helpers/*.c *print_type_info*.c main.c parse*.c

// gcc -Wall -Wextra -g -fsanitize=address -L. -I./helpers -lftprintf *print_type_info.c main.c parser.c -o aa


//valgrind --leak-check=full --log-file="fillit_test_log/log_errorfile$i.txt"
// -fsanitize=address

#include <fcntl.h>



#include <stdio.h>
#include "parser.h"
#include <limits.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

		//argc = 0;
		argv = 0;
		int * a = &argc; 

 //  int *array = (int *)malloc(sizeof(int) * 100);
 //  free(array);

 //  array[4] = 7;
 		//system("leaks a.out");

	printf("%0x %#0x\n", 12345);

	ft_printf("%0x %#0x\n", 12345);
	
		// char *temp = "i am a big string";
		// char *ptr = "temp";
		// printf("%p\n is the pointer address of pointer %s\n", temp, ptr);
		// ft_printf("%p\n is the pointer address of pointer %s\n", temp, ptr);

		// printf("%015.4+d\n", 45354353);
		// //ft_printf("%015.4+d\n", 45354353);

		// printf("%+015.4d\n", 45354353);
		// //ft_printf("%+015.4d\n", 45354353);

		// // printf("%+0.5d\n", 45354353);
		// // ft_printf("%+0.5d\n", 45354353);

		// // printf("%.c", 0);
		// ft_printf("%b", 17);

		// printf("%#12.5x\n", 125);
		// ft_printf("%#12.5x\n", 125);

		// printf("%#f\n", 0);
		// ft_printf("%#f\n\n", 0);


		// printf("%b\n", argc);
		// ft_printf("%b\n", argc);

		// printf("%.2f\n", 0.9375);
		// ft_printf("%.2f\n\n", 0.9375); 

		// printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
		// ft_printf ("floats: %4.2f %+.0e %E \n\n", 3.1416, 3.1416, 3.1416);


		// printf ("| %f \n", 1416.0);
		// ft_printf ("| %f \n", 1416.0);



	// ft_printf("%f\n", 4.3);
//    char *string = "hello worlds";
		

		return 0;
}
