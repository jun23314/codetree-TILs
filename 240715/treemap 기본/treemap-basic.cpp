#include <iostream>
#include <map>

using namespace std;

int n;
string cmd;
int k, v;
map<int, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> cmd;

        if(cmd == "add"){
            cin >> k >> v;
            m[k] = v;
        }
        else if(cmd == "remove" || cmd == "find"){
            cin >> k;
            if(m.find(k) == m.end()) cout << "None\n";
            else if(cmd == "remove") m.erase(k);
            else if(cmd == "find") cout << m.find(k)->second << "\n";
        }
        else{
            if(m.empty()) cout << "None";
            for(auto i: m) cout << i.second << " ";
            cout << "\n";
        }
    }

    return 0;
}