/*
 *
 *
 */


#include <iostream>
#include <string>

using namespace std;

#define debug2(x, y) std::cout << "(debug)" << x << y << std::endl;
#define debug(x) std::cout << "(debug)" << x << std::endl;

class LCSer
{
public:
    LCSer(char* a, int alen, char* b, int blen)
    {
       this->a = a;
       this->b = b;
       this->alen = alen;
       this->blen = blen;
    }

    void getLCS(char* result)
    {
        int c[alen][blen];
        for(int i=0; i < alen; i++)
        {
            for(int j = 0; j < blen; j++)
            {
                if (i==0 || j==0)
                {
                    if (this->a[i] == this->b[j])
                        c[i][j] = 1;
                    else
                        c[i][j] = 0;
                }
                else
                {
                    if (this->a[i] == this->b[j])
                    {
                        c[i][j] = c[i-1][j-1] + 1;
                    }
                    else
                        c[i][j] = 0;
                }
            }
        }
        int maxlen = 0;
        for(int i=0; i<alen; i++)
            for(int j=0; j<blen; j++)
                if (c[i][j] > maxlen)
                    maxlen = c[i][j];
        std::cout << "max lenght: " << maxlen << std::endl;
    }


    void printStr(char* str)
    {
        std::cout << str << std::endl;
    }
private:
    char* a;
    char* b;
    int alen;
    int blen;
    int indexStart;
    int indexEnd;
};



int main()
{
    char a[14] = "aocdfacddcdfe";
    char b[11] = "pmcdfacdfe";
    LCSer* lcser = new LCSer(a,13, b, 10);
    char result[11];
    lcser->getLCS(result);
    debug("Hello world"); 
    return 0;
}
