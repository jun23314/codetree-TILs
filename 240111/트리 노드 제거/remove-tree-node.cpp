#include <iostream>
#include <stack>
using namespace std; 

stack<int> s;
int main() {
    int n;
    cin >> n;

    int start = -1;
    int arr[51];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(arr[i] == -1) start = i;
    }

    int del;
    cin >> del;
    arr[del] = -2;

    while(1) {
        for(int i = 0; i < n; ++i){
            if(arr[i] == del){
                arr[i] = -2;
                s.push(i);
            }
        }
        
        if(s.empty()) break;
        del = s.top();
        s.pop();
    }
    
    stack<int> k;
    int ans = 0;
    while(1) {
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == start){
                arr[i] = -2;
                s.push(i);
                cnt++;
            }
        }
        if(cnt == 0) ans++;
        
        if(s.empty()) break;
        del = s.top();
        s.pop();
    }

    cout << ans;

    return 0;
}