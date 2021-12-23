#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

class Month {
public:
	string name;
	vector<double> t;
};

class Test {
public:
	double Tmin;
	double Tmax;
	vector<Month> m;		
};


vector<string> solve(Test& test) {
	vector<string> res;
	for (auto month : test.m) {
		auto minTemp = *min_element(month.t.begin(), month.t.end());
		auto maxTemp = *max_element(month.t.begin(), month.t.end());
	       	if (test.Tmin <= minTemp && maxTemp <= test.Tmax) {
	       		res.push_back(month.name);
		}	       
	}

	sort(res.begin(), res.end());
	return res;
}


int main() {
	ifstream in("tests.in");
	ofstream out("tests.out");
	long T;
	in >> T;
	for (auto t = 0; t < T; t++) {
		Test test;
		long M;
		in >> M >> test.Tmin >> test.Tmax;
		for (int i = 0; i < M; i++) {
			Month m;
			in >> m.name;
			long k;
			in >> k;
			for (int j = 0; j < k; j++) {
				double temp;
				in >> temp;
				m.t.push_back(temp);
			}

			test.m.push_back(m);
		}

		vector<string> res = solve(test);
		if (res.empty()) {
			out << "NU" << endl;
		} else {
			for (auto r : res) {
				out << r << endl;
			}
		}
	}
	
	in.close();
	out.close();
}

