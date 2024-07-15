#include <iostream>
#include <set>

using namespace std;

int n, m;
int x, y;
set<pair<int, int>> s;
int main() {
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        s.insert({x, y});
    }

    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        if(s.upper_bound(make_pair(x, y)) == s.end()) cout << "-1 -1\n";
        else cout << s.upper_bound(make_pair(x, y))->first << " " << s.upper_bound(make_pair(x, y))->second << "\n";
    }

    return 0;
}