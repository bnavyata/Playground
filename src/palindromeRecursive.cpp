#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool isPalindromeRecur(string s, int i, int n) {
	if (i == n)
		return true;
	if (s[i] != s[n])
		return false;
	if(i<n)
	 return isPalindromeRecur(s, i+1, n-1);
	return true;
}

bool isPalindrome(string s) {
	if (s.length() == 0)
		return true;
	int n = s.length() - 1;
	isPalindromeRecur(s, 0,n );
}

int main() {
	string s = "catac";
	cout << s << endl;
	if (isPalindrome(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}