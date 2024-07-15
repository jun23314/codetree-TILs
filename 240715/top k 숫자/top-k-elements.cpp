#include <iostream>
#include <set>

using namespace std;

int n, k;
int num;
set<int> s;
set<int>::reverse_iterator it;
int main() {
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> num;
        s.insert(num);
    }

    int cnt = 0;
    for(it = s.rbegin(); it != s.rend(); --it){
        if(cnt == k) break;
        cout << *it << " ";
        cnt++;
    }

    
    return 0;
}