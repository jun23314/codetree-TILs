#include <iostream>
#include <set>

using namespace std;

int n, m;
int num;
set<int> s;
int main() {
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= m; ++i){
        s.insert(i);
    }

    for(int i = 0; i < n; ++i){
        scanf("%d", &num);
        s.erase(num);
        printf("%d\n", *s.rbegin());
    }
    return 0;
}