#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

void drawLine(char* screen, int width, int x1, int x2,int y) {
	int firstFullByte = x1 / 8;
	int startOffset = x1 % 8;
	if (startOffset != 0)
		firstFullByte++;

	int lastFullByte = x2 / 8;
	int endOffset = x2 % 8;
	if (endOffset != 7)
		lastFullByte--;

	//set pixels for full bytes
	for (int b = firstFullByte; b < lastFullByte; b++)
		screen[(width / 8)*y + b] = (char)0xFF;

	char startMask = (char)0xFF >> startOffset;
	char endMask = (char)~(0xFF >> endOffset+1);

	//if both x1 and x2 are in same byte
	if ((x1 / 8) == (x2 / 8)) {
		char mask = startMask & endMask;
		screen[(width / 8)*y + (x1/8)] |= mask;
	}
	else {
		if (startOffset != 0) {
			char num = (width / 8)*y + firstFullByte - 1;
			screen[num] |= startMask;
		}
		if (endOffset != 7) {
			char num = (width / 8)*y + lastFullByte + 1;
			screen[num] |=endMask;
		}
	}
}

int main() {

	return 0;
}
