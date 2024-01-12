#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> e;
unordered_set<int> s;
unordered_set<int> all;
vector<int> arr[1001];
bool visited[1001] = {0, };

void dfs(int node){
    for(auto i : arr[node]){
        if(!visited[node])
        visited[i] = 1;
        dfs(i);
    }
}



int main() {
    int m;
    cin >> m;

    int ans = 0;
    bool flag = 0;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        s.insert(a);
        if(e.find(b) != e.end()) flag = 1;
        e.insert(b);
        all.insert(a);
        all.insert(b);
    }

    //2번 조건 확인
    if (flag){
        cout << "0";
        return 0;
    }

    int cnt = 0;
    int root = 0;
    for(auto i : s){
        if(e.find(i) == e.end()) {
            cnt++;
            root = i;
        }
    }

    //1번 조건 확인
    if (cnt != 1){
        cout << "0";
        return 0;
    }


    //3번 조건 확인
    visited[root] = 1;
    dfs(root);
    for(auto i : all){
        if(!visited[i]){
            cout << "0";
            return 0;
        }
    }





    cout << "1";
    return 0;
}