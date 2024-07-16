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
        
        it = s.upper_bound(num);
        if(it == s.begin()) cout << "-1\n";
        else{
            it--;
            cout << *it << "\n";
            s.erase(*it);
        }
    }
    return 0;
}