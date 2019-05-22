#include "ft_printf.h"


int main(int ac, char **av)
{
    ac = 0;
    av = 0;
  
  ft_printf("%+d", 42);
ft_printf("%+d", -42);
ft_printf("% d", 9999);
ft_printf("% d", -9999);
ft_printf("{% +d}", 42);
ft_printf("{%+ d}\n", 42);
ft_printf("{%+03d}", 0);
ft_printf("{% 03d}", 0);
ft_printf("{%0-3d}\n", 0);
ft_printf("{%+03d}", 12);
ft_printf("{%+03d}", 123456);
ft_printf("{%03.2d}", 0);

ft_printf("\nPASSED\n");
  ft_printf("%.4d|\n", 42);
  ft_printf("%.4d|\n", 424242);
  ft_printf("%.4d|\n", -424242);
  ft_printf("%15.4d|\n", 42);
   ft_printf("%15.4d|\n", 424242);
ft_printf("%8.4d|\n", 424242424);
ft_printf("%15.4d|\n", -42);
ft_printf("%15.4d|\n", -424242);
ft_printf("%8.4d|\n", -424242424);
ft_printf("%4.15d|\n", 42);
ft_printf("%4.15d|\n", 424242);
ft_printf("%4.8d|\n", 424242424);
ft_printf("%4.15d|\n", -42);
ft_printf("%4.15d|\n", -424242);
ft_printf("%4.8d|\n", -424242424);
ft_printf("%.d, %15.0d|\n", 0, 0);
ft_printf("%.10d|\n", -42);


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
