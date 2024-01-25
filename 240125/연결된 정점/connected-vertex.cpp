#include <iostream>

using namespace std;

int n, m;
int uf[100001];
int size[100001] = {0, };

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
        size[b] += size[a];
        size[a] += size[b];
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        uf[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i < m; ++i){
        char what;
        cin >> what;
        if(what == 'x'){
            int a, b;
            cin >> a >> b;
            unions(a, b);

        }
        else{
            int a;
            cin >> a; 
            int seek = find(a); // 이러면 루트 노드가 나오겠징?
            cout << size[seek] << endl;
        }
    }
    return 0;
}