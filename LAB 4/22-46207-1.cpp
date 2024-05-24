#include <bits/stdc++.h>


using namespace std;

void userDefinedFunctionDetect(const string& line, unordered_set<string>& functionNames)
{
    size_t position = line.find("(");
    if (position != string::npos)
    {
        size_t start = line.rfind(" ", position);
    if (start != string::npos) {
        string functionName = line.substr(start + 1, position - start - 1);
    if (functionName != "main")
    {
        functionNames.insert(functionName);
    }
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

    unordered_set<string> functionNames;
    int functionIndex = 1;

    string line;
    while (getline(file, line))
    {
        userDefinedFunctionDetect(line, functionNames);
    }

    file.close();

    cout << "Total Number of Unique User-Defined Functions: " << functionNames.size() << endl;

    cout << "User Defined Function Names:" << endl;
    for (const auto& functionName : functionNames)
    {
        cout << "Function-" << functionIndex++ << ": " << functionName << endl;
    }

    return 0;
}
