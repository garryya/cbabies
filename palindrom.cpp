#include <stdio.h>
#include <string.h>
#include <ostream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void make_palindrom( const char * s, string& spc )
{
    int l = strlen(s);
    //cout << "\t" << s << ":" << spc << " l=" << l << endl;
    if( !s || l <= 1 )
        return;
    for( const char * s1 = s, * s2 = &s[l-1]; *s1 && *s2 && s1 <= s2; s1++, s2-- )
    {
        if( *s1 != *s2 )
        {
            spc = *s + spc; //TODO - bad, maybe reverse at the end
            make_palindrom( s+1, spc);
            //reverse(spc.begin(),spc.end());
            break;
        }
    }
}

int main( int argc, const char * argv[] )
{
    string s = "abcdfc", spc;

    if( argc > 1 )
        s = argv[1];
    else
    {
        cout << "Enter string:" << endl;
        cin >> s;
    }

    cout << "String to 'palindrom':" << s << endl;

    make_palindrom( s.c_str(), spc );
    cout << "added = " << spc.length() << " chars: " << s << "+" << spc << endl;

	return 0;
}


