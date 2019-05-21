#include "ft_printf.h"

int main(int ac, char **av)
{
    t_arg * head_arg = 0;
    ac = 0;

    int status = parseStr(av[1], &head_arg);
    printf("%d\n", status);

    intptr_t d = 123456789;
    
    char * str =  d_repr(head_arg->chunk_params, (void*) d);
    printf("%s\n", str); 

    //+000000123456789    %
    return 0;
}