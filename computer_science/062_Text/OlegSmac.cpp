#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ifstream in("text.in");
	ofstream out("res.txt");
	vector<string> words;
	while (!in.eof()) {
        string str;
        in >> str;
        if (str.size() != 0) {
            words.push_back(str);
        }
	}
	vector<int> numWords (words.size(), 1);
	vector<vector<int>> resWords (words.size(), vector<int>{-1});
	for (int i = 0; i < resWords.size(); i++) {
        resWords[i][0] = i;
	}
	//solution
	int res = 0;
	for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[j][words[j].size() - 1] == words[i][0]) {
                if (numWords[j] + 1 > numWords[i]) {
                    resWords[i].swap(resWords[j]);
                    resWords[i].push_back(i);

                }
                numWords[i] = max(numWords[i], numWords[j] + 1);
            }
        }
	}
	//output
	int max = 0;
	for (int i = 0; i < numWords.size(); i++) {
        if (numWords[i] > numWords[max]) {
            max = i;
        }
	}
	out << words.size() << endl;
	out << words.size() - numWords[max] << endl;
	for (int i = 0; i < resWords[max].size(); i++) {
        out << words[resWords[max][i]] << endl;
	}

	in.close();
	out.close();
}
