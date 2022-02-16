#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
class User {
public:
	string lastName;
	string firstName;
	long usage;
};

int main() {
    ifstream in("tests.in");
    ofstream out("tests.out");
    vector<User> users;
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
	User user;
	in >> user.lastName;
	in >> user.firstName;
	in >> user.usage;
	users.push_back(user);
    }

    int minIdx = 0;
    int maxIdx = 0;
    long sum = 0;
    for (int i = 0; i < users.size(); i++) {
    	if (users[i].usage < users[minIdx].usage) {
		minIdx = i;
	}

	if (users[i].usage > users[maxIdx].usage) {
		maxIdx = i;
	}

	sum += users[i].usage;
    }

    // limit float to 2 decimal only
    char avgUsage[100]; // long cannot be bigger than 100
    sprintf(avgUsage, "%.2f", 1.0 * sum / users.size());

    out << avgUsage << endl;
    out << users[maxIdx].lastName << " " << users[maxIdx].firstName << " " << users[maxIdx].usage << endl;
    out << users[minIdx].lastName << " " << users[minIdx].firstName << " " << users[minIdx].usage << endl;

    in.close();
    out.close();
} 
