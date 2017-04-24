#include <stdio.h>
#include <string.h>
#include <ostream>
#include <string>
#include <iostream>

using namespace std;


int strstr1( const char * s1, const char * s2 )
{
    const char * s2last = &s2[strlen(s2)-1];
    int s2len = strlen(s2);
    for( const char * ss1 = s1, * s1last = &s1[strlen(s1)-1]; *ss1 && ss1+s2len-1<=s1last; ss1++ )
    {
        cout << ss1 - s1 << " : " << *ss1 << endl;
        const char * ss1aux = ss1;
        for( const char * ss2 = s2; *ss1aux && *ss2 && *ss1aux == *ss2; ss1aux++, ss2++)
        {
            if( ss2 == s2last )
                return ss1 - s1;
        }
        ss1 = ss1aux;
    }

    return -1;
}


int main()
{
    string s1, s2;

    cout << "Enter strings:" << endl;
    cin >> s1;
    cin >> s2;

    cout << "Strings entered:" << endl << s1 << endl << s2;

    int idx = strstr1( s1.c_str(), s2.c_str() );
    if( idx != -1 )
        cout << "Found idx=" << idx << endl;
    else
        cout << "NOT Found" << endl;

	return 0;
}


