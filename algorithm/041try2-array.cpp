/*
 * 5.下面程序执行结果为【说明：x86_64环境】
 * [cpp] view plaincopy
 * int a[4][4] = {  
 *     {1,2,3,4},  
 *         {50,60,70,80},  
 *             {900,1000,1100,1200},  
 *                 {13000,14000,15000,16000}  
 *                 };  
 *                 int (*p1)[4] = a;  
 *                 int (*p2)[4] = &a[0];  
 *                 int *p3 = &a[0][0];  
 *                   
 *                   printf("%d, %d, %d, %d\n",  
 *                       *(*(a+1)-1),  
 *                           *(*(p1+3)-2)+1,  
 *                               *(*(p2-1)+16)+2,  
 *                                   *(p3+sizeof(p1)-3)  
 *                                       );  
 */

#include "stdio.h"
#include <iostream>
#include<memory>
#define debugch(x) std::cout << "(debugch):" << x << std::endl;
int main()
{
    /*
    int a[4][4] = {  
        {1,2,3,4},  
        {50,60,70,80},  
        {900,1000,1100,1200},  
        {13000,14000,15000,16000}  
    };  
    int (*p1)[4] = a;  
    int (*p2)[4] = &a[0];  
    int *p3 = &a[0][0];  

    printf("%d, %d, %d, %d\n",  
            *(*(a+1)-1),  
            *(*(p1+3)-2)+1,  
            *(*(p2-1)+16)+2,  
            *(p3+sizeof(p1)-3)  
          );  
    */
    char *str[] = {"one", "two", "three"};
    char **p = str;
    debugch(**p);
    debugch(**(p+1));
    debugch(**str);
    printf("%c\n", **str);
    debugch(*(str+1)[0]);
}
/*
class A
{
    public:
        virtual void foo(){}
};
class B
{
    public:
        virtual void foo(){}
};
class C:public A, public B
{
    public:
        virtual void foo(){}
};
void bar1(A *pa)
{
        B *pc = dynamic_cast<B*>(pa);
}
void bar2(A *pa)
{
        B *pc = static_cast<B*>(pa);
}
void bar3()
{
        C c;
            A *pa = &c;
                B *pb = static_cast<B*>(static_cast<C*>(pa));
}
*/
