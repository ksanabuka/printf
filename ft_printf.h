#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>

// gcc -Wall -Werror -Wextra -g -L ./libft -lft main.c misc.c diffferent.c structures.c parcing.c d_representtion.c x_X_repr.c o_representation.c

typedef struct		s_params
{
	int switchon_percentage;
    int fl_diez;
    int fl_sign;
    int fl_align;
    int fl_zeropadding;
    int fl_space;

    int width;
    int precision;

    int fm_l;
    int fm_ll;
    int fm_h;
    int fm_hh;
    int fm_L;

    int switchoff_format;
	
}					t_params;

 char *extractPureS(char *s);
int ft_printf(char * fmt, ...);
int getNumDig(long long int d, int base);

int validateFlags(t_params *myparams);
int checkLenModifier(t_params *myparams);
int addFlags(char *s, t_params *params);
int addFormat(char *s, t_params *params);
int skipModifier(char *s);
int addModififer(char *s, t_params *params);
int skipPrecision(char *s);
int addPrecision(char *s, t_params *params);
int skipWidth(char *s);
int addWidth(char *s, t_params *params);
int addFlag(char c, t_params *params);


char    *ft_strchr(const char *s, int c);
size_t          ft_strlen(const char *s);

char			*ft_positoa(long long int n);
 char * d_repr(t_params * params, void * content);
t_params *initChunk_params(void);


char * o_repr(t_params * params, void * content);
char *addZero(char * num);
char	*ft_itoa_base(long long int n, int base);
void strRev(char *s);



 int getSign(t_params * params, void * content);
 int getNumDig(long long int d, int base);
 char *addZerosPrecision(char * num, int numDigits, int precision);
 char *addZerosWidth(char * num, int numDigits, int width);
char *addSign(char * num, int sign);
char *addSpace(char * num);
char *addSpaces(char * num, t_params * params, int side);

char	*ft_itoa_base(long long int n, int base);

 char * x_X_repr(t_params * params, void * content);
 void toxX(t_params * params, char *s);
 char *add0x(char * num);




