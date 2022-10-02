#include<iostream>
#include<stdio.h>
#include <cstring>
class Test
{
    public:
        Test() = default;
        Test(const char* string)
        {
            std::cout<<"CREATED\n";
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            memcpy(m_Data, string, m_Size);
        }

        Test(const Test& other)
        {
            std::cout<<"COPIED\n";
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }

        Test(Test&& other) noexcept
        {
            std::cout<<"MOVED\n";
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            
            other.m_Size=0;
            other.m_Data=nullptr;
        }

        ~Test()
        {
            std::cout<<"DESTROYED "<<m_Size<<"\n";
            delete m_Data;
        }

        void Print()
        {
            for (uint32_t i = 0; i < m_Size; i++)
            {
                printf("%c", m_Data[i]);
            }
            printf("\n");
            
        }

    private:
        char* m_Data;
        uint32_t m_Size;

};

class Entity
{
    public:
        Entity(const Test& name)
            : m_Name(name)
        {
        }

        Entity(Test&& name)
            //m_Name(name)//this is used to call copy contructor
            //: m_Name((Test&&)name)//use this syntax and below syntax to call 
            // the move constructor
            : m_Name(std::move(name))//works both ways
        {
        }

        void PrintName()
        {
            m_Name.Print();
        }
    private:
        Test m_Name;
};

int main()
{
    Entity entity(Test("Abhilash"));
    entity.PrintName();
    std::cin.get();
    // Test* t1 = new Test("Abhilash");
    // t1->Print()
    // std::cin.get();
}