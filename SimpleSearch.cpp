#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;
const int SIZE = 8;

int length(char a[]) {
	int i = 0;
	while (a[i] != '\0') {
		++i;
	}
	return i;
}

int main() {
	char Text[MAX_SIZE];
	char Pattern[SIZE];
	cin >> Text;
	cin >> Pattern;
	int PatternSize = length(Pattern);
	for (int i = 0; Text[i] != '\0'; ++i) {
		int j;
		for (j = 0; j < PatternSize; ++j) {
			if (Text[i + j] != Pattern[j]) {
				break;
			}
		}
		
		if ( j == PatternSize) {
			cout << i << ' ';
		}}
	}
	cout << '\n';
}
