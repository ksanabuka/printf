#include "ft_printf.h"

 char *add0x(char * num)
{
    if (num[0] == '0' && num[1] == '\0')
        return num;
    char * res; 
    char * str = ft_strnew(2);
    str[0] = '0';
    str[1] = 'x';
    res = ft_strjoin((char const *)str, (char const *)num);
    free(str);
    free(num);
    return res; 
}
 
 void toxX(t_params * params, char *s)
 {
     int i = 0;
     if (params->switchoff_format == 'X')
     {
         while(s[i])
         {
             if (s[i] >= 'a' && s[i] <= 'z')
             {
                 s[i] = s[i] - 32;
             }
             i++;
         }
     }
     else if (params->switchoff_format == 'x')
     {
         while(s[i])
         {
             if (s[i] >= 'A' && s[i] <= 'Z')
             {
                 s[i] = s[i] + 32;
             }
             i++;
         }
     }

 }

 char * x_X_repr(t_params * params, void * content)
 {
    int long long d = (int long long) content; 

    if (params->fl_sign == 1)
        params->fl_sign = -1;
    if (params->fl_space == 1)
        params->fl_space = -1;

    char *num = ft_itoa_base((long long int) content, 16);
    int numDigits = (int)ft_strlen(num);

    if (params->precision == 0 && d == 0)
        num[0] = '\0';
    
    if ((params->fl_align == 1 && params->fl_zeropadding == 1) || (params->precision > 0 && params->fl_zeropadding == 1))
        params->fl_zeropadding = -1;
     
    if(params->precision > numDigits)
        num = addZerosPrecision(num, numDigits, params->precision);

    if(params->fl_diez == 1 && (params->precision != 0 || d != 0))
        num =  add0x(num);

    if (params->precision == -1 && params->fl_zeropadding == 1 && params->width > (int)ft_strlen(num))
        num = addZerosWidth(num, (int)ft_strlen(num), params->width);

    if (params->width > (int)ft_strlen(num))
        num = (params->fl_align == 1) ? addSpaces(num, params, 1): addSpaces(num, params, 0);         
    
    toxX(params, num);
    return num; 
 }