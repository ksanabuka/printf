#include "ft_printf.h"

int main(int ac, char **av)
{
    t_arg * head_arg = 0;
    ac = 0;

    int status = parseStr(av[1], &head_arg);
    printf("%d\n", status);
    return 0;
}