//
// COMSC 210 || Lab 37 || Mehraj Hasan Nafi
// IDE used: Visual Studio Code
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (int i = 0; i < s.length(); i++) {
        total += (int)s[i];
    }
    return total;
}


int main() {

    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);

    int result = sum_ascii(input);

    cout << "The sum of ASCII values is: " << result << endl;
 
    return 0;
}

