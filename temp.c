

void ft_printf(char *fmt, ...)
{
    va_list ap;
    char *pnt;
    char *str;
    int intgr;
    


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
           
        }
        pnt++;
    }
}


int main(void)
{
    char * s = "hello";
    double dbl = 2.3;
    int intgr = 17; 
    char c = 'z';

  //  minimal_printf("this is the string %s and a double %f and a intgr %d and a char %c", s, dbl, intgr, c);
   printf("%10.2Lf", dbl);
    return 0; 
}

// parse 
// validate_params
