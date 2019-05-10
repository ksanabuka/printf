#include <stdio.h>
#include <stdlib.h>

typedef struct		s_arg
{
	int             qty;
    char *          str_chunk;
    t_conversion *  conv_chunk; 
	struct s_arg	*next;
}					t_arg;

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