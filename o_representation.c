#include "ft_printf.h"

void strRev(char *s)
{
    
    int i = 0;

    while (s[i] != '\0')
        i++;

    int half = i / 2;

    i--;
    int beg = 0;
    char tmp;
    
    
        while (half)
        {
            tmp = s[beg];
            s[beg] = s[i];
            s[i] = tmp;
            half--;
            beg++;
            i--;
        }
}
 

char	*ft_itoa_base(long long int n, int base)
{
    char * res;
    if (!(res = (char*)malloc(sizeof(char) * 34)))
        return 0;

    if (n == 0)
    {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    if (n == -2147483648)
    {
        res = "-2147483648\0";
        return res;
    }
    int i = 0;
    int neg = 0;

    if (n < 0)
    {
        neg = 1;
        n = -n;
    }
    

    int d = 0;
    while (n > 0)
    {
        d = (n % base);
        res[i] = (d >= 0 && d <= 9) ? d + '0': d + 'A' - 10;

        i++;
        n = n / base;
    }
   
    if (neg)
    {
        res[i] = '-';
        i++;
        res[i] = '\0';
    }
    else 
        res[i] = '\0';

    strRev(res);

    return res;

}

 
 char *addZero(char * num)
{
   
    char * res; 
    char * str = ft_strnew(2);
    str[0] = '0';
    str[1] = '\0';
    res = ft_strjoin((char const *)str, (char const *)num);
    free(str);
    free(num);
    return res; 
}
 
 char * o_repr(t_params * params, void * content)
 {
    int long long d = (int long long) content; 
    int numDigits = getNumDig(d, 8);

    if (params->fl_sign == 1)
        params->fl_sign = -1;
    if (params->fl_space == 1)
        params->fl_space = -1;

    char *num = ft_itoa_base((long long int) content, 8);
    if (params->precision == 0 && d == 0)
    {
        num[0] = '\0';
    }

    if(params->fl_diez == 1)
        num =  addZero(num);

    if ((params->fl_align == 1 && params->fl_zeropadding == 1) || (params->precision > 0 && params->fl_zeropadding == 1))
    {
        params->fl_zeropadding = -1;
    }
     
    if(params->precision > numDigits)
        num = addZerosPrecision(num, numDigits, params->precision);

    if (params->width > (int)ft_strlen(num))
    {
        num = (params->fl_align == 1) ? addSpaces(num, params, 1): addSpaces(num, params, 0);         
    }
    
    return num; 
    
 }
 //            "args": ["\"%.d, %15.0d|\n\", 0, 0"],
