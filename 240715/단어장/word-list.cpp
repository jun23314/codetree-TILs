#include <iostream>
#include <map>

using namespace std;

int n;
string str;
map<string, int> m;
int main() {
    cin >> n;

    for(int i = 0; i< n; ++i){
        cin >> str;

        m[str]++;
    }

    for(auto i: m){
        cout << i.first << " " << i.second << "\n";
    }
    
    return 0;
}