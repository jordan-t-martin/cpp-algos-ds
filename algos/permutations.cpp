#include <iostream>
#include <string>

using namespace std;

void permutation(string str, string prefix)
{
    if(str.length() == 0) 
    {
        puts(prefix.c_str());
    }
    else
    {
        for(int i = 0; i < str.length(); i++)
        {
            string rem = str.substr(0, i) + str.substr(i+1);
            permuation(rem, prefix + str.at(i));
        }
    }
}

void permuation(string str) {
    permuation(str, "");
}

int main()
{
    permuation("hello");
}