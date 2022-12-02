#include <iostream>
#include <vector>

using namespace std;


int64_t N, X, R, P, K, r, p;
vector<bool> regenerationSequence;


int64_t getTotalDamage(int64_t reservedUses) {
	bool poisonUse[N] = {0};
	int64_t poisonUseAmount = 0;

	int64_t i = 0;
	while (reservedUses > 0 && i < N) {
		if (regenerationSequence[i]) {
			poisonUse[i] = true;
			reservedUses--;
			poisonUseAmount++;
		}
		i++;
	}

	i = 0;
	int64_t usesLeft = K - poisonUseAmount;
	while (usesLeft > 0 && i < N) {
		if (!poisonUse[i]) {
			poisonUse[i] = true;
			usesLeft--;
		}
		i++;
	}
	
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
		// cout << "round " << i << "; totalDamage = " << totalDamage << endl;
	}

	return totalDamage;
}



int main() {
	cin >> N >> X >> R >> P >> K;

	regenerationSequence.reserve(N);
	int64_t regenerationAmount = 0;

	for (int64_t i = 0; i < N; i++) {
		char tmp;
		cin >> tmp;

		bool tmpBool = tmp == '1';

		regenerationSequence.push_back(tmpBool);

		if (tmpBool) {
			regenerationAmount++;
		}
	}


	int64_t maxDamage = -9223372036854775000;
	for (int64_t i = 0; i <= K ; i++) {
		if (i > regenerationAmount) {
			break;
		}

		int64_t totalDamage = getTotalDamage(i);
		// cout << "i = " << i << "; damage = " << totalDamage << endl;

		if (totalDamage > maxDamage) {
			maxDamage = totalDamage;
		} else {
			break;
		}
	}

	cout << maxDamage << endl;

	return 0;
}
