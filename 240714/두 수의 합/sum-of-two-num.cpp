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

    for(int i = 3; i <= n; ++i){
        arr[i] = arr[i-1] + (i - 1);
    }

    for(auto i: m){
        int toFind = k - i.first;
        if(m.find(toFind) == m.end()) continue;

        int tmp = m.find(toFind)->second;
        if(toFind == (i.first) && tmp > 1) {
            cnt += 2 * (arr[tmp]);
        }
        else cnt++;
    }

    cout << cnt/2;
    return 0;
}