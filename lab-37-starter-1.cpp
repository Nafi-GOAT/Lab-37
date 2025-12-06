//
// COMSC 210 || Lab 37 || Mehraj Hasan Nafi
// IDE used: Visual Studio Code
//
#include <iostream>
#include <string>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
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

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
