#include <iostream>

using namespace std;
int n, m;
int uf[100001];

int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;
}

void unions(int x, int y){
    int a = find(x);
    int b = find(y);
    uf[a] = b;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        uf[i] = i;
    }

    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            unions(b, c);

        }
        else{
            if(find(b) == find(c)) cout << 1 << endl;
            else cout << 0 << endl;

        }
    }
    return 0;
}