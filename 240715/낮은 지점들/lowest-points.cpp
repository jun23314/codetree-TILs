#include <iostream>
#include <unordered_map>

using namespace std;

int n;
long long x, y;
unordered_map<long long, long long> m;
int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &x, &y);
        
        if(m.find(x) == m.end()) m[x] = y;
        else{
            if(m.find(x)->second > y) m[x] = y;
        }
    }

    long long sum = 0;
    for(auto i: m){
        sum += i.second;
    }
    
    printf("%lld", sum);
    return 0;
}