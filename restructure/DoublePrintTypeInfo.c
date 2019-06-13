#include "libft.h"
#include "DoublePrintTypeInfo.h"


static char get_sign(long double value, const struct FormatParams *fmt_params) {
    if (value < 0) {
        return '-';
    }
    return fmt_params->flags & F_PLUS ? '+' : 0;
}

static void abs_integral_quotient_to_digits(char *digits, long double value) {
    int i;
    long long d = (long long)value;
    
    i = 0;
    while (value)
    {
        d = value - (value / 10) * 10;
        d = d < 0 ? -d : d;
        digits[i] = d + '0';
        value /= 10;
        ++i;
    }
    digits[i] = 0;
    reverse_str(digits);
}

static void abs_integral_and_fractural_join(char *digits, long double value, const struct FormatParams *fmt_params) {
  
    {
        char * res;
        char * tmp = ft_strnew(0);
        value = (value < 0) ? -value : value;
        char * fracturial_part =  fracture_part(&value, fmt_params);
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

}



struct PrintTypeInfo create_int_print_type_info(void *value_ptr, const struct FormatParams *fmt_params) {
    struct PrintTypeInfo res;
    long long value;
    
    value = *(long long *)value_ptr;
    res.sign = get_sign(value, fmt_params);
    res.value_str = ft_strnew(LONG_LONG_BITS);
    res.free_value_str = 1;
    abs_ll_to_digits(res.value_str, value, fmt_params->precision);
    ft_strcpy(res.prefix, "");
    res.num_leading_zeros = 0;
    if (fmt_params->precision > (int)ft_strlen(res.value_str)) {
        res.num_leading_zeros = fmt_params->precision - (int)ft_strlen(res.value_str);
    }
    res.leading_zeros_allowed = fmt_params->precision < 0;
    return res;
}
