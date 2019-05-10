#include "ft_printf.h"

t_arg *initArg(void)
{
    t_arg * arg = (t_arg *)malloc(sizeof(t_arg));
    if (!arg)
        return 0;

    arg->qty = 0;
    arg->conv_chunk = 0;
    arg->next = 0;
    arg->str_chunk = 0;
    return (arg);
}

 void add_chunk(int strORconversion, void * cont, t_arg * head)
 {
     
 }