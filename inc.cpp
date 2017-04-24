#include <stdio.h>
#include <string>
#include <stdlib.h>


void inc(std::string& s)
{
    printf("%s ", s.c_str());

    int i = s.length()-1;
    for( ; i >= 0 ; i-- )
    {
        int nDigit = s[i] - '0';
        s[i] = '0';
        if( nDigit + 1 <= 9 )
        {
            s[i] += nDigit + 1;
            break;
        }
    }
    if( i < 0 )
        s = std::string("1") + s;
    inc( s );
}
int main()
{
    std::string s("0");
    inc(s);
}

