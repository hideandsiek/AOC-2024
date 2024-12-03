#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std; 

vector<int> getIntFromStr(const string& input) {
    vector<int> vi;
    istringstream stream(input);
    int num; 

    while (stream >> num) {
        vi.push_back(num);
    }
    
    return vi;
}

bool isReportSafe(vector<int>& vi) {
    if (vi.size() < 2) {
        return true;
    }

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 0; i < vi.size() - 1; i++) {
        int diff = vi[i+1] - vi[i];

        if (abs(diff) < 1 || abs(diff) > 3 ) {
            return false;
        }

        // if (isIncreasing) {
        //     isIncreasing = diff > 0 ? true : false;
        // } 
        // if (isDecreasing) {
        //     isDecreasing = diff < 0 ? true : false;     
        // }
        if (diff > 0) {
            isDecreasing = false;
        } else if (diff < 0) {
            isIncreasing = false;
        }
    }
    
    return isIncreasing || isDecreasing;
}

bool isReportSafeOneRemoval(vector<int>& vi) {
    if (isReportSafe(vi)) {
        return true;
    }

    if (vi.size() <= 1) {
        return false;
    }

    for (int i = 0; i < vi.size(); i++) {
        vector<int> tempVi = vi; 
        tempVi.erase(tempVi.begin() + i);
        if (isReportSafe(tempVi)) {
            return true;
        }
    }
    return false;
}

int main() {
    string line;
    vector<int> report; 
    int result_p1 = 0;
    int result_p2 = 0;

    while(getline(cin, line)) {
        report = getIntFromStr(line);
        result_p1 = isReportSafe(report) ? ++result_p1 : result_p1;
        result_p2 = isReportSafeOneRemoval(report) ? ++result_p2 : result_p2;
    }

    cout << "part1: " << result_p1 << " | part2: " << result_p2 << endl;
}