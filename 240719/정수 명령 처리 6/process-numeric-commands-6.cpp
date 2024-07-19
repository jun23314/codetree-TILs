#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
string cmd;
int a;
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> cmd;
        if(cmd == "push"){
            cin >> a;
            q.push(a);
        }
        else{
            if(cmd == "pop") {
                cout << q.top() << "\n";
                q.pop();
            }
            else if(cmd == "size") cout << q.size() << "\n";
            else if(cmd == "empty") cout << q.empty() << "\n";
            else cout << q.top() << "\n";
        }
    }
    return 0;
}