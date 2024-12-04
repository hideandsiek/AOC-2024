#include <iostream>
#include <regex>
#include <string>
using namespace std; 

int getMul(string input) {
    regex mulPattern("(mul\\((\\d+),(\\d+)\\))");
    sregex_iterator matches_begin(input.begin(), input.end(), mulPattern);
    sregex_iterator matches_end;
    int result = 0;

    for (sregex_iterator i = matches_begin; i != matches_end; i++) {
        smatch match = *i; 
        int x = stoi(match[2].str());
        int y = stoi(match[3].str());
        result += x * y; 
    }
    return result;
}

int doDontMul(string input) {
    bool doActive = true; 
    int result = 0; 
    regex doDontMulPattern("(do\\(\\))|(don't\\(\\))|mul\\((\\d+),(\\d+)\\)");
    smatch match;
    string::const_iterator inputStart(input.cbegin());

    while (regex_search(inputStart, input.cend(), match, doDontMulPattern)) {
        if ((match[2].matched)) {
            doActive = false;
        } else if ((match[1].matched)) {
            doActive = true;
        } else if (match[3].matched && match[4].matched) {
            if (doActive) {
                cout << "match[3]: " << stoi(match[3].str()) << " match[4]: " << stoi(match[4].str()) << endl; 
                int x = stoi(match[3].str());
                int y = stoi(match[4].str());
                result += x * y;
            }
        } 
        inputStart = match.suffix().first;
    }
    return result;
}

int main() {
    string line;
    string combined;
    int result_p1 = 0;
    int result_p2 = 0; 

    while(getline(cin, line)) {
        result_p1 += getMul(line);
        combined.append(line);
    }
    result_p2 += doDontMul(combined);

    cout << "part1: " << result_p1 << " | part2: " << result_p2 << endl;
}