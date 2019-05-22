#include "ft_printf.h"

 int getSign(t_params * params, void * content)
 {
    if (params->fl_sign == -1 && (long long int)content >= 0)
        return 0; 
    else if ((long long int)content >= 0)
        return '+';
    else  
        return '-';
 }

int getNumDig(long long int d)
{
    if (d != 0)
    {
        int c = 1;
        while (d / 10 != 0)
        {
            d = d/10;
            c++;
        }
        return c; 
    }
    else 
        return 0; 
}
  
char *addZeros(char * num, int numDigits, t_params * params)
{
    int diff = params->precision - numDigits;
    
    char * zeros = ft_strnew(diff);
    int i = 0;
    while (i < diff)
    {
        zeros[i] = '0';
        i++;
    }
    char * res = ft_strjoin((char const *)zeros, (char const *)num);
    free(num);
    free(zeros);
    return res; 
}


char *addSign(char * num, int sign)
{
    char * str = ft_strnew(1);
    str[0] = sign;
    str[1] = '\0';
    char * res = ft_strjoin((char const *)str, (char const *)num);
    free(num);
    free(str);
    return res; 
}

char *addSpace(char * num)
{
   
    char * res; 
    char * str = ft_strnew(2);
    str[0] = ' ';
    str[1] = '\0';
    res = ft_strjoin((char const *)str, (char const *)num);
    free(str);
    free(num);
    return res; 
}

char *addSpaces(char * num, t_params * params, int side)
{
    int diff = params->width - (int)ft_strlen(num);
    char * res; 
    char * str = ft_strnew(diff);
    int i = 0;
    while (i < diff)
    {
        str[i] = ' ';
        i++;
    }
    if (side == 0)
        res = ft_strjoin((char const *)str, (char const *)num);
    else 
        res = ft_strjoin((char const *)num, (char const *)str);

    free(num);
    free(str);
    return res; 
}

 char * d_repr(t_params * params, void * content)
 {
    int long long d = (int long long) content; 
    int numDigits = getNumDig(d);
    int sign = getSign(params, content);

    char *num = ft_positoa((long long int) content);
    if (params->precision == 0 && d == 0)
    {
        num[0] = '\0';
    }

    // if(params->precision > numDigits && params->precision < params->width)
    // {

    // }
    if ((params->fl_align == 1 && params->fl_zeropadding == 1) || (params->precision > 0 && params->fl_zeropadding == 1))
    {
        params->fl_zeropadding = -1;
    }


    if ((params->fl_sign == 1 && params->fl_space == 1))
    {
        params->fl_space = -1;
    }
    if ((params->fl_space == 1 && d < 0))
    {
        params->fl_space = -1;
    }

    if (params->fl_space == 1)
    {
        if (d >= 0 && params->fl_sign == 1)
        {
            params->fl_space = -1;
        }
        else 
        {
            num = addSpace(num);
        }
    }
    if(params->precision > numDigits)
        num = addZeros(num, numDigits, params); 

    if (sign)
        num = addSign(num, sign);

    if (params->width > (int)ft_strlen(num))
    {
        num = (params->fl_align) ? addSpaces(num, params, 1): addSpaces(num, params, 0);         
    }
    
    return num; 
    
 }