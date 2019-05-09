#include <stdio.h>

typedef struct		s_chunks
{
	int             qty;
    t_string        pure_str;
    t_conversion    arg; 
	struct s_chunks	*next;
}					t_chunks;


typedef struct      s_string
{
    char *s;
    int capacity;
    int size;
}                   t_string;

typedef struct      s_conversion
{
    void * type;
    int capacity;
    int size; 
}                   t_conversion;

typedef struct		s_params
{
    t_string s; 

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