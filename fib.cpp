#include <stdio.h>
#include <string.h>
#include <ostream>
#include <string>

int fib_loop( int n, int * pFib )
{
    for( int i = 0; i <= n; i++ )
        pFib[i] = i > 1 ? pFib[i-2]+pFib[i-1] : 1;
    return -1;
}

int fib_recursion_dumb( int n, int * pFib )
{
    int fibn = 1;
    if( n > 1 )
        fibn = fib_recursion_dumb(n-1, pFib) + fib_recursion_dumb(n-2, pFib);
    pFib[n] = fibn;
    return fibn;
}

int fib_recursion_nodumb( int n, int * pFib )
{
    if(n < 0)
        return 1;
    fib_recursion_nodumb(n-1, pFib);
    if(n <= 1)
        pFib[n] = 1;
    else
        pFib[n] = pFib[n-2] + pFib[n-1];
    return 1;
}

unsigned long long fib_recursion_nodumb2( int n )
{
    if(n < 0)
        return 0;
    int shift = sizeof(long) * 8;
    unsigned long long r = fib_recursion_nodumb2(n-1);
    unsigned long n2 = r >> shift;
    unsigned long n1 = (r << shift) >> shift;
    unsigned long fibn = 1;
    if(n > 1)
        fibn = n2 + n1;
    printf("%6lu ", fibn);
    //printf("%d:(%lu, %lu, %lu)  ", n, fibn, n2, n1);
    return (unsigned long long)(n1) << shift | (unsigned long long)fibn;
}

typedef int (*pfFibonacci)(int, int*);

template <pfFibonacci fibonacci>
void getFibonacci(int n, const char * szName)
{
    int * pFib = new int [n];
    memset( pFib, -1, n*sizeof(int));
    printf("fibonacci %16s : ", szName);
    fibonacci(n-1, pFib);
    for( int i = 0; i < n; i++ )
        printf("%6d%c", pFib[i], i<n-1?' ':'\n' );
    delete [] pFib;
}

void getFibonacci2(int n, const char * szName)
{
    printf("fibonacci %16s : ", szName);
    fib_recursion_nodumb2(n-1);
    printf("\n");
}


int main()
{
    printf("enter n:");
    int n;
    scanf( "%d", &n);

    getFibonacci<fib_loop>(n, "LOOP1");
    getFibonacci<fib_recursion_dumb>(n, "RCRSV (dumb)");
    getFibonacci<fib_recursion_nodumb>(n, "RCRSV (no-dumb)");
    getFibonacci2(n, "RCRSV (no-dumb2)");

	return 0;
}


