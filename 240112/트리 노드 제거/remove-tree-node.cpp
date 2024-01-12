#include <iostream>
#include <vector>

using namespace std; 

vector<int> arr[51];
vector<int>::iterator it;
bool deleted[51] = {0, };
int cnt = 0;

void dfs(int node){
    if (deleted[node]) return;

    bool leaf = 1;

    for(it = arr[node].begin(); it != arr[node].end(); ++it){
        int new_node = *it;
        if(deleted[new_node]) continue;
        dfs(new_node);
        leaf = 0;
    }
    if(leaf) cnt++;
}
int main() {
    int n;
    cin >> n;

    int root = 0;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        
        if(a == -1) root = i;
        else arr[a].push_back(i);
    }

    int del;
    cin >> del;

    deleted[del] = 1;

    dfs(root);

    cout << cnt;
    return 0;
}