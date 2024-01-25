#include <iostream>

using namespace std;

int n, m, k;
int uf[100001];

int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;
}

void unions(int x, int y){
    int a = find(x);
    int b = find(b);
    uf[a] = b;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        uf[i] = i;
    }
    
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        unions(a, b);
    }

    if (k == 1) {
        cout << 1;
        return 0;
    }
    int a;
    cin >> a;
    for(int i = 0; i < k; i++){
        int b;
        cin >> b;
        if(find(a) != find(b)){
            cout << 0;
            return 0;
        }
        cin >> a;
    }
    cout << 1;
    return 0;
}