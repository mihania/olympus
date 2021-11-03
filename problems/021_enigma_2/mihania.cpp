#include<fstream>
#include<vector>

using namespace std;

int main() {
	ifstream in("in.txt");
	string A, B;
	in >> A >> B;
	in.close();

	vector<int> h(26, 0);
	long res = 0;
	
	for (int i = 0; i < B.length(); i++) {
        	if (i < A.length()) {
            		h[A[i] - 'a']++;
        	}

        	res += h[B[i] - 'a'];
        	int idx = A.length() - B.length() + i;
        	if (idx >= 0) {
            		h[A[idx] - 'a']--;
        	}
    	}

	ofstream out("out.txt");
	out << res << endl;
	out.close();
}
