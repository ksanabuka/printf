#include "ft_printf.h"

t_arg *initArg(void)
{
    t_arg * arg = (t_arg *)malloc(sizeof(t_arg));
    if (!arg)
        return 0;
    arg->chunk_params = 0; 
    arg->qty = 0;
    arg->conv_chunk = 0;
    arg->next = 0;
    arg->str_chunk = 0;
    return (arg);
}

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

t_arg * add_chunk(int strORconversion, void * cont, t_arg ** head)
 {
    t_arg * el = initArg();

    if (!*head)
    {
        *head = el;

         if (strORconversion == 1)
     {
         el->str_chunk = (char*)cont;
         el->conv_chunk = 0;
         el->chunk_params = 0; 
     }
     else 
     {
         el->conv_chunk = (t_conversion *)cont;
         el->str_chunk = 0;
        el->chunk_params = initChunk_params();
     }
    }
    else 
    {
        t_arg * tmp = *head;

        while (tmp->next)
        {
            tmp = tmp->next; 
        }
        if (strORconversion == 1)
        {
            el->str_chunk = (char*)cont;
            el->conv_chunk = 0;
            el->chunk_params = 0; 
        }
        else 
        {
            el->conv_chunk = (t_conversion *)cont;
            el->str_chunk = 0;
            el->chunk_params = initChunk_params();

        }
        tmp->next = el;
    }
     return el; 
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

 void cleanup(t_arg ** head_arg)
 {
     if (!*head_arg)
        return;
    else 
     return ;
 }