#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void minimal_printf(char *fmt, ...)
{
    va_list ap;
    char *pnt;
    char *str;
    int intgr;
    double dbl;
    char chr;


    va_start(ap, fmt); // put ap at the place after first known arg 

    pnt = fmt; 
    char c; 

    while (*pnt)
    {
        if (*pnt != '%')
        {
            c = *pnt; 
            write(1, &c, 1);
            pnt++;
            continue; 
        }
        else 
        {
            pnt++;
            if (*pnt == 'd')
            {
                intgr = va_arg(ap, int);
                printf("%d\n", intgr);

            }
            else if (*pnt == 'c')
            {
                chr = va_arg(ap, int);
                printf("%c\n", chr);
            }
            else if (*pnt == 'f')
            {
                dbl = va_arg(ap, double);
                printf("%f\n", dbl);
            }
            else if (*pnt == 'c')
            {
                dbl = va_arg(ap, double);
                printf("%f\n", dbl);
            }
            else if (*pnt == 's')
            {
                str = va_arg(ap, char *);
                printf("%s\n", str);
            }
            else
            {
                c = *pnt; 
                write(1, &c, 1);
            }
        }
        pnt++;
    }
}


int main(void)
{
    char * s = "hello";
    double dbl = 2.3;
    int intgr = 7; 
    char c = 'z';

  //  minimal_printf("this is the string %s and a double %f and a intgr %d and a char %c", s, dbl, intgr, c);
   printf("this is the string %-00s and a double %#f and a intgr %-d and a char %-c", s, dbl, intgr, c);
    return 0; 
}

// parse 
// validate_params
