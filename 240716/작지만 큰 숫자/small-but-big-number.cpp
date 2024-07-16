#include <iostream>
#include <set>

using namespace std;

int n, m;
int num;
set<int> s;
set<int> :: iterator it;
int main() {
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < m; ++i){
        cin >> num;
        
        it = s.lower_bound(num);
        if(it == s.end()) {
            it--;
            cout << *it << "\n";
            s.erase(*it);
        }
        else if(it != s.begin()){ // 답이 있다!
            if(it != s.find(num)) it--;
            cout << *it << "\n";
            s.erase(*it);
        }
        else cout << "-1\n";
    }
    return 0;
}