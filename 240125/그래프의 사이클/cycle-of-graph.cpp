#include <iostream>

using namespace std;

int n, m;
int uf[100001];
bool flag = 0;

int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;
}

void unions(int x, int y){
    int a = find(x);
    int b = find(y);
    if (a != b) {
        uf[a] = b;
    }
    else flag = 1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        uf[i] = i;
    }
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        unions(a, b);
        if(flag){
            cout << i+1;
            return 0;
        }
    }
    cout << "happy";
    return 0;
}