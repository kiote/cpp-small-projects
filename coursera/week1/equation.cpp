#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<float> find_roots(int a, int b, int c);
void print_result(vector<float> a);
void test();
void real_run();
bool almost_equal(vector<float> a, vector<float> b);

/**
 * main
 */
int main() {
	real_run();
//	test();
	return 0;
}

/**
 * check if two float vectors are almost equals (2 digits after comma)
 */
bool almost_equal(vector<float> a, vector<float> b) {
	if (a.size() != b.size()) {
		return false;
	}
	int size = a.size();
	for (int i=0; i<=size-1; i++) {
		if (abs(a[i] - b[i]) > 0.01) {
			return false;
		}
	}
	return true;
}

/**
 * makes real program run
 */
void real_run() {
	int a, b, c;
	cin >> a >> b >> c;

	print_result(find_roots(a, b, c));
}

/**
 * finds roots of equation
 */
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
		result.push_back(0.00);
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

/**
 * prints roots
 */
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

/**
 * test conditions
 */
void test() {
	vector<vector<int>> test_data = {
		// cases from assignment
		{2, 5, 2},
		{2, 4, 2},
		{2, 1, 2},
		{0, 4, 10},
		// all special cases
		{0, 0, 9},
		{1, 0, 0},
		{3, 0, -9}, // 3*x*x - 9 = 0; 3xx = 9; xx = 3; x = 1.73
		{1, 1, 0},  // xx + x = 0; x(x+1)=0
		// regular cases
		// D > 0
		{1, 12, 1},
		{2, 5, 2},
		// D = 0
		{1, 6, 9},
		// D < 0
		{2, 4, 7}
	};

	vector<vector<float>> roots_data = {
		// cases from assignment
		{-2, -0.5},
		{-1},
		{},
		{-2.5},
		// all special cases
		{},
		{0.00},
		{-1.73, 1.73},
		{0.00, -1.00},
		// regular cases
		// D > 0
		{-11.92, -0.08},
		{-2.00, -0.50},
		// D = 0
		{-3},
		// D < 0
		{},
	};

	for (int i=0; i<=test_data.size()-1; i++) {
		cout << "A=" << test_data[i][0];
		cout << ";B=" << test_data[i][1];
		cout << ";C=" << test_data[i][2] << endl;
		vector<float> found_roots = find_roots(test_data[i][0],
						       test_data[i][1],
						       test_data[i][2]);
		cout << "roots:";
		print_result(found_roots);

		cout << endl << "expected:";
		print_result(roots_data[i]);
		assert(almost_equal(found_roots,roots_data[i]));
		cout << endl;
	}
}
