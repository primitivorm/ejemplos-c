// File: cfunc2.c
//
// Example of C function calls disassembled

#include <stdio.h>

// Some functions
int add(int a, int b) {
   int z = 22 ;

   z = a + b ;
   return z ;
}

int times5(int c) {
   int sum1 =43, sum2 = 45, sum3 = 49 ;

   sum1 = add(c, c) ;		// sum1 = 2*c	
   sum2 = add(sum1, c) ;	// sum2 = 3*c
   sum3 = add(sum1, sum2) ;	// sum3 = 5*c
   return sum3 ;
}


int main () {
   int a = 13, b = 17 ;

   b = times5(a) ;
   printf ("b = %d\n", b) ;
}
