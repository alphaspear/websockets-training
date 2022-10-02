#include<string>
#include<iostream>

void recurse(int value)
{
    if(value==0)
        return;
    int local = value * 10;
    int * localptr = &local;
    std::cout<<std::endl<<"recurse ("<<value<<")"<<std::endl;
    for (int i = 0;i<10*(4-value);i++)
    {
        std::cout<<"* localptr: "<<localptr<<std::endl;
        localptr++;
    }
    
    recurse(value-1);
}

int main()
{
    recurse(4);
}