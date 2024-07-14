#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int cnt = 0;
unordered_map<int, int> m;
int arr[100001] = {0, 0, 1, };
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;

        if(m.find(num) == m.end()) m[num] = 1;
        else m[num]++;
    }

    for(auto i: m){
        int num = i.first;
        int toFind = k - num;

        if(m.find(toFind) == m.end()) continue;

        if(num == toFind) cnt += i.second * (i.second - 1);
        else cnt += i.second *m[toFind];
    }

    cout << cnt/2;
    return 0;
}