#include<bits/stdc++.h>

using namespace std;

            bool check_identifiers(string str){

                if( (str[0] >= 'a' and str[0] <= 'z' ) or (str[0] >= 'A' and str[0] <= 'Z') or (str[0] == '_')){

                    for(int i = 1; i < str.size(); i++){
                        if(str[i] == '$'){
                            return false;
                        }
                    }

                    return true;
                }

                return false;

            }

bool check_cons(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0' and str[i]<='9')
        {


        }
        else
        {
            return false;
        }
    }
    return true;
}

bool check_string(string str)
{
    int s=str.size();

    char first= str[0];
    char last= str[s -1];

    if(first == '"' and last == '"')
    {
        return true;
    }

    return false;
}


int main() {



    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }


    ifstream secondFile("keywords.txt");
    if (!secondFile.is_open()) {
        cerr << "Error opening second file." << endl;
        return 1;
    }


    ifstream thirdFile("operator.txt");
    if (!thirdFile.is_open()) {
        cerr << "Error opening third file." << endl;
        return 1;
    }

    ifstream fourthFile("punctuation.txt");



    set<string> wordSetSecond;
    set<string> wordSetThird;
    set<string> wordSetFourth;


    string line;


    while (getline(secondFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordSetSecond.insert(word);
        }
    }


    while (getline(thirdFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordSetThird.insert(word);
        }
    }

    while (getline(fourthFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordSetFourth.insert(word);
        }
    }






    set < string > keyword;
    set < string > oper;
    set < string > punc;
    set < string > cons;
    set < string > identifier;
    set < string > constant;



    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {

            if (wordSetSecond.find(word) != wordSetSecond.end())
            {

                keyword.insert(word);
            }

            else if (wordSetThird.find(word) != wordSetThird.end())
            {

                oper.insert(word);

            }

           else if( wordSetFourth.find(word)!=wordSetFourth.end())
           {
               punc.insert(word);
           }

           else
           {
               if(check_identifiers(word))
               {
                   identifier.insert(word);
               }
               else if (check_cons(word))
               {
                    constant.insert(word);
               }
               else if( check_string(word))
               {
                   constant.insert(word);
               }
           }


        }
    }

    cout<<"KEYWORDS ARE: "<<endl;

    for(auto it=keyword.begin();it!=keyword.end();it++)
    {
        cout<<*(it)<<" ";


    }

    cout<<endl;
    cout<<"\nOPERATORS ARE: "<<endl;

    for(auto it=oper.begin();it!=oper.end();it++)
    {
        cout<<*(it)<<" ";


    }

    cout<<endl;
    cout<<"\nPUNCTUATIONS ARE: "<<endl;

    for(auto it=punc.begin();it!=punc.end();it++)
    {
        cout<<*(it)<<" ";


    }



    cout<<endl;
    cout<<"\nIDENTIFIERS ARE: "<<endl;

    for(auto it=identifier.begin();it!=identifier.end();it++)
    {
        cout<<*(it)<<" ";


    }

    cout<<endl;
    cout<<"\nCONSTANTS ARE:  "<<endl;

    for(auto it=constant.begin();it!=constant.end();it++)
    {
        cout<<*(it)<<" ";

    }

    inputFile.close();
    secondFile.close();
    thirdFile.close();
    fourthFile.close();


    return 0;
}
