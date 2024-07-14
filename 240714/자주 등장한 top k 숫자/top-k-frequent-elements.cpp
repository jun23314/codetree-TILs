#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
unordered_map<int, int> m;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        m[num]++;
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    vector<pair<int, int>> :: iterator it;
    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    for(it = v.end() - 1; it >= v.begin(); --it){
        if(cnt == k) return 0;

        cout << it->first << " ";
        cnt++;
    }
}