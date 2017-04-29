#include <iostream>
#include <string>
#include <map>
using namespace std;

int numOfOnes(int num) {
	int count = 0;
	while (num > 0) {
		num = num&(num - 1);
		count++;
	}
	return count;
}

int larger(int num) {
	int currentOnes = numOfOnes(num);
	num += 1;
	while (currentOnes != numOfOnes(num))
		num += 1;
	return num;
}

int smaller(int num) {
	int currentOnes = numOfOnes(num);
	num -= 1;
	while (currentOnes != numOfOnes(num))
		num -= 1;
	return num;

}

int main() {

	int num = 12;
	int small = smaller(num);
	int large = larger(num);
	cout << "number: " << num << endl;
	cout << "smaller: " << small << endl;
	cout << "larger: " << large << endl;

	return 0;
}