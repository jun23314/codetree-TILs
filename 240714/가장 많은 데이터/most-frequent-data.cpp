#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> m;
int main() {
    cin >> n;

    int maxi = 0;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;

        if(m.find(str) == m.end()) m[str] = 1;
        else m[str]++;

        if(m[str] > maxi) maxi = m[str];
    }

    cout << maxi;
    return 0;
}