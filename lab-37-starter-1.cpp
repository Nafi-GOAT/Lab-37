//
// COMSC 210 || Lab 37 || Mehraj Hasan Nafi
// IDE used: Visual Studio Code
//
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string &s) {
    int total = 0;
    for (int i = 0; i < s.length(); i++) {
        total += (int)s[i];
    }
    return total;
}


int main() {

    ifstream inputFile ("lab-37-data-3.txt");
    
    if (!inputFile){
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    map<int, list<string>> hash_table;
    string code;

    while (inputFile >> code) {
        int index = gen_hash_index(code);
        hash_table[index].push_back(code);
    }

    inputFile.close();

    int count = 0;
    for (auto &entry : hash_table) {
        cout << "Index " << entry.first << ": ";
        for (const auto &code : entry.second) {
            cout << code << " ";
        }
        cout << endl;

        count++;
        if (count == 100) break;
    }
 
    return 0;
}

