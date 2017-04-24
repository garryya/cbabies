#include "factorial.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int factorial(int n)
{
    int factorial = 1;
    for( int i = 1; i <= n; i++ )
        factorial *= i;
    return factorial;
}

