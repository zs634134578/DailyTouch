/*
如下为类CMyString的声明，请为该类型添加赋值运算符函数。
*/


#include <iostream>
#include <string.h>

class CMyString {
public:
    CMyString(char* pData=NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    
    void printData();
    CMyString& operator=(const CMyString& str);

private:
    char* m_pData;
};

CMyString::CMyString(char* pData) {
    if ( pData == NULL ) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str) {
    if ( this == &str )
        return;
    int len = strlen(str.m_pData);
    m_pData = new char[len+1];
    strcpy(m_pData, str.m_pData);
}

CMyString& CMyString::operator=(const CMyString& str)
{
    if ( this != &str )
    {
        CMyString tmpStr(str);
        char* tmp = str.m_pData;
        tmpStr.m_pData = m_pData;
        m_pData = tmp;
    }
    return *this;
}

CMyString::~CMyString(void) 
{
    delete[] m_pData;
}

void CMyString::printData() {
    std::cout << m_pData << std::endl;
}

void test1() {
    CMyString* cms = new CMyString("Hello test1");
    cms->printData();
}

void test2() {
    CMyString* cms = new CMyString("Hello test2");
    CMyString cms2 = *cms;
    cms2.printData();
}


int main()
{
    test1();   
    test2();
}
