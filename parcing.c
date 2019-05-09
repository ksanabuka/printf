#include "ft_printf.h"

int validateFlags(int flag, t_arg n_arg)
{

}

int addFlags(char *s, t_arg n_arg)
{
    int i = 0;
    while(s[i] && validflag(s[i]) && validFlagSequence(s[i], n_arg))
    {
        addFlag(s[i]);

    }

}

int parseStr(char *s, t_arg)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%' && s[i + 1] != '%' && s[i + 1] != '\0')
        {
            if (!addFlags(*(s + i + 1), n_arg);
                return 0;
            i = skipFlags(*(s + i + 1));
        }
        else if (s[i] == '%' && s[i + 1] == '%')
        {
            save string in n_arg;
            i = i + 2; 
        }
        else
        {
            while (s[i] && s[i] != '%')
            {
                save string in n_arg;
                i++;
            }
        }
    }
    return 1;
}
