#include <iostream>
using namespace std;

int flipBits(int a)
{
	return  ((a & 0x55555555)<<1) | ((a & 0xaaaaaaaa)>>1);
}

int main() {
	int num = 10;
	cout << flipBits(num) << endl;
	return 0;
}