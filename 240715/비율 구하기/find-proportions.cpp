#include <iostream>
#include <string>
#include <map>

using namespace std;

char n[5];
char str[30];
map<string, double> m;
int main() {
    scanf("%s", n);

    int n_ = stoi(n);
    int total = stod(n);
    for(int i = 0; i < n_; ++i){
        scanf("%s", str);

        m[str]++;
    }

    for(auto i : m){
        for(auto j: i.first) printf("%c", j);
        printf(" %.4lf\n", i.second / total * 100);
    }

    
    return 0;
}