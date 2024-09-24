//1308 1605
#include<iostream>
#include<vector>
#include<fstream>    //for classes i/o of file
/*
   1.fstreambase
   2.ifstream ->derived from fstreambase
   3.ofstrea ->derived from fstreambase
   2 way to open file 1.) using constructor  2.) using the member function open() of the class
*/
using namespace std;
int main()
{
       ifstream read("smaple.txt");   //write operation
      // ifstream read("sample1.txt"); //read operation 
       string str;
          // out<<str;
       read>>str; //only one word 
       cout<<str;
       getline(read,str);
       cout<<str;
       getline(read,str);
       cout<<str;
       getline(read,str);
       cout<<str;
       return 1;


};