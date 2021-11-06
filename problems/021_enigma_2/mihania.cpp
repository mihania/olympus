#include<fstream>
#include<vector>

using namespace std;

// Let's assume A length is N, B length is M.
// Let's divide string B into three parts [left|middle|right], where both left and right are of length N.

// To simplify the task, let's assume we need to find number of intersections of each B' in middle.
// We can reverse the problem and see that for each letter c in middle we can intersect it T times, 
// where T - is the number of occurences of letter c in A, because we can shift B' to this required position.

// For the left and right part logic is the same, but corner cases must be applied for calculating histogram of each letter. 
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
