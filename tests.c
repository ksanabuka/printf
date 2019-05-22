
#include <stdio.h>
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
  

printf("{%  03d}", 0);
// printf("%+d", 42);
// printf("%+d", -42);
// printf("% d", 9999);
// printf("% d", -9999);
// printf("{% +d}", 42);
// printf("{%+ d}", 42);
// printf("{%+03d}", 0);
printf("{% 03d}", 0);
printf("{%0-3d}", 0);
printf("{%+03d}", 12);
printf("{%+03d}", 123456);
printf("{%03.2d}", 0);


printf("\nPASSED\n");
  printf("%.4d|\n", 42);
  printf("%.4d|\n", 424242);
  printf("%.4d|\n", -424242);
  printf("%15.4d|\n", 42);
   printf("%15.4d|\n", 424242);
printf("%8.4d|\n", 424242424);
printf("%15.4d|\n", -42);
printf("%15.4d|\n", -424242);
printf("%8.4d|\n", -424242424);
printf("%4.15d|\n", 42);
printf("%4.15d|\n", 424242);
printf("%4.8d|\n", 424242424);
printf("%4.15d|\n", -42);
printf("%4.15d|\n", -424242);
printf("%4.8d|\n", -424242424);
printf("%.d, %15.0d|\n", 0, 0);
printf("%.10d|\n", -42);






    return 0; 
} 


//%#.x, %#.0x
  