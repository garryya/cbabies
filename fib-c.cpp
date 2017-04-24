#include <stdio.h>
#include <string.h>
#include <ostream>
#include <string>


class FibonacciBase
{
    protected:
        const char * m_szTitle;
    public:
        FibonacciBase(const char * szTitle) :
            m_szTitle(szTitle)
        {}
        virtual ~FibonacciBase() {}
        virtual void calc( int n ) = 0;
};

class FibonacciWithAlloc: public FibonacciBase
{
    protected:
        unsigned int * m_pFibonacci;
    public:
        FibonacciWithAlloc(const char * szTitle) :
            FibonacciBase(szTitle),
            m_pFibonacci(NULL)
        {}
        virtual ~FibonacciWithAlloc()
        {
            delete [] m_pFibonacci;
        }
        virtual void calc( int n )
        {
            init( n );
            doCalculate( n );
        }
        virtual void print( int n )
        {
            printf("fibonacci %16s : ", m_szTitle);
            for( int i = 0; i < n; i++ )
                printf("%6d%c", m_pFibonacci[i], i<n-1?' ':'\n' );
        }

    protected:

        virtual int doCalculate( int n ) = 0;

    private:

        void init( int n )
        {
            if( ! m_pFibonacci )
               m_pFibonacci = new unsigned int [n];
            memset( m_pFibonacci, -1, n*sizeof(int));
        }
};

class FibonacciLoop : public FibonacciWithAlloc
{
    public:
        FibonacciLoop() :
            FibonacciWithAlloc("LOOP")
        {}

    protected:
        virtual int doCalculate( int n )
        {
            for( int i = 0; i <= n; i++ )
                m_pFibonacci[i] = i > 1 ? m_pFibonacci[i-2] + m_pFibonacci[i-1] : 1;
            return -1;
        }
};

int main()
{
    printf("enter n:");
    int n;
    scanf( "%d", &n);

    FibonacciLoop f;
    f.calc(n);
    f.print(n);

	return 0;
}


