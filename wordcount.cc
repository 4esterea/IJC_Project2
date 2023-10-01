#include <string>
#include <iostream>
#include <unordered_map>


int main() {
        using namespace std;
        unordered_map<string,int> m; 
        string word;
        while (cin >> word) 
            m[word]++; 

        for (auto &mi: m)
            cout << mi.first << "\t" << mi.second << "\n";
    }