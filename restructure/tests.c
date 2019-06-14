
#include <stdio.h>
#include <limits.h>

// int main(void)
//   {

//       char * s = "helllo";
//       int number    =  5;

    //printf("-%4d-and a-%10s-word.\n", number, pointer); // Here is a number-   5-and a-    little-word.
   // printf("-%-10d-and a-%10s-word.\n", number, pointer); // -5         -and a-    little-word.
    // printf("-%+010d-and a-%10s-word.\n", number, pointer); //  -+000000005-and a-    little-word.
  //  printf("!%-#10x!\n", number);           //      !0x5       !
 //   printf("!%#x!\n", number);              //      !0x5!
  //  printf("!%*d!\n", 6, number);            //       !     5!
   // printf("!%4.8s!\n", s); // ! hel!
    //printf("!%4.*s!\n", 5, s);            //     !helll!
   // printf(" string  %s" " digit %d", s, number );            //     !helll!
void  print_num(void* num)
{  
   printf("%llu", (long long int)num);
}  

int main() 
{ 
   //int  var = 90; 
    // scanf("%i", &a); // input is 017 (octal of 15 ) 
    // printf("%d\n", a); 
    // scanf("%i", &a); // input is 0xf (hexadecimal of 15 ) 
    // printf("%d\n", a); 
   // printf("%s, %lld", "world", (long long int)var);
    //printf("%-+20.15d", 123456789);
   //  intptr_t d = 18446744073709551615;
   // print_num((void*)d);


// printf("1%x|\n", 42);
// printf("2before %x after|\n", 42);
// printf("3%x, %x|\n", 0, 4294967294);
// printf("4{%030x}\n", 0xFFFF);
// printf("5{%030X}\n", 0xFFFF);
// printf("6%#x|\n", 42);
// printf("7%#X|\n", 42);
// printf("8%#x|\n", 0);
// printf("9%#x|\n", 2147483647);
// printf("10%.4x|\n", 42);
// printf("11%.4x|\n", 424242);
// printf("12%15.4x|\n", 42);
// printf("13%15.4x|\n", 424242);
// printf("14%8.4x|\n", 424242424);
// printf("15%4.15x|\n", 42);
// printf("16%4.15x|\n", 42424242);
// printf("17%4.8x|\n", 424242424);
// printf("18%.x, %.0x|\n", 0, 0);
// printf("19%#.x, %#.0x|\n", 0, 0);
// printf("20{%#.5x}|\n", 1);
// printf("21% x|%+x|\n", 42, 42);



// printf("%o|\n", 42);
// printf("before %o after|\n", 42);
// printf("%#o|\n", 42);
// printf("%#o|\n", 0);
// printf("%#o|\n", 2147483647);
// printf("%+o|\n", 0);
// printf("%+o|\n", 42);
// printf("%.4o|\n", 42);
// printf("%.4o|\n", 424242);
// printf("%15.4o|\n", 42);
// printf("%15.4o|\n", 424242);
// printf("%8.4o|\n", 424242424);
// printf("%4.15o|\n", 42);
// printf("%4.15o|\n", 424242);
// printf("%4.8o|\n", 424242424);
// printf("1%.o, %.0o|", 0, 0);
// printf("2%.o, %.0O|", 0, 0);
// printf("3%#.o, %#.0o|\n", 0, 0);
// printf("%#.3o|\n", 1);
// printf("%o|\n", -42);
// printf("%o|\n", 2147483647);
// printf("% o|%+o|\n", 42, 42);
// printf("%#.o|\n", 42);



// printf("{%  03d}", 0);
// printf("%+d", 42);
// printf("%+d", -42);
// printf("% d", 9999);
// printf("% d", -9999);
// printf("{% +d}", 42);
// printf("{%+ d}", 42);
// printf("{%+03d}", 0);
// printf("{% 03d}", 0);
// printf("{%0-3d}", 0);
// printf("{%+03d}", 12);
// printf("{%+03d}", 123456);
// printf("{%03.2d}", 0);
//   printf("%.4d|\n", 42);
//   printf("%.4d|\n", 424242);
//   printf("%.4d|\n", -424242);
//   printf("%15.4d|\n", 42);
//    printf("%15.4d|\n", 424242);
// printf("%8.4d|\n", 424242424);
// printf("%15.4d|\n", -42);
// printf("%15.4d|\n", -424242);
// printf("%8.4d|\n", -424242424);
// printf("%4.15d|\n", 42);
// printf("%4.15d|\n", 424242);
// printf("%4.8d|\n", 424242424);
// printf("%4.15d|\n", -42);
// printf("%4.15d|\n", -424242);
// printf("%4.8d|\n", -424242424);
// printf("%.d, %15.0d|\n", 0, 0);
// printf("%.10d|\n", -42);


// printf("%ld%ld\n", 0, 42);
// printf("%ld\n", (long)INT_MAX + 1);
// printf("%ld\n", (long)INT_MIN - 1);
// printf("%ld\n", LONG_MAX);
// printf("%ld\n", LONG_MIN);
// printf("%lld\n", LLONG_MAX);
// printf("%lld\n", LLONG_MIN);
// printf("%hd%hd\n", (short int)0, (short int)42);
// printf("%hd\n", SHRT_MAX);
// printf("%hd\n", SHRT_MIN);
// printf("%hhd%hhdv", 1, 42);
// printf("%hhd\n", CHAR_MAX);
// printf("%hhd\n", CHAR_MAX + 42);
// printf("%hhd\n", CHAR_MIN);
// printf("%hhd\n", CHAR_MIN - 42);
// printf("%hhd\n", CHAR_MAX);
// printf("%hhd\n", CHAR_MAX + 42);
 double d = 0.126;
printf("%-+10f|\n", d);
    return 0; 
} 
// ???
// -0.12345678900123449595

// -0.13
