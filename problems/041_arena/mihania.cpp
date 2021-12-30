#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;


bool eq(double a, double b) {
    return abs(a - b) < 0.00001;
}

double sqr(double v) {
    return pow(v, 2);
}

// gets euclidian distance between two points p1 and p2
double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(sqr(p1.first - p2.first) + sqr(p1.second - p2.second));
}

int solve(vector<pair<double, double>>& m) {
    
    // finding the sides of the triangle, a, b, c.
    vector<double> s = { 
        distance(m[0], m[1]),
        distance(m[1], m[2]),
        distance(m[2], m[0]) 
    };
    
    sort(s.begin(), s.end());
    
    // based on https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%BA%D0%BE%D1%81%D0%B8%D0%BD%D1%83%D1%81%D0%BE%D0%B2
    double cosAlpha  = (sqr(s[0]) + sqr(s[1]) - sqr(s[2])) / (2 * s[0] * s[1]);
    double alpha = acos(cosAlpha) * 180.0 / M_PI;
    
    // based on https://mathvox.ru/geometria/mnogougolniki/glava-1-mnogougolniki-i-ih-svoistva/svoistva-uglov-pravilnogo-mnogougolnika/
    return eq(alpha, 180) ? 8 : (int)ceil(360 / (180 - alpha));  
}

int main() {
    ifstream in("tests.in");
	ofstream out("tests.out");
    long T;
    in >> T;
    for (auto t = 0; t < T; t++) {
        vector<pair<double, double>> m;
        for (int i = 0; i < 3; i++) {
            double x;
            double y;
            in >> x >> y;
            m.push_back({x, y});
        }

        out << solve(m) << endl;
    }

    in.close();
    out.close();
} 
