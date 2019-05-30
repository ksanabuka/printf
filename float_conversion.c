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

char * rounding(char * s)
{
    int len = ft_strlen(s); 
    int i = len - 1; 
    char * new; 
    if (s[i] >= '5' && s[i] <= '9' && i - 1 >= 0)
        {
            if (s[i - 1] < '9')
            {
                s[i - 1] = s[i - 1] + 1;
            }
            else 
            {
                s[i - 1] = '0';
                i = i - 2; 
                while (i >= 0)
                {
                    if (s[i] < '9')
                    {
                        s[i] = s[i] + 1;
                        break;
                    }
                    else 
                    {
                        s[i] = '0';
                        if (i == 0 && s[i] == '0')
                            return 0;
                        i--;
                    }
                }
                
            }
        }
    new = ft_strnew(len - 1);
    i = 0;
    while (i < len - 1)
    {
        new[i] = s[i];
        i++;
    }
    free(s);
    return new;          
}

char * createStr0(int len)
{
    char * str = ft_strnew(len); 
    int i = 0;
    while (i < len)
    {
        str[i] = '0';
        i++;
    }
    return str; 
}


char * fracture_part(long double *d, t_params * params)
{
    char * res ;
    char * tmp; 
    char * str;
    if (params->precision == 0)
    {    
       str = ft_strnew(1);
       return str;
    }

    str = ft_strnew(15);
    int i = 0; 
    long double aftercoma = *d - (long long)(*d); 
    int mnozhnyk = 10; 
    while (42)
    {
        if (params->precision != -1)
            if (i == params->precision + 1)
                break;
        if (aftercoma == 0 || (params->precision == -1 && i == 7) || i == 17)
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
    
        str = rounding(str);

    if (!str)
    {
        *d = *d + 1; 
        if (params->precision == 0)
        {
            str = createStr0(1);
            str[0] = '\0'; 
        }
        else if (params->precision == -1)
        {
            str = createStr0(6);
        }
        else if (params->precision > 0)
        {
            str = createStr0(params->precision);
        }
     }

    if (params->precision > 0 && (int)ft_strlen(str) < params->precision)
    {
        int len1 = params->precision - (int)ft_strlen(tmp);
        tmp = createStr0(len1);
        res = tmp; 
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

char * f_repr(t_params * params, long double * dig)
 {
    char * res;
    char * tmp = ft_strnew(1); 
    long double d = *dig; 
    int sign = (d < 0) ? '-' : '+';
    char * fracturial_part =  fracture_part(&d, params); 
    d = (d < 0) ? -d : d;
    char * integral_part = ft_itoa_base((long long) d, 10);
    
    
    
    if (fracturial_part[0] != '\0' && params->precision != 0)
    {
        tmp[0] = '.';
        res = integral_part; 
        integral_part = ft_strjoin(integral_part, tmp);
        free(res);
        free(tmp);
    }
    
    res = ft_strjoin(integral_part, fracturial_part);
    free(integral_part);
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
         
    if (params->fl_zeropadding == 1 && (params->fl_sign == 1 && params->fl_space == 1) && params->width  > (int)ft_strlen(res) + 2)
    {
        res = addZerosWidth(res, ft_strlen(res) + 2, params->width);

    } 
    else if (params->fl_zeropadding == 1 && (params->fl_sign == 1 || params->fl_space == 1) && params->width  > (int)ft_strlen(res) + 1)
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