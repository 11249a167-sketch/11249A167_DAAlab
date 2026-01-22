#include <stdio.h>
int main()
 {
    int n = 10;           
    int a = 0;           
    int b = 1; 
	int i;           
    int next_term;        
    printf("Fibonacci Series up to %d terms:\n", n); 
    for (i = 2; i <= n; ++i)
   {
     printf("%d, ", a); 
     next_term = a + b;
     a = b;           
     b = next_term;    
    }
    printf("\n"); 
    return 0;
}

