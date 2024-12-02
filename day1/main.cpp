#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std; 

int main() {
    vector<int> array1;
    vector<int> array2;
    string line;
    int result_p1 = 0;

    while (getline(cin, line)) {
        istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            array1.push_back(num1);
            array2.push_back(num2);
        }
    }

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    // part1
    for (int i = 0; i < array1.size(); i++) {
        result_p1 += abs(array1[i] - array2[i]);
    }

    cout << "day1 part1 answer is: " << result_p1 << endl;

    int result_p2 = 0;
    int freq;
    // part2
    for (int i = 0; i < array1.size(); i++) {
        if ((i == 0) || (array1[i] != array1[i-1])) {
            freq = count(array2.begin(), array2.end(), array1[i]);
        }
        result_p2 += array1[i] * freq;
    }

    cout << "day1 part2 answer is: " << result_p2 << endl; 
}