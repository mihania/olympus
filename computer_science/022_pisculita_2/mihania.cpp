#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("in.txt");
	int N, G;
	in >> N >> G;
	in.close();		

	// k[i][j] - number of combinations of i coins with weight j
        vector<vector<long long>> k(N + 1, vector<long long>(G + 1, 0));	
	
	// m[i][j] - minimum value of i coins with weight j 
	vector<vector<long long>> m(N + 1, vector<long long>(G + 1, LONG_MAX)); 

	// coin weight -> value mapping
	vector<int> coins = {0, 1, 5, 10, 25, 50};

	for (int j = 1; j < min(k[0].size(), coins.size()); j++) {
		k[1][j] = 1;
		m[1][j] = coins[j];
	}
	
	for (int i = 1; i < k.size(); i++) {
		for (int j = 1; j < k[0].size(); j++) {
			for (int t = 1; t < min(j + 1, (int)coins.size()); t++) {
				
				// checking that a combination exist
				// preventing duplicate combinations
				if (k[i - 1][j - t] > 0 && j - t >= t) {
					k[i][j] += k[i - 1][j - t];
					m[i][j] = min(m[i][j], m[i - 1][j - t] + coins[t]);
				}
			}
		}
 	}

	ofstream out("out.txt");
	out << (k[N][G] == 0 ? 0 : m[N][G]) << " " << k[N][G] << endl;
	out.close();
	return 0;
}

