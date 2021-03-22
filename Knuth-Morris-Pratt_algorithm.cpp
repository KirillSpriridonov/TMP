#include <iostream>

using namespace std;

int const MAX_SIZE = 1024;

int size_string(char s[]) {
	int i = 0;
	while (s[i] != '\0') { 
		cout << s[i] << ' ';
		++i;
	}
	
	return i;
}

int main() {
	char Text[MAX_SIZE];
	char Pattern[MAX_SIZE];
	cin >> Text;
	cin >> Pattern;
	int PatternSize = size_string(Pattern);
	int TextSize = size_string(Text);
	int *p = new int [PatternSize];

	for (int i = 0; i < PatternSize; ++i) {
		p[i] = 0;
	}

	int j = 0;
	int i = 1;

	while (i < PatternSize) {
		if (Pattern[j] == Pattern [i]) {
			p[i] = j + 1;
			++i;
			++j;
		}
		else {
			if (j == 0) {
				p[i] = 0;
				++i;
			}
			else { 
				j = p[j-1];
			}
		}
	}
	cout << PatternSize << '\n';	
	for (int i = 0; i < PatternSize; ++i) {
        	cout << p[i] << ' ';
        }
	i = 0;
	j = 0;
	while (i < TextSize) {
		if (Text[i] == Pattern[j]) {
			i++;
			j++;
			if (j == PatternSize) {
				cout << "Pattern was found\n";
			}
		}
		else {
			if (j > 0) {
				j = p[j -1];
			}
			else { 
				++i;
			}
		}
	}
}
