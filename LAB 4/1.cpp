#include<bits/stdc++.h>
using namespace std;

void countOperators(const string line,unordered_map<string,int>&countOp)
{
    string operators = "+-*/%=><!&|^";
    for(char op:operators)
    {
        size_t position=line.find(op);
         while (position != string::npos)
        {
            string operatorStr(1, op);
            countOp[operatorStr]++;
            position = line.find(op, position + 1);
        }

    }
}

int main()
{
    ifstream file("Program.cpp");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    else
    {
        cout<<"FILE OPENED SUCCESFULLY"<<endl;
    }

    unordered_map<string, int> operatorCounts;

    string line;
    while (getline(file, line))
    {
        countOperators(line, operatorCounts);
    }



    cout<<"\nTHE OPERATORS ARE: "<<endl;
    for (unordered_map<string, int>::iterator it = operatorCounts.begin(); it != operatorCounts.end(); ++it)
    {

        cout << it->first << ": " << it->second << endl;
    }

}
