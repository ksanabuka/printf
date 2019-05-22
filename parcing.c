#include "ft_printf.h"

int addFlag(char c, t_params *params)
{
    if (c == 32)
    {
        params->fl_space = 1;
        return 1;
    }
    else if (c == 35)
    {
        params->fl_diez = 1;
        return 1;
    }
    else if (c == 43)
    {
        params->fl_sign = 1;
        return 1;
    }
    else if (c == 45)
    {
        params->fl_align = 1;
        return 1;
    }
    else if (c == 48)
    {
        params->fl_zeropadding = 48;
        return 1;
    }
    else 
        return 0;
}

int addWidth(char *s, t_params *params)
{
    int i = 0;
    int n = 0; 
    if (s[i] == 48)
        return 0; 
    while (s[i] && s[i] >= '0' && s[i] <= '9')
    {
        n = n * 10 + s[i] - '0';
        i++; 
    }
    if ((s[i] < '0' || s[i] > '9'))
    {
        if (n > 0)
        {
            params->width = n; 
            return 1;
        }
    }
        return 0;
}

int skipWidth(char *s)
{
    int i = 0;
    
    while (s[i] && s[i] >= '0' && s[i] <= '9')
    {
        i++; 
    }
    return i;
}

int addPrecision(char *s, t_params *params)
{
    int i = 0;
    int n = 0; 

    if (s[i] != '.' || (s[i] == '.' && s[i + 1] == '\0'))
        return 0; 
    else 
    {
        i++;
        while (s[i] && s[i] >= '0' && s[i] <= '9')
        {
            n = n * 10 + s[i] - '0';
            i++; 
        }
        if ((s[i] < '0' || s[i] > '9'))
        {
            if (n > 0)
            {
                params->precision = n; 
                return 1;
            }
            else 
            {
                params->precision = 0; 
                return 1;
            }
        }
            return 0;
    }
}

int skipPrecision(char *s)
{
    int i = 1;
    
    while (s[i] && s[i] >= '0' && s[i] <= '9')
    {
        i++; 
    }
    return i;
}

int addModififer(char *s, t_params *params)
{
    int i = 0;

    if (s[i] == 'l' && s[i + 1] == 'l')
    {    
        params->fm_ll = 1; 
        return 1;
    }
    else if (s[i] == 'l' && s[i + 1] != 'l')
    {    
        params->fm_l = 1; 
        return 1;
    }
    else if (s[i] == 'h' && s[i + 1] != 'h')
    {    
        params->fm_h = 1; 
        return 1;
    }
    else if (s[i] == 'h' && s[i + 1] == 'h')
    {    
        params->fm_hh = 1; 
        return 1;
    }
    else if (s[i] == 'L')
    {    
        params->fm_L = 1; 
        return 1;
    }
    else 
            return 0;
}

int skipModifier(char *s)
{
    int i = 0;

    if (s[i] == 'l' && s[i + 1] == 'l')
    {    
        return 2;
    }
    else if (s[i] == 'l' && s[i + 1] != 'l')
    {    
        return 1;
    }
    else if (s[i] == 'h' && s[i + 1] != 'h')
    {    
        return 1;
    }
    else if (s[i] == 'h' && s[i + 1] == 'h')
    {    
        return 2;
    }
    else if (s[i] == 'L')
    {    
        return 1;
    }
    else 
            return 0;
}

int addFormat(char *s, t_params *params)
{
    if (s[0] == 'd')
    {    
        params->switchoff_format = 'd'; 
        return 1;
    }
    else if (s[0] == 'i')
    {    
        params->switchoff_format = 'i'; 
        return 1;
    }
    else if (s[0] == 'o')
    {    
        params->switchoff_format = 'o'; 
        return 1;
    }
    else if (s[0] == 'u')
    {    
        params->switchoff_format = 'u'; 
        return 1;
    }
    else if (s[0] == 'x')
    {    
        params->switchoff_format = 'x'; 
        return 1;
    }
    else if (s[0] == 'X')
    {    
        params->switchoff_format = 'X'; 
        return 1;
    }
    else if (s[0] == 'f')
    {    
        params->switchoff_format = 'f'; 
        return 1;
    }
    else if (s[0] == 'F')
    {    
        params->switchoff_format = 'F'; 
        return 1;
    }
    else if (s[0] == 's')
    {    
        params->switchoff_format = 's'; 
        return 1;
    }
    else if (s[0] == 'c')
    {    
        params->switchoff_format = 'c'; 
        return 1;
    }
    else if (s[0] == 'p')
    {    
        params->switchoff_format = 'p'; 
        return 1;
    }
    else 
            return 0;
}

int checkLenModifier(t_params *myparams)
{
    if (ft_strchr("diouxX", myparams->switchoff_format))
    {
        if (myparams->fm_L == -1 && (myparams->fm_l + myparams->fm_ll + myparams->fm_h + myparams->fm_hh <= -2))
            return 1; 
        else 
            return 0; 
    }
    else if (ft_strchr("fF", myparams->switchoff_format))
    {
        if ((myparams->fm_L + myparams->fm_l) <= 0 && (myparams->fm_ll + myparams->fm_h + myparams->fm_hh == -3))
            return 1; 
        else 
            return 0; 
    }
    else if (ft_strchr("sc", myparams->switchoff_format))
    {
        if ((myparams->fm_L + myparams->fm_l + myparams->fm_ll + myparams->fm_h + myparams->fm_hh == -5))
            return 1; 
        else 
            return 0; 
    }
    else 
        return 0;
}

int validateFlags(t_params *myparams)
{
    int format = myparams->switchoff_format; 
    if (format == 'd' || format == 'i' || format == 'u')
    {
        if (myparams->fl_diez == -1 && checkLenModifier(myparams))
            return 1;
        else 
            return 0;
    }
    else if (format == 'o' || format == 'x' || format == 'X' || format == 'f' || format == 'F')
    {
        if (checkLenModifier(myparams))
            return 1;
        else 
            return 0;
    }
    else if (format == 's')
    {
        if (myparams->fl_diez == -1  && myparams->fl_sign == -1 && myparams->fl_zeropadding == -1 && myparams->fl_space == -1 && checkLenModifier(myparams))
            return 1;
        else 
            return 0;
    }
    else if (format == 'c')
    {
        if (myparams->fl_diez == -1  && myparams->fl_sign == -1 && myparams->fl_zeropadding == -1 && myparams->fl_space == -1 && (checkLenModifier(myparams)))
            return 1;
        else 
            return 0;
    }
    else 
        return 0; 
}

void printmyargs(t_arg ** head_arg)
{
    t_arg * head = * head_arg;

    while (head)
    {
        if (head->str_chunk == 0)
        {
            if (head->chunk_params->fl_diez != -1)
                printf("#,");
            if (head->chunk_params-> fl_sign != -1)
                printf("+,");
            if (head->chunk_params-> fl_align != -1)
                printf("-,");
            if (head->chunk_params->fl_zeropadding  != -1)
                printf("0,"); 
            if (head->chunk_params->fl_space  != -1)
                printf("space,"); 
            if (head->chunk_params->width != -1)
                printf("width = %d,", head->chunk_params->width); 
            if (head->chunk_params->precision != -1)
                printf("precision %d,", head->chunk_params->precision);
            if (head->chunk_params->fm_l  != -1)
              printf("l,");
            if (head->chunk_params->fm_ll  != -1)
              printf("ll,");
            if (head->chunk_params->fm_h  != -1)
               printf("h,");
            if (head->chunk_params->fm_hh  != -1)
              printf("hh,");
            if (head->chunk_params->fm_L  != -1)
              printf("L,");
            if (head->chunk_params-> switchoff_format  != -1)
              printf("format - %c,", head->chunk_params-> switchoff_format);
            printf("\n");
        }
        else 
            printf("string arg - %s\n", head->str_chunk);

        head = head->next;
    }
}

int addFlags(char *s, t_params *params)
{
    int i = 0;
    while (addFlag(s[i], params))
    {
        i++;
    }
    if (addWidth((s + i), params))
    {     
        i += skipWidth((s + i)); 
    }
    if (addPrecision((s + i), params))
    {   
        i += skipPrecision((s + i)); 
    }

    if (addModififer((s + i), params))
    {     
        i += skipModifier((s + i)); 
    }
    
    if (addFormat((s + i), params))
        return (i + 1);
    else 
        return 0; 
}

int ft_printf(char * fmt, ...)
{
    t_arg * head_arg = 0;
    char *s = fmt; 
    int i = 0;
    int diff = 0; 
    t_arg *cur; 
    va_list ap;
    intptr_t digit;
    va_start(ap, fmt);
    char * str;
    int j; 
    while (s[i] != '\0')
    {
        if (s[i] == '%')
        {
            if (s[i + 1] && s[i + 1] == '%')
            {
                write(1, "\%", 1);
                i = i + 2; 
            }
            else 
            {
                i++;
                cur = add_chunk(2, 0, &head_arg);

                diff = addFlags((s + i), cur->chunk_params);
                if (!diff || !validateFlags(cur->chunk_params))
                {
                    printf("current conversion not walid argument");
                    cleanup(&head_arg);
                    return 0;
                }

                digit = va_arg(ap, int);
                str =  d_repr((head_arg)->chunk_params, (void*) digit);
                j = 0;
                {
                    while (str[j])
                    {
                        write(1, &str[j], 1);
                        j++;
                    }
                }
                i += diff;

            }
        }
        else
        {
            if (s[i] && (s[i] != '%'))
            {
                write(1, &s[i], 1);
                i++;
            }
        }
    }
    va_end(ap);


    return 1;
}
