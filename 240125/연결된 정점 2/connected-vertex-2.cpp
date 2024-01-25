#include <iostream>

using namespace std;

const int MAX_N = 100001;

int parent[MAX_N];
int componentSize[MAX_N];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootX] = rootY;
        componentSize[rootY] += componentSize[rootX];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 100000; ++i) {
        parent[i] = i;
        componentSize[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int sizeA = componentSize[find(a)];
        int sizeB = componentSize[find(b)];

        unionSets(a, b);

        cout << sizeA + sizeB << endl;
    }

    return 0;
}