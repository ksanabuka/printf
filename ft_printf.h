#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>

//gcc -Wall -Werror -Wextra -g -L ./libft -lft main.c misc.c diffferent.c structures.c parcing.c d_representtion.c

typedef struct      s_conversion
{
    void * type;
    int capacity;
    int size; 
}                   t_conversion;

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

typedef struct		s_arg
{
    t_params * chunk_params;
	int             qty;
    char *          str_chunk;
    t_conversion *  conv_chunk; 
	struct s_arg	*next;
}					t_arg;

 char *extractPureS(char *s);
t_arg * add_chunk(int strORconversion, void * cont, t_arg ** head);
t_arg *initArg(void);
int ft_printf(char * fmt, ...);

 void cleanup(t_arg ** head_arg);
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
