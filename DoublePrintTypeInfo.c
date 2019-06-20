/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoublePrintTypeInfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:49:12 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:49:15 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoublePrintTypeInfo.h"
#include "libft.h"

static char get_sign(long double value, const struct fmt_pms *fmt_params)
{
    if (value < 0)
{
        return '-';
    }


    return fmt_params->flags & F_PLUS ? '+' : 0;
}



char* abs_integral_quotient_to_digits(char *digits, long double value) 
{
    int i;
    long long integral_part;
    char d; 
    
    integral_part = (long long)value;
    if (integral_part == 0)
   
{
        digits[0] = '0';
        return (digits); 
    }


    i = 0;
    while (integral_part)
   
{
        d = (integral_part - (integral_part / 10) * 10);
        d = d < 0 ? -d : d;
        digits[i] = d + '0';
        integral_part /= 10;
        ++i;
    }


    digits[i] = 0;
    reverse_str(digits);
    return (digits);
}


static char * rounding(char * s)
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


char *fracture_part(long double * value, const struct fmt_pms *fmt_params)
{
    char * res;
    char * tmp; 
    char * str;
    if (fmt_params->precision == 0)
   
{    
       str = ft_strnew(0);
       return str;
    }


    str = ft_strnew(17);
    int i = 0; 
    long double aftercoma = *value - (long long)(*value);
    while (42)
   
{
        if (fmt_params->precision != -1 && i == fmt_params->precision + 1)
            break;
        if (aftercoma == 0 || (fmt_params->precision == -1 && i == 7) || i == 17)
            break; 
        if ((int) (aftercoma * 10) == 0 && aftercoma != 0)
       
{
            str[i] = '0';
        }


        else 
       
{
            str[i] = (int) (aftercoma * 10) + '0';
        }


        aftercoma = aftercoma * 10 - (int) (aftercoma * 10);
        i++; 
    }


    str = rounding(str);
    if (!str)
   
{
        *value = *value + 1; 
        if (fmt_params->precision == 0)
       
{
           str = ft_strnew(0);
                // str = createStr0(1);
            // str[0] = '\0'; 
        }


        else if (fmt_params->precision == -1)
       
{
            str = createStr0(6);
        }


        else if (fmt_params->precision > 0)
       
{
            str = createStr0(fmt_params->precision);
        }


     }


    if (fmt_params->precision > 0 && (int)ft_strlen(str) < fmt_params->precision)
   
{
        int len1 = fmt_params->precision - (int)ft_strlen(tmp);
        tmp = createStr0(len1);
        res = tmp; 
        str = ft_strjoin(str, tmp);
        free(res);
        free(tmp);
    }


    if (ft_strlen(str) < 6 && fmt_params->flags & F_DIEZ)
   
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



static char * abs_integral_and_fractural_join(long double value, const struct fmt_pms *fmt_params)
   
{
        char * tmp;
        char * fracturial_part;
        char * integral_part;
        char * digits = ft_strnew(64);
        value = (value < 0) ? -value : value;
        fracturial_part =  fracture_part(&value, fmt_params);
        integral_part = abs_integral_quotient_to_digits(digits, value);
        if (fracturial_part[0] != '\0' && fmt_params->precision != 0)
       
{
            tmp = ft_strnew(1);
            tmp[0] = '.';
            integral_part = digits; 
            digits = ft_strjoin(digits, tmp);
            free(integral_part);
            free(tmp);
        }


            integral_part = digits; 
            digits = ft_strjoin(digits, fracturial_part);
            free(integral_part);
            free(fracturial_part);
            return digits;  
}



struct pt_inf create_realpti(void *value_ptr, const struct fmt_pms *fmt_params) 
{
    struct pt_inf res;
    long double value;
    
    value = *(long double *)value_ptr;
    res.type = PT_REAL;
    res.sign = get_sign(value, fmt_params);
    res.value_str =  abs_integral_and_fractural_join(value, fmt_params);
    res.free_value_str = 1;
    
    ft_strcpy(res.prefix, "");
    res.num_leading_zeros = 0;
    if (fmt_params->flags & F_MINUS && fmt_params->flags & F_ZERO)
{
        res.leading_zeros_allowed = 0;
    }


    res.leading_zeros_allowed = 1;
    return res;
}


