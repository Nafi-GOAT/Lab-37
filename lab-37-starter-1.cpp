//
// COMSC 210 || Lab 38 || Mehraj Hasan Nafi
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

void print_first_100(const map<int, list<string>>& table) {
    int count = 0;
    for (const auto &entry : table) {
        cout << "Index " << entry.first << ": ";
        
        for (const auto &code : entry.second) {
            cout << code << " ";
        }
        cout << endl;
        count++;

        if (count == 100) 
        break;
    }
}

void search_index(const map<int, list<string>>& table) {
    int index;
    cout << "Enter index to search: ";
    cin >> index;

    auto it = table.find(index);

    if (it == table.end()) {
        cout << "Index not found in the hash table." << endl;
        return;
    }

    cout << "Codes at index " << index << ": ";
    for (const auto &code : it->second) {
        cout << code << " ";
    }
    cout << endl;
}

void search_string(const map<int, list<string>>& table) {
    string s;
    cout << "Enter a string to search: ";
    cin >> s;

    int index = gen_hash_index(s);

    cout << "Computed index = " << index << endl;

    auto it = table.find(index);

    if (it == table.end()) {
        cout << "No codes found at this index." << endl;
        return;
    }

    bool found = false;
    for (const auto &code : it->second) {
        if (code == s) {     
            cout << "Found matching string: " << code << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No exact match found at this index." << endl;
    }
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

    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Print first 100 entries of the hash table\n";
        cout << "2. Search for an index\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                print_first_100(hash_table);
                break;
             
            case 2:
                search_index(hash_table);
                break;

            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
