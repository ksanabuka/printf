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

int getNumDig(long long int d, int base)
{
    
    if (d != 0)
    {
        int c = 1;
        while (d / base != 0)
        {
            d = d/base;
            c++;
        }
        return c; 
    }
    else 
        return 1; 
}

char *addZerosPrecision(char * num, int numDigits, int precision)
{
    int diff = precision - numDigits;
    
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

char *addZerosWidth(char * num, int numDigits, int width)
{
    int diff = width - numDigits;
    
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
    int numDigits = getNumDig(d, 10);
    int sign = getSign(params, content);

    char *num = ft_positoa((long long int) content);
    if (params->precision == 0 && d == 0)
    {
        num[0] = '\0';
    }

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

    if (params->fl_space == 1 && (d >= 0 && params->fl_sign == 1))
    {
        params->fl_space = -1;
    }
        
    
    if (params->fl_zeropadding == 1 && params->fl_sign == 1 && params->fl_space == 1 && params->width  > numDigits + 2)
    {
        num = addZerosWidth(num, numDigits + 2, params->width);

    } 
    else if (params->fl_zeropadding == 1 && (params->fl_sign == 1 || params->fl_space == 1) && params->width  > numDigits + 1)
        num = addZerosWidth(num, numDigits + 1, params->width);
       
    
    if(params->precision > numDigits)
        num = addZerosPrecision(num, numDigits, params->precision);


    if (d < 0 || params->fl_sign != -1)
    {
        params->fl_sign = 1;
    }
    
    if (params->fl_sign != -1)
    {
        num = addSign(num, sign);
    }

      
   if (params->fl_space == 1 && d > 0)
    {
        num = addSpace(num);    
    }

    if (params->width > (int)ft_strlen(num))
    {
        num = (params->fl_align == 1) ? addSpaces(num, params, 1): addSpaces(num, params, 0);         
    }
    
    return num; 
    
 }