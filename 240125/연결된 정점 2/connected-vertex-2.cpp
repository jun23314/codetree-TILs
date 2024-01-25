#include <iostream>

using namespace std;

int n;
int uf[100001];
int size[100001];

int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;   
}

void unions(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a != b){
        uf[a] = b;
        size[b] += size[a];
    }
    
}

int main() {
    cin >> n;

    for(int i = 1; i <= 100000; ++i){
        uf[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        unions(a, b);
        cout << size[b] << endl;
    }
    return 0;
}