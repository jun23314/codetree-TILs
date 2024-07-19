#include <iostream>
#include <queue>

using namespace std;

int n, m;
int num;
priority_queue<int> q;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> num;
        q.push(num);
    }

    for(int i = 0; i < m; ++i){
        int now = q.top();
        now--;
        q.pop();
        q.push(now);
    }

    cout << q.top();
    return 0;
}