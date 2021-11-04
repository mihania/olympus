#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("in.txt");
	int N, G;
	in >> N >> G;
	in.close();		

	// c[i][j] - number of combinations of i coins with weight j
        vector<vector<long long>> c(N + 1, vector<long long>(G + 1, 0));	
	
	// mc[i][j] - minimum value of i coins with weight j 
	vector<vector<long long>> mc(N + 1, vector<long long>(G + 1, LONG_MAX)); 

	// coin weight -> value mapping
	vector<int> coins = {0, 1, 5, 10, 25, 50};

	for (int j = 1; j < min(c[0].size(), coins.size()); j++) {
		c[1][j] = 1;
		mc[1][j] = coins[j];
	}
	
	for (int i = 1; i < c.size(); i++) {
		for (int j = 1; j < c[0].size(); j++) {
			for (int k = 1; k < min(j + 1, (int)coins.size()); k++) {
				
				// checking that a combination exist
				// preventing duplicate combinations
				if (c[i - 1][j - k] > 0 && j - k >= k) {
					c[i][j] += c[i - 1][j - k];
					mc[i][j] = min(mc[i][j], mc[i - 1][j - k] + coins[k]);
				}
			}
		}
 	}

	ofstream out("out.txt");
	out << (c[N][G] == 0 ? 0 : mc[N][G]) << " " << c[N][G] << endl;
	out.close();
	return 0;
}

