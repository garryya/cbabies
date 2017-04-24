#include <stdio.h>

class C0
{
    virtual void f0() {}
};

class C1 : public C0
{
		int i;
	public:
		C1() : i(999) {}
		void 	f1() {}
};

class C2 : virtual public C1
{
		int j;

	public:

		C2() : C1(), j(888) {}

	virtual void f2() {}
	virtual void f3() {}
};
	

#define BINPATTERN "%d%d%d%d%d%d%d%d"
#define BINCONV(n)  \
        (n & 0x80 ? 1 : 0), \
        (n & 0x40 ? 1 : 0), \
        (n & 0x20 ? 1 : 0), \
        (n & 0x10 ? 1 : 0), \
        (n & 0x08 ? 1 : 0), \
        (n & 0x04 ? 1 : 0), \
        (n & 0x02 ? 1 : 0), \
        (n & 0x01 ? 1 : 0)

int main()
{
	C0 c0;
	C1 c1;
	C2 c2;

	printf( "C0 size = %d\n", sizeof(c0) );
	printf( "C1 size = %d\n", sizeof(c1) );
	printf( "C2 size = %d\n", sizeof(c2) );


	for( int i = 0; i < 4; i++ )
	{
		printf( "p+%d = %d\n", i, * ( (int*)((char*)&c2)+i) );
	}

    // OVERFLOW
    char sfmt[64];
    sprintf( sfmt, "%%3d: %%5d %s\n", BINPATTERN);
    printf("OVERFLOW signed\n");
    for( char i=0, iprev=0, reset=0; reset<=1; iprev=i, i++)
    {
        printf(sfmt, reset+1, i, BINCONV(i));
        if( i < iprev )
            reset++;
    }
    printf("OVERFLOW unsigned\n");
    for( unsigned char i=0, iprev=0, reset=0; reset<=1; iprev=i, i++)
    {
        printf(sfmt, reset+1, i, BINCONV(i));
        if( i < iprev )
            reset++;
    }

	return 0;
}


