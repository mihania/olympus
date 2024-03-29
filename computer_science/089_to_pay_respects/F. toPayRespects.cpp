#include <iostream>
#include <vector>

using namespace std;

int64_t N, X, R, P, K, r, p;
vector<bool> regenerationSequence;

int64_t getTotalDamage(bool poisonUse[]) {
	int64_t p = 0, r = 0, totalDamage = 0;
	// Calculate actual damage
	for (int i = 0; i < N; i++){
		if (regenerationSequence[i]) {
			r++;
		}

		if (poisonUse[i]) {
			p++;
			if (r > 0) {
				r--;
			}
		}

		totalDamage += X + P * p - R * r;
	}

	return totalDamage;
}



int main() {
	cin >> N >> X >> R >> P >> K;
	regenerationSequence.reserve(N);

	for (int64_t i = 0; i < N; i++) {
		char tmp;
		cin >> tmp;

		bool tmpBool = tmp == '1';

		regenerationSequence.push_back(tmpBool);
	}

	bool poisonUse[N] = {0};
	int64_t startingPoisonLastIdx = K - 1;

	for (int64_t i = 0; i < K; i++) {
        	poisonUse[i] = true;
	}

	int64_t maxDamage = getTotalDamage(poisonUse);

	for (int64_t i = K; i < N; i++) {
		if (regenerationSequence[i]) {

		    while (startingPoisonLastIdx >= 0 && regenerationSequence[startingPoisonLastIdx]) {
			startingPoisonLastIdx--;
		    }

		    if (startingPoisonLastIdx < 0) {
			 break;
		    }

		    poisonUse[startingPoisonLastIdx] = false;
		    poisonUse[i] = true;

		    int64_t damage = maxDamage;
		    damage -= P * (N - startingPoisonLastIdx);
		    damage += P * (N - i) + R * (N - i);

		    if (damage > maxDamage) {
			maxDamage = damage;
		    } else if (damage < maxDamage) {
			break;
		    }
		    startingPoisonLastIdx--;
		}
	}

	cout << maxDamage << endl;

	return 0;
}
