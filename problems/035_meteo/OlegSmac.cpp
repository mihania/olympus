#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int k;
		double mint;
		double maxt;
		in >> k >> mint >> maxt;
		vector<string> months;
		for (int i = 0; i < k; i++) {
			string s;
			in >> s;
			int n;
			in >> n;
			double t;
			bool outOfBounds = true;
			for (int j = 0; j < n; j++) {
				in >> t;
				if (t < mint || t > maxt) {
					outOfBounds = false;
				}
			}
			if (outOfBounds) {
				months.push_back(s);
			}
		}
		//output
		if (months.size() == 0) {
			out << "NU" << endl;
		}
		else {
			sort(months.begin(), months.end());
			for (int i = 0; i < months.size(); i++) {
				out << months[i] << endl;
			}
		}
	}
	
	in.close();
	out.close();
}