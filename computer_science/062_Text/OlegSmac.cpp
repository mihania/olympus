#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<unordered_map>

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
	//dp[i] - количество слов в подпослделовательности, начинающейся с этого слова
	vector<int> dp (words.size(), 1);
	//resWords[i] - индекс следующего слова после words[i]
	vector<int> resWords (words.size(), -1);
	//let_idx - буква и её индекс, с которого нужно начинать подпоследовательность
	unordered_map<char, int> let_idx;

	//solution
	int maxIdx = 0;
	for (int i = words.size() - 1; i >= 0; i--) {
        char beginWord = words[i][0];
        char endWord = words[i][words[i].size() - 1];
        if (let_idx.count(beginWord) == 0) {
            let_idx[beginWord] = i;
        }
        if (let_idx.count(endWord) != 0) {
            if (dp[i] < dp[let_idx[endWord]] + 1) {
                dp[i] = dp[let_idx[endWord]] + 1;
                resWords[i] = let_idx[endWord];
                let_idx[beginWord] = i;
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }
	}

	//output
	out << words.size() << endl;
	out << words.size() - dp[maxIdx] << endl;
	while (maxIdx != -1) {
        out << words[maxIdx] << endl;
        maxIdx = resWords[maxIdx];
	}

	in.close();
	out.close();
}
