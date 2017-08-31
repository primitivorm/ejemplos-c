#include<stdio.h>
 
int Fibonacci(int);
 
int main()
{
   int n =24;
 
   /*scanf("%d",&n);*/
   /*printf("Fibonacci series\n");*/
   /*
   for ( c = 1 ; c <= n ; c++ )
   {
      printf("%d\n", Fibonacci(i));
      i++; 
   }*/
   printf("%d\n", Fibonacci(n));
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
} 
