#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<char> firstLetters;
    string words[n];

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words[i] = word;
        firstLetters.insert(word[0]);
    }

    for (int i = 0; i < n; i++) {
        bool isAcronym = true;
        for (int j = 0; j < words[i].size(); j++) {
            auto elementIt = firstLetters.find(words[i][j]);
            if (elementIt == firstLetters.end()) {
                isAcronym = false;
                break;
            }
        }
        if (isAcronym) {
            cout << "Y";
            return 0;
        }
    }
    cout << "N";
}
