#include "libft/libft.h"
#include <stdio.h>
int	dig_count(long long int n)
{
	long i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_positoa(long long int n)
{
	long long int	v;
	int 	count;
	char	*str;
	char	neg;

	v = n;
	neg = (v < 0 ? 1 : 0);
	count = dig_count(v);
	str = ft_strnew(count);
	if (str == 0)
		return (0);
	if (neg)
	{
		v = -v;
	}
	while (count > 0)
	{
		str[count - 1] = (v % 10) + '0';
		count--;
		v /= 10;
	}
	return (str);
}

// int main(void)
// {
//     printf("%s\n", ft_positoa(+184467440737095));
//     return 0;
// }