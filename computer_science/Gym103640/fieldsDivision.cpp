#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> id;
vector<int> sz;

int root(int i) {
    while (i != id[i]) {
        i = id[i];
    }
    return i;
}

void unionTwoFields(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) {
        return;
    }
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    }
    else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main() {
	int N, M;
	cin >> N >> M;

	id.resize(N);
	sz.resize(N);
	for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int field1, field2;
		cin >> field1 >> field2;
		field1--;
		field2--;

        if (field1 != N - 1 && field2 != N - 1) {
            unionTwoFields(field1, field2);
        }
	}

    int lastIndex = N - 1;
    vector<char> fieldsOwnership(N, 'A');

    int rootOfPrev = root(lastIndex - 1);
    for (int i = 0; i < N; i++) {
        if (i != N - 1 && root(i) == rootOfPrev) {
            fieldsOwnership[i] = 'B';
        }
        cout << fieldsOwnership[i];
    }

	return 0;
}
