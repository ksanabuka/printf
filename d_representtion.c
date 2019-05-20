(l, ll, h, hh) -> (format)va_arg;
 
 int getSign(t_arg * arg, void * content)
 {
    if (arg->sign == -1)
        return 0; 
    else if ((long long int)content >= 0)
        return '+';
    else  
        return '-';
 }

  

 void d_repr(t_arg * arg)
 {
    check width -> create canvas;

    fill with filler; 
    put sign at the begining
    adjust precision; 
    apply lenmodifier; 

if (arg->width)
{
    if (width == 0 || width == -1)
        return 0; 
    else
    {
        char * canvas = (char*)malloc(sizeof(char) * (width + 1));
    }
    
}
   
 
     
 
 }