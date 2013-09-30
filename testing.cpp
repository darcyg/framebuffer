#include "characters.h"
#include <iostream>

int main(void)
{
    std::string s;
    character c;
    s=c.A;
    std::cout<<"letter is:"<<s<<std::endl;
    
    for(auto &i:s)
    {
        std::cout<<i;
    }
    
    return 0;
    
}
