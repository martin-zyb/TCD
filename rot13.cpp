#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    int temp;
    string str;
    while(true)
    {
        putchar('>');
        getline(cin,str);
        if(str == "exit") break;
        if(str == "clean")
        {
            clrscr();
            continue;
        }
        for(int i = 0; i < str.length(); ++i)
        {
            temp = char(str[i]);
            if(temp >= 65 && temp <= 90)
            {
                temp += 13;
                if(temp > 90)
                {
                    temp -= 26;
                }
            }
            if(temp >= 97 && temp <= 122)
            {
                temp += 13;
                if(temp > 122)
                {
                    temp -= 26;
                }
            }
            str[i] = char(temp);
        }
        puts(str.c_str());
        putchar('\n');
    }
    clrscr();
    return 0;
}
