#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+')
            {

            cout<<"operator: +"<<endl;
             }


             else if(s[i]=='-')
             {
                 cout<<"operator: -"<<endl;
             }
             else if(s[i]==',')
             {
                 cout<<"operator: ,"<<endl;
             }
             else if(s[i]=='%')
             {
                 cout<<"operator: %"<<endl;
             }
             else if(s[i]=='=')
             {
                 cout<<"operator: ="<<endl;
             }
              else if(s[i]=='/')
             {
                 cout<<"operator: /"<<endl;
             }




       }




}
