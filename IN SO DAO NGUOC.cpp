#include <stdio.h>
int main() {
    unsigned long n ;
        scanf( "%lu", &n );
    while ( n % 10 == 0 ) n /= 10; 
          do printf( "%lu" , n % 10 ); 
          while ( n /= 10 ) ;
    return 0;
}