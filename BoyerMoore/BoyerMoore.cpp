#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const MAX_SIZE = 1024;
int const MAX_ALP = 26;

char Text[MAX_SIZE];
char Pattern[MAX_SIZE];

int length(char a[]) {
	int i = 0;
	while (a[i] != '\0') {
		++i;
	}
	return i;
}

int RuleBadSymbol(int j,int symbol, vector<vector<int>>& vec) {
    for(int i = vec[symbol].size()-1; i >= 0; --i) {
        if (vec[symbol][i] < j) {
            return j - vec[symbol][i];
        }
    }   
   return 0; 
}

vector<int> z_function(char str[], int n) {
    vector<int> z(n,0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
           z[i] = min(z[i - l], r - i + 1);
        } 
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
           z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }   
    }
    return z;
}

void RuleGoodSuffix(char str[], int n) {
    char ReversedStr[MAX_SIZE];
    vector<int> a(n, 0);
    cout<<"---\n";
    for (int i = 0; i < n; ++i) {
        ReversedStr[n - i - 1] = str[i];
    }
    for (int i = 0; i < n; ++i) { cout<< ReversedStr[i]<<' ';}
    cout<<'\n';
    vector<int> L = z_function(ReversedStr, n);
    for (int i = 0; i < L.size(); ++i) { cout << L[i] << ' '; }
    cout<<"\n---\n";
    vector<int> N(n, 0);
    for (int i = 0; i < n; ++i) { N[i] = L[n -i -1]; }
    cout << "---\n";
    for (int i = 0; i < n; ++i) { cout << N[i] << ' '; }
    cout<<"\n---\n";
    int j = 0;
    vector<int> _L(n, 0);
    cout<<"---\n";
    for (int i = 0; i < n-1; ++i) { 
        j = n - N[i] + 1;
        if (j > n) {
            _L[j] = 0;
        } else {
            _L[j] = i;
        }
    }
    for (int i = 0; i < n; ++i ) { cout<< _L[i] << ' '; }
    cout<<"\n---\n";
}

int main() {
    char Text[MAX_SIZE];
    char Pattern[MAX_SIZE];
    char Alphabet[26];
    cin>>Text;
    cin>>Pattern;
    int SizeText = length(Text);
    int SizePattern = length(Pattern);
    vector<vector<int>> RBS(MAX_ALP);
    int i = SizePattern - 1;
    int j = SizePattern - 1;
    int displace = 0;
    int n = length(Pattern);
    RuleGoodSuffix(Pattern, n);
    while (i <= SizeText-1) {
        if (Text[i - displace] == Pattern[j]) {
            displace++;
            --j;
            if (displace == SizePattern) {
                cout<< i - displace + 1 <<' ';
                j = SizePattern - 1;
                i++;
                displace = 0;   
            }    
        }
        else {
            int shift = RuleBadSymbol(j, Text[i - displace] - 97, RBS);            
            if (shift > 0) {
                i += shift;
            }
            else {
                i += (j + 1);
            }
            j = SizePattern - 1;
        }
    } 
}
