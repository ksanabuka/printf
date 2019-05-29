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


 int getSign(t_params * params, long long content)
 {
    if (params->fl_sign == -1 && content >= 0)
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





 char * d_repr(t_params * params, long long d)
 {
    int numDigits = getNumDig(d, 10);
    int sign = getSign(params, d);
    char *num; 
    num = ft_positoa((long long int) d);
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





 char * f_repr(t_params * params, long double d)
 {
    int numDigits = getNumDig(d, 10);
    int sign = getSign(params, d);

    char *num = ft_positoa((long long int) d);
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