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

		printf("%#c\n", 0);
		ft_printf("%#c\n\n", 0);

		printf("%.2f\n", 0.9375);
		ft_printf("%.2f\n\n", 0.9375); 

		printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
		ft_printf ("floats: %4.2f %+.0e %E \n\n", 3.1416, 3.1416, 3.1416);

		printf ("floats: %4.2    %f  %.f     %5.6f   %.0f    %.0f   %f \n", 3.1416, 3.1416, 3.1416, 0, 0.01, 0, 1416);
		ft_printf ("floats: %4.2    %f  %.f     %5.6f   %.0f    %.0f   %f \n", 3.1416, 3.1416, 3.1416, 0, 0.01, 0, 1416);
		system("leaks a.out");

	// ft_printf("%f\n", 4.3);
//    char *string = "hello worlds";
		

		return 0;
}
