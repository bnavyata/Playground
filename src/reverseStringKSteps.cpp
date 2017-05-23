#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


void reverseK(int a, int b, string& s) {
	while (a<b) {
		swap(s[a++], s[b--]);
	}
}

string reverseStr(string s, int k) {
	int l = s.length() - 1;
	for (int i = 0; i<s.length(); i = i + 2 * k) {
		int b = i + k - 1;
		reverseK(i, min(b,l), s);
	}
	return s;
}

int main() {
	string s = "abcdefghi";
	int k = 2;
	s =reverseStr(s, k);
	cout << s << endl;

	return 0;
}