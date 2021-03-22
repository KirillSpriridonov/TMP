#include <iostream>

using namespace std;

int main() {
    int i = 0;
    cout<< (i>0)?5: -3; 
    cout<<"_________________________________\n";
for(int i = 0; i < SizePattern; ++i) {
        RBS[Pattern[i]-97].push_back(i);
}
for(int i = 0; i < RBS.size(); ++i) {
    cout<<char(97+i)<<'-';
    for(int j = 0; j < RBS[i].size(); ++j) {
        cout<<RBS[i][j]<< ' ';
    }
    cout<<'\n';
}
cout<<"_________________________________\n";

}
