#include "ft_printf.h"

int integral_quotient(long double d)
{
    long double c = 1;
    int i = 0;  
    if (d < 0)
        d =-d; 
    while (c < d)
    {
        c = c * 10;
        i++;
    }
    return i; 
}


char * fracture_part(long double d, t_params * params)
{
    char * str;
    if (d == 0)
    {    
       str = ft_strnew(1);
       return str;
    }

    char * str = ft_strnew(15);
    int i = 0; 
    long double aftercoma = d - (long long)d; 
    long long res = 0; 
    int mnozhnyk = 10; 
    while (42)
    {
        if (params->precision != -1)
            if (i == params->precision)
                break;
        if (aftercoma == 0 || params->precision == -1 && i == 5 || i == 15;)
            break; 
        if ((int) (aftercoma * mnozhnyk) == 0 && aftercoma != 0)
        {
            str[i] = '0';
        }
        else 
        {
            str[i] = (int) (aftercoma * mnozhnyk) + '0';
        }
        aftercoma = aftercoma * mnozhnyk - (int) (aftercoma * mnozhnyk);
        i++; 
    }

    char * res;
    char * tmp; 
    
    if (params->precision > 0 && ft_strlen(str) < params->precision)
    {
        int len1 = params->precision - ft_strlen(str);
        tmp = ft_strnew(len1);
        i = 0; 
        while (i < len1)
        {
            tmp[i] = '0';
            i++;
        }
        res = str; 
        str = ft_strjoin(str, tmp);
        free(res);
        free(tmp);
    }


    if (ft_strlen(str) < 6 && params->fl_diez == 1)
    {
       int len = 6 - ft_strlen(str); 
        tmp = ft_strnew(len);
        i = 0; 
        while (i < len)
        {
            tmp[i] = '0';
            i++;
        }
        res = str; 
        str = ft_strjoin(str, tmp);
        free(res);
        free(tmp);
    }
    return str; 
}

char * f_repr(t_params * params, long double dig)
 {
    char * res;
    char * tmp; 
    long double d = dig; 
    int sign = (d < 0) ? '-' : '+';
    char * fracturial_part =  fracture_part(d, params->precision); 
    d = (d < 0) ? -d : d;
    char * integral_part = ft_itoa_base((long long) d, 10);
    if (d =! 0 && fracturial_part[0] != '\0')
    {
        res = ft_strnew(1);
        res[0] = '.';
        tmp = res; 
        res = ft_strjoin(integral_part, res);
        free(tmp);
        free(integral_part);
    }
    tmp = res; 
    res = ft_strjoin(res, fracturial_part);
    free(tmp);
    free(fracturial_part);


    if ((params->fl_align == 1 && params->fl_zeropadding == 1) || (params->precision > 0 && params->fl_zeropadding == 1))
    {
        params->fl_zeropadding = -1;
    }


    if ((params->fl_sign == 1 && params->fl_space == 1) || (params->fl_space == 1 && d < 0))
    {
        params->fl_space = -1;
    }
    
    if (params->fl_space == 1 && (d >= 0 && params->fl_sign == 1))
    {
        params->fl_space = -1;
    }
         
    if (params->fl_zeropadding == 1 && (params->fl_sign == 1 && params->fl_space == 1) && params->width  > ft_strlen(res) + 2)
    {
        res = addZerosWidth(res, ft_strlen(res) + 2, params->width);

    } 
    else if (params->fl_zeropadding == 1 && (params->fl_sign == 1 || params->fl_space == 1) && params->width  > ft_strlen(res) + 1)
        res = addZerosWidth(res, ft_strlen(res) + 1, params->width);
       
    
    if (dig < 0 || params->fl_sign != -1)
    {
        params->fl_sign = 1;
    }
    
    if (params->fl_sign != -1)
    {
        res = addSign(res, sign);
    }

   if (params->fl_space == 1 && d > 0)
    {
        res = addSpace(res);    
    }

    if (params->width > (int)ft_strlen(res))
    {
        res = (params->fl_align == 1) ? addSpaces(res, params, 1): addSpaces(res, params, 0);         
    }
    
    return res; 
    
 }