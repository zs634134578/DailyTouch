#include <iostream>
#include <vector>
#include "stdlib.h"
#include <sstream>

using namespace std;

class Solution 
{
public:
    Solution(){};
    ~Solution() {}
 
    int evalRPN(vector<string> &tokens);
    int findop(string op);


    string int2str(double &i){
        string s;
        stringstream ss(s);
        ss << i;

        return ss.str();
    }
};

int Solution::evalRPN( vector<string> &tokens ) 
{
    double result = 0;

    if ( tokens.empty() ) 
        return result;
    
    result = atoi(((string)tokens[0]).c_str());
    vector<string> pTokens(tokens);
    
    for ( vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        int op;
        
        if ( op = this->findop(*it)  )
        {
            int firstNum = atoi((*(it-2)).c_str());
            int secondNum = atoi((*(it-1)).c_str());
            switch(op){
                case 1: result = firstNum + secondNum; break;
                case 2: result = firstNum - secondNum; break;
                case 3: result = firstNum * secondNum; break;
                case 4: result = firstNum / secondNum; break;
                default: return -1;
            }
            *it = int2str(result);
            tokens.erase(it-2, it);
            it = tokens.begin();
        }
    }
    return result;    
}

int Solution::findop( string op ) {
    if ( op == "+" ) return 1;
    else if ( op == "-" ) return 2;
    else if ( op == "*" ) return 3;
    else if ( op == "/" ) return 4;
    else return 0;
}



int main()
{
    vector<string> data;
    data.push_back("-5");
    data.push_back("1");
    data.push_back("2");
    data.push_back("+");
    data.push_back("4");
    data.push_back("*");
    data.push_back("+");
    data.push_back("3");
    data.push_back("/");
    Solution* solver = new Solution();
    std::cout << solver->evalRPN(data) << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}
