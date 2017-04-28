#include <iostream>
#include <string>
#include <list>
using namespace std;


// Remove all extra backslashes in the string

void removeExtraSlashes(string &str) {
	int slow = 0;
	int fast = 0;
	while (fast < str.length()) {
		if (str[slow] != '/') {
			slow++;
			fast++;
		}
		else {
			slow++;
			fast++;
			while (str[fast] == '/')
				fast++;
		}		
		str[slow] = str[fast];
	}
	str.erase(slow, string::npos);
}


int main() {

	string str = "C:/Program Files(x86)//My Folder///Temp/Folder/";

	removeExtraSlashes(str);

	cout << str << endl;

	return 0;
}