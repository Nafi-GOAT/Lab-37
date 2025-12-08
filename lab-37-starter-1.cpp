//
// COMSC 210 || Lab 38 || Mehraj Hasan Nafi
// IDE used: Visual Studio Code
//
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
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

    cout << "Codes at this index: ";
    for (const auto &code : it->second) {
        cout << code << " ";
    }
    cout << endl;
}

void count_total_codes(const map<int, list<string>>& table) {
int total = 0;

    for (const auto &entry : table) {
        total += entry.second.size();  // number of strings in this bucket
    }

    cout << "Total number of codes in the hash table: " << total << endl;
}

void modify_string(map<int, list<string>>& table) {
    string oldStr, newStr;

    cout << "Enter the string you want to modify: ";
    cin >> oldStr;

    int oldIndex = gen_hash_index(oldStr);

    auto it = table.find(oldIndex);
    if (it == table.end()) {
        cout << "String not found (index does not exist)." << endl;
        return;
    }

    auto &lst = it->second;
    auto pos = find(lst.begin(), lst.end(), oldStr);

    if (pos == lst.end()) {
        cout << "String NOT found at its index." << endl;
        return;
    }

    cout << "Enter new string to replace it with: ";
    cin >> newStr;

    lst.erase(pos);

    int newIndex = gen_hash_index(newStr);
    table[newIndex].push_back(newStr);

    cout << "String successfully modified!" << endl;
}

void remove_string(map<int, list<string>>& table) {
    string target;
    cout << "Enter the string you want to remove: ";
    cin >> target;

    int index = gen_hash_index(target);

    auto it = table.find(index);
    if (it == table.end()) 
        cout << "Index does not exist. String not found." << endl;
        return;
    

    auto &lst = it->second;
    auto pos = find(lst.begin(), lst.end(), target);

    if (pos == lst.end()) {
        cout << "String not found at this index." << endl;
        return;
    }

    lst.erase(pos);
    cout << "String removed successfully." << endl;
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
        cout << "3. Search for a string\n";
        cout << "4. Count total number of codes\n";
        cout << "5. Modify a string\n";
        cout << "6. Remove a string\n";
        cout << "7. Exit\n";
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
            search_string(hash_table);
            break;

            case 4:
            count_total_codes(hash_table);
            break;

            case 5:
            modify_string(hash_table);
            break;

            case 6:
            remove_string(hash_table);
            break;

            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
