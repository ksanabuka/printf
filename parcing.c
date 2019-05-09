#include "ft_printf.h"

void parseStr(char *s, t_params myparams)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%' && s[i + 1] != '%')
        {

        }
        else 
            i++; 
    }

}
