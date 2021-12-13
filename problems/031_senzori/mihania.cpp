#include<fstream>
#include<vector>
#include<unordered_map>
#include<tuple>
#include<cmath>

using namespace std;

class Test {
public:
	long K;
	vector<pair<long, long>> sensors;
	long N;
	unordered_map<long, tuple<long, long, long>> waps;
	long M;
	vector<int> broken;
};

long solve(Test& t) {
	for (int k : t.broken) {
		t.waps.erase(k);
	}

	long res = 0;
	for (auto s : t.sensors) {
		bool connected = false;
		for (auto& kv : t.waps) {
			connected |= (pow(s.first - get<0>(kv.second), 2) + pow(s.second - get<1>(kv.second), 2) <= pow(get<2>(kv.second), 2));
			if (connected) {
				break;
			}
		}

		if (!connected) {
			res++;
		}
	}

	return res;
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;
	ofstream out("tests.out");
	for (int i = 0; i < T; i++) {
		Test test;
		in >> test.K;
		for (int j = 0; j < test.K; j++) {
			long x, y;
			in >> x >> y;
			test.sensors.push_back({x, y});
		}

		in >> test.N;
		for (int j = 1; j <= test.N; j++) {
			long x, y, r;
			in >> x >> y >> r;
			test.waps[j] = {x, y, r};
		}

		in >> test.M;
		for (int j = 0; j < test.M; j++) {
			long k;
			in >> k;
			test.broken.push_back(k);
		}

		out << solve(test) << endl;
	}

	return 0;
	
	in.close();
	out.close();
}

