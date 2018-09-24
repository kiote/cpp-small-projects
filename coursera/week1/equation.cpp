#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<float> find_roots(int a, int b, int c);
void print_result(vector<float> a);
void test();

int main() {
//	real_run();
	test();
	return 0;
}

void real_run() {
	int a, b, c;
	cin >> a >> b >> c;

	print_result(find_roots(a, b, c));
}

vector<float> find_roots(int a, int b, int c) {
	vector<float> result;

	// all special cases
	if (a==0 && b!=0) {
		result.push_back(-c*1.0/b);
		return result;
	}
	else if (a==0 && b==0) {
		return result;
	}
	else if (b==0 && c == 0) {
		result.push_back(0);
		return result;
	}
	else if (b==0 && c!=0) {
		if (-c/a > 0) {
			result.push_back(-sqrt(-c/a));
			result.push_back(sqrt(-c/a));
		}
		return result;
	}
	else if (b!=0 && c==0) {
		result.push_back(-b*1.0/a);
		return result;
	}

	// regular cases
	float D = b*b - 4*a*c;
//	cout << "D = " << D << endl;

	if (D > 0) {
		result.push_back((-b-sqrt(D))/(2*a));
		result.push_back((-b+sqrt(D))/(2*a));
		return result;
	}
	else if (D == 0) {
		result.push_back(-b/(2*a));
		return result;
	}

	return result;
}

void print_result(vector<float> a) {
	if (a.size() == 2) {
		printf ("%4.2f %4.2f", a[0], a[1]);
	}
	else if (a.size() == 1) {
		printf ("%4.2f", a[0]);
	}
	else {
		cout << "";
	}
}

void test() {
	struct equation {
		vector<int> coeficients;
		vector<int> roots;
	};
	vector<vector<int>> test_data = {
			// all special cases
			{0, 5, 2},
			{0, 0, 9},
			{1, 0, 0},
			{3, 0, -9},
			{1, 1, 0},
			// regular cases
			// D > 0
			{1, 12, 1},
			{2, 5, 2},
			{2, 4, 2},
			// D = 0
			{1, 12, 32},
			// D < 0
			{1, 12, 42}
	};

	for (auto d:test_data) {
		cout << "a=" << d[0] << "b=" << d[1] << "c=" << d[2] << endl;
		print_result(find_roots(d[0], d[1], d[2]));
		cout << endl;
	}
}
