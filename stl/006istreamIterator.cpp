#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<list>
using namespace std;

void test1()
{
   istream_iterator<string> inIt(cin), eof;
   vector<string> svec;

   while(inIt!=eof)
   {
       svec.push_back(*inIt++);
   }

   for(vector<string>::iterator it=svec.begin(); it!=svec.end(); it++)
   {
       std::cout << *it << std::endl;
   }

}

void test2()
{
    ifstream dataFile("test.txt", ifstream::in);
    list<int> data((istream_iterator<int>(dataFile)),
        istream_iterator<int>());
    list<int>::iterator it = data.begin();
    while(it!=data.end())
    {
        std::cout << *it++ << std::endl;
    }
}


int main()
{
    //test1();
    test2();
    std::cout << "Hello world!"<< std::endl;
    return 0;
}
