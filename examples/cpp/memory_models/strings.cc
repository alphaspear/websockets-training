#include<iostream>
// #include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

// int main() { 
//   char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
//   // string s = {'h', 'e', 'l', 'l', 'o'};
//   cout << strlen(s) << "\n";
//   // cout << s << "\n"; // TODO: Figure out why garbage end characters?!
//   cin >> s; // TODO: HOW!? Heap!? How is it free-ed!?
//   // scanf("%s", s); // TODO: HOW!?
//   cout << "Input read:" << s << "\n";
//   cout << strlen(s) << "\n";

//   return 0;
// }

int main(int argc, char const *argv[])
{
  //char name2[8]={'a','b','h','i','l','a','s','h'};
  //cout<<name2<<endl<<strlen(name2)<<endl;
  //cin>>name2;
  //cout<<name2<<endl<<strlen(name2)<<endl;
  //return 0;
  string name = "Abhilash"; 
  cout<<endl<<name.max_size()<<endl;
  cout<<name<<endl<<name.size()<<endl;
  cin>>name;
  cout<<name<<endl<<name.size()<<endl;

  
}

//using namespace std;

