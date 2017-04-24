#include <stdio.h>
#include <string.h>
#include <ostream>
#include <string>
#include <iostream>

#include "factorial.h"

using namespace std;


void swap( char * s1, char * s2 )
{
    /*/
    //*s1 ^= *s2 ^= *s1 ^= *s2;
    *s1 = *s1 ^ *s2;
    *s2 = *s1 ^ *s2;
    *s1 = *s1 ^ *s2;
    /*/
    char t = *s1;
    *s1 = *s2;
    *s2 = t;
    /**/
}

int permute( char * s, int start, int end, int count )
{
    string indent = string(start+1,'\t');
    cout << indent << "PRM: " << s << ' ' << start << ' ' << end << endl;
    if( start == end )
    {
        cout << indent << s << endl;
        return ++count;
    }

    for( int i = start; i <= end; i++ )
    {
        swap( s+start, s+i );
        //cout << indent << '\t' << i << "->" << ' ' << s << ' ' << *(s+start) << ' ' << *(s+i) << endl;
        count = permute( s, start+1, end, count );
        swap( s+start, s+i );
        //cout << indent << '\t' << i << "<-" << ' ' << s << ' ' << *(s+start) << ' ' << *(s+i) << endl;
    }
    return count;
}


int main()
{
    string s;

    cout << "Enter string:" << endl;
    cin >> s;
    //s = "abc";

    cout << "String entered:" << s << endl;

    int count = permute( (char*)s.c_str(), 0, s.length()-1, 0 );
    cout << "N permutations : " << count << "(" << factorial(s.length()) << ")" << endl;

	return 0;
}


