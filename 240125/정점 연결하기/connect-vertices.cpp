#include <iostream>

using namespace std;

int n;
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
    if (a != b) {
        uf[a] = b;
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i){
        uf[i] = i;
    }

    for(int i = 2; i < n; ++i){
        int a, b;
        cin >> a >> b;
        unions(a, b);
    }

    //근데 사실 1번이랑 뭐 연결할지만 찾으면 되는거 아닌가....?
    int root = find(1);
    for(int i = 1; i <= n; ++i){
        if(find(i) == root) continue;
        else{
            cout << 1 << " " << i;
            break;
        }
    }
    return 0;
}