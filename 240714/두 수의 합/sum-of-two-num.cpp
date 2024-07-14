#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int cnt = 0;
unordered_map<int, int> m;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;

        if(m.find(num) == m.end()) m[num] = 1;
        else m[num]++;
    }

    for(auto i: m){
        int toFind = k - i.first;
        if(m.find(toFind) == m.end()) continue;

        if(toFind == (i.second) && m.find(toFind)->second > 1) cnt += 2;
        else cnt++;
    }

    cout << cnt/2;
    return 0;
}