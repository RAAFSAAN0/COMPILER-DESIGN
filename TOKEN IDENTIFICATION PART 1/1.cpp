#include<iostream>
using namespace std;

bool check(string s)
{

    for(int i=0;i<s.size();i++)
    {
        if(s>="0"&&s<="9")
    {


    }

    else if(s[i]>='A'&&s[i]<='Z'&&s[i]>='a'&&s[i]<='z')
    {


       return false;
    }
    return true;


    }}

int main()
{

    string s;
    cin>>s;
    if(check(s)==true)
    {

        cout<<"Numeric constant";
    }
    else{
        cout<<"Not numeric constant";
    }
}
