#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>
#include <memory>
#include <stdarg.h>

/**
 * CFmtString - class implementing resizable string with va-format capabilities
 */
class CFmtString
{
public:
    CFmtString(int nInitialSize = 1024) 
            : m_nSize(nInitialSize), m_bResized(false) { alloc(); }
    
    const char * get() const { return m_ptrStr.get(); }
    size_t size() const { return m_nSize; }
    size_t length() const { return strlen(m_ptrStr.get()); }

    void format(const char* fmt, va_list ap) 
    {
        va_list ap2;
        va_copy(ap2, ap);
        size_t nRequired = vsnprintf(m_ptrStr.get(), m_nSize, fmt, ap);
        m_bResized = nRequired >= m_nSize;
        if(m_bResized)
        {
            resize(nRequired * 1.33f); // resize to required+30%
            nRequired = vsnprintf(m_ptrStr.get(), m_nSize, fmt, ap2);
        }
        va_end(ap2);
    }
    void format(const char * fmt, ...)
    {
        va_list ap;
        va_start(ap, fmt);
        format(fmt, ap);
        va_end(ap);
    }
    friend std::ostream& operator<<(std::ostream& os, const CFmtString& s)
    {
        os << "|" << s.get() << "| s=" << s.size() << " l=" << s.length();
        if(s.m_bResized)
            os << " RESIZED";
        return os;
    }

protected:
    typedef std::auto_ptr<char> CPtr;
    size_t m_nSize;
    CPtr m_ptrStr;
    bool m_bResized;

    void alloc()
    {
        m_ptrStr = CPtr(new char [m_nSize]);
        memset(m_ptrStr.get(), 0, m_nSize);
    }
    void resize(size_t nSize)
    {
        if(nSize <= m_nSize)
            return;
        m_nSize = nSize;
        alloc();
    }
};

class CFmtStringSafe
{
public:
    ~CFmtStringSafe() { delete ps; }
    CFmtString& operator*() { return *_get();}
    CFmtString* operator->() { return _get();}
private:
    static __thread CFmtString * ps;
    static CFmtString * _get()
    {
        if(!ps) 
            ps = new CFmtString();
        return ps;
    }
};
__thread CFmtString * CFmtStringSafe::ps = 0;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

CFmtStringSafe msgbuf;

void va_test(const char * fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    msgbuf->format(fmt, ap);
    std::cout << *msgbuf << std::endl;
    va_end(ap);
}

void test(const char * s, bool empty_format=false)
{
    static int i = 0;
    if(!empty_format)
        va_test("TEST %d %s", ++i, s);
    else
        va_test("");
}


int __main(int argc, const char ** argv)
{
    int i = 0;
    
    test("1234567890");
    test("1");
    test("12345");
    test("1");
    test("12345678901");
    test("1");
    test("123456789012");
    test("12345");
    test("1");
    test("1234567890123");
    test("12345");
    test("1");
    test("123456789012345");
    test("");
    test("aa");
    test("", true);
    return 0;
}


int main(int argc, const char ** argv)
{
    std::cout << atoi("e1e1e1e1e11e") << std::endl;
    std::cout << atoi("1454551900");
    
    printf("%% -> %ld %S\n", 2, "", 34324243);

    return 0;
}
