#include "ft_printf.h"

void ft_printf(char *fmt, ...)
{
    t_arg * head_arg = 0;
    va_list ap;
    intptr_t digit;
   
    va_start(ap, fmt);
    parseStr(fmt, &head_arg);

    digit = va_arg(ap, int);
    va_end(ap);

    char * str =  d_repr(head_arg->chunk_params, (void*) digit);
    printf("%s\n", str);
}

int main(int ac, char **av)
{
    ac = 0;
    av = 0;
    ft_printf("before %d after", 42);
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
