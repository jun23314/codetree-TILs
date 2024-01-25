#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int uf[100001];

typedef struct Line{
    int s;
    int e;
    int v;
};

int find(int x){
    if(uf[x] == x) return x;
    int root = find(uf[x]);
    uf[x] = root;
    return root;
}

bool compare(const Line &a, const Line &b){
    if(a.v == b.v) {
        if (a.s == b.s){
            return a.e < b.e;
        }
        else return a.s < b.s;
    }
    else return a.v < b.v;
}

int unions(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b){
        return 0;
    }
    else{
        uf[b] = a;
        return 1;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        uf[i] = i;
    }

    Line line[100001];
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        line[i].s = a;
        line[i].e = b;
        line[i].v = c;
    }

    sort(line, line+m, compare);

    int weight = 0;
    for(int i = 0; i < m; ++i){
        if(unions(line[i].s, line[i].e)) weight += line[i].v;
    }

    cout << weight;
    
    return 0;
}