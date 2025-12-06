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

    ifstream inputFile ("lab-37-data-3.txt");
    
    if (!inputFile){
        cout << "Error: Could not open file." << endl;
    }
  
    long long totalSum = 0;
    string code;

    while (inputFile >> code) {
        totalSum += sum_ascii(code);
    }

    inputFile.close();

    cout << "Total ASCII sum: " << totalSum << endl;    
 
    return 0;
}

