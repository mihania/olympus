#include <iostream>
#include <cmath>

using namespace std;

int pastDayOfWeek(int startDayOfWeek, int daysAgo) {
    int dayOfWeek = (startDayOfWeek - daysAgo) % 7;
    if (dayOfWeek < 0) {
        dayOfWeek = 7 + dayOfWeek;
    }
    
    return dayOfWeek;
}


int futureDayOfWeek(int startDayOfWeek, int daysForward) {
    int dayOfWeek = (startDayOfWeek + daysForward) % 7;
    return dayOfWeek;
}


int findTimeRemaining(int dayOfWeek, int deposit) {
    int daysUntilRenewal;
    
    // Case 1: deposit made today
    // Case 2: any other day
    
    
    if (deposit == 0) {
        daysUntilRenewal = 30;
        
        int renewalDayOfWeek = futureDayOfWeek(dayOfWeek, daysUntilRenewal);
    
        if (renewalDayOfWeek == 6) {
            daysUntilRenewal += 1;
        } else if (renewalDayOfWeek == 5) {
            daysUntilRenewal += 2;
        }
        
        return daysUntilRenewal;

    } else {
        while (deposit > 30) {
            int depositDayOfWeek = pastDayOfWeek(dayOfWeek, deposit);
            int localRenewalDayOfWeek = pastDayOfWeek(dayOfWeek, deposit - 30);

            // Mon/Wed/Fri
            if ((depositDayOfWeek == 0 || depositDayOfWeek == 2 || depositDayOfWeek == 4) && deposit >= 91) {
                deposit = deposit % 91;
            // Sat
            } else if (localRenewalDayOfWeek == 5) {
                deposit -= 32;
            // Sun
            } else if (localRenewalDayOfWeek == 6) {
                deposit -= 31;
            // Tue/Thu
            } else {
                deposit -= 30;
            }
        }
        
        if (deposit == 0 || deposit == 30) {
            daysUntilRenewal = 0;
        } else {
            daysUntilRenewal = 30 - deposit;
        }
        
        int renewalDayOfWeek = futureDayOfWeek(dayOfWeek, daysUntilRenewal);
    
        if (renewalDayOfWeek == 6) {
            daysUntilRenewal += 1;
        } else if (renewalDayOfWeek == 5) {
            daysUntilRenewal += 2;
        }
        
        return daysUntilRenewal;
    }
    
}

int main() {
    string T;
    int N;
    int dayOfWeek;

    cin >> T;
    cin >> N;

    // Convert day of week to number
    if (T == "Mon") {
        dayOfWeek = 0;
    } else if (T == "Tue") {
        dayOfWeek = 1;
    } else if (T == "Wed") {
        dayOfWeek = 2;
    } else if (T == "Thu") {
        dayOfWeek = 3;
    } else if (T == "Fri") {
        dayOfWeek = 4;
    } else if (T == "Sat") {
        dayOfWeek = 5;
    } else if (T == "Sun") {
        dayOfWeek = 6;
    }

    int minWaitTime = 500;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        int tmpWaitTime = findTimeRemaining(dayOfWeek, tmp);
        if (tmpWaitTime < minWaitTime) {
            minWaitTime = tmpWaitTime;
        }
    }

    cout << minWaitTime << endl;

    return 0;
}
