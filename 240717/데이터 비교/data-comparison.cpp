#include <iostream>
#include <unordered_set>
using namespace std;

int n, m, number;
int num[100001];
unordered_set<int> s;
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> number;
        s.insert(number);
    }

    cin >> m;
    for(int i = 0; i < m; ++i) cin >> num[i];

    for(int i = 0; i < m; ++i){
        if(s.find(num[i]) == s.end()) cout << "0 ";
        else cout << "1 ";
    }

    return 0;
}