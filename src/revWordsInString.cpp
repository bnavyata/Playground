#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


void reverseword(string &s, int i, int j) {
	while (i<j) {
		char t = s[i];
		s[i++] = s[j];
		s[j--] = t;
	}
}

void reverseWords(string &s) {
	reverse(s.begin(), s.end());
	int i = 0, j = 0;
	int l = 0;
	int len = s.length();
	int wordcount = 0;

	while (i<len) {
		// skip spaces in front of the word
		while (i<len && s[i] == ' ')
			i++;
		//if the whole string was only spaces, return
		if (i == len)
			break;
		if (wordcount)
			s[j++] = ' ';
		l = j;
		while (i<len && s[i] != ' ') {
			s[j] = s[i];
			j++;
			i++;
		}
		// reverse word in place
		reverseword(s, l, j - 1);
		wordcount++;
	}
	// resize result string
	s.resize(j);
}

int main() {
	string s = "My name is navyata";
	cout << s << endl;
	reverseWords(s);
	cout << s << endl;
	return 0;
}