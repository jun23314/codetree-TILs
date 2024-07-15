#include <iostream>
#include <set>

using namespace std;

int n;
string cmd;
int x;
set<int> s;
int main() {
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> cmd;

        if(cmd == "largest" || cmd == "smallest"){
            if(s.empty()) cout << "None\n";
            else if(cmd == "largest") cout << *s.rbegin() << "\n";
            else if(cmd == "smallest") cout << *s.begin() << "\n";
        }
        else{
            cin >> x;
            if(cmd == "add") s.insert(x);
            else if(cmd == "remove") s.erase(x);
            else if(cmd == "find"){
                if(s.find(x) == s.end()) cout <<"false\n";
                else cout << "true\n";
            }
            else if(cmd == "lower_bound"){
                if(s.lower_bound(x) == s.end()) cout << "None\n";
                else cout << *s.lower_bound(x) << "\n";
            }
            else if(cmd == "upper_bound"){
                if(s.upper_bound(x) == s.end()) cout << "None\n";
                else cout << *s.upper_bound(x) << "\n";
            }
        }
    }
    return 0;
}