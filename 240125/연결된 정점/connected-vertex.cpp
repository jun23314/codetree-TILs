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
            int cnt = 0;
            for(int i = 1; i <= n; ++i){
                if(uf[i] == seek) cnt++;
            }

            cout << cnt << endl;
        }
    }
    return 0;
}