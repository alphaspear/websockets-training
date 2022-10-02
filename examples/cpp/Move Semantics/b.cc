#include<iostream>
#include<stdio.h>
#include <cstring>
class Test
{
    public:
        Test() = default;
        Test(const char* s_variable)
        {
            std::cout<<"CREATED\n";
            m_Size = strlen(s_variable);
            m_Data = new char[m_Size];
            memcpy(m_Data, s_variable, m_Size);
        }

        Test(const Test& other)
        {
            std::cout<<"COPIED\n";
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }


        ~Test()
        {
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
}