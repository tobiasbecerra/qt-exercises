#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string removeSpaces(const string& str){
    string result;
    for(char c: str){
        if(c!=' '){
            result += c;
        }
    }
    return result;
}

bool compareIgnoringSpaces(const string& a, const string& b){
    return removeSpaces(a) < removeSpaces(b);
}

int main()
{

    vector<string> idioms;

    idioms.push_back("piece of cake");
    idioms.push_back("hit the books");
    idioms.push_back("break a leg");
    idioms.push_back("under the weather");
    idioms.push_back("spill the beans");

    cout << "Idioms before sorting:\n";
    for(const string& idiom:idioms){
        cout << idiom << endl;
    }

    sort(idioms.begin(), idioms.end(), compareIgnoringSpaces);

    cout << "\nIdioms after sorting (ignoring spaces):\n";
    for(const string& idiom:idioms){
        cout << idiom << endl;
    }


    return 0;
}
