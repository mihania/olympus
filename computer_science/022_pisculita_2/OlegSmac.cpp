#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("in1.txt");
	int N, G;
	in >> N >> G;
	in.close();		
	
	// 	 масса монет =   0, 1, 2, 3,  4,  5;
	vector<int> coins = {0, 1, 5, 10, 25, 50};
	
	vector<vector<long long>> k(N + 1, vector<long long>(G + 1, 0)); //количество комбинаций из i монет, массой j
	vector<vector<long long>> m(N + 1, vector<long long>(G + 1, 2147483647)); //минимальная сумма из i монет, массой j
	
	for (int j = 1; j < min(G + 1, (int)coins.size()); j++) {
		k[1][j] = 1;
		m[1][j] = coins[j];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= G; j++) {
			for (int t = 1; t < min(j + 1, (int)coins.size()); t++) {
				if (k[i - 1][j - t] > 0 && j - t >= t) {
					k[i][j] += k[i - 1][j - t];
					m[i][j] =  min(m[i][j], m[i - 1][j - t] + coins[t]);
				}
			}
		}
	}
	
	ofstream out("out.txt");
	out << (k[N][G] == 0 ? 0 : m[N][G]) << " " << k[N][G] << endl;
	out.close();
	return 0;
}
