#include "ft_printf.h"

 

t_params *initChunk_params(void)
{
    t_params * chunk_params = (t_params *)malloc(sizeof(t_params));
    if (!chunk_params)
        return 0;
    chunk_params->switchon_percentage = -1;
    chunk_params->fl_diez = -1;
    chunk_params->fl_sign = -1;
    chunk_params->fl_align = -1;
    chunk_params->fl_zeropadding = -1;
    chunk_params->fl_space = -1;

    chunk_params->width = -1;
    chunk_params->precision = -1;

    chunk_params->fm_l = -1;
    chunk_params->fm_ll = -1;
    chunk_params->fm_h = -1;
    chunk_params->fm_hh = -1;
    chunk_params->fm_L = -1;

    chunk_params->switchoff_format = -1;
    
    return (chunk_params);
}

 char *extractPureS(char *s)
 {
     int i = 0;
     int j = 0; 
     char * res;
     if (s[i] && s[i] == '%')
     {
         res = (char *)malloc(sizeof(char) * 2);
         res[0] = '%';
         res[1] = '\0';
         return res;
     }
     else if (s[i] && s[i] != '%')
     {
         while (s[i] && s[i] != '%')
         {
             i++;
         }
         res = (char *)malloc(sizeof(char) * (i + 1));
         res[i] = '\0';
         while (j < i)
         {
             res[j] = s[j];
             j++;
         }
         return res; 
     }
     else 
        return 0; 
 }

 