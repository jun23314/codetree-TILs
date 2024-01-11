#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Line{
    int end, value;
};

stack<int> s;
vector<Line> arr[100001];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int s, e, v;
        cin >> s >> e >> v;
        arr[s].push_back({e, v});
        arr[e].push_back({s, v});
    }

    int val[100001] = {0, };
    vector<Line>::iterator it;
    int start = 1;
    bool visited[100001] = {0, };

    while(1) {
        visited[start] = 1;
        for(it = arr[start].begin(); it != arr[start].end(); ++it){
            Line line = *it;
            if(!visited[line.end]){
                val[line.end] = val[start] + line.value;
                s.push(line.end);
            }
        }
        if(s.empty()) break;
        start = s.top();
        s.pop();
    }

    int max = -1;
    int idx = -1;
    for(int i = 1; i <= n; ++i){
        if(val[i] > max){
            max = val[i];
            idx = i;
        }
    }
    
    int vals[100001] = {0, };
    start = idx;
    bool visit[100001] = {0, };
    while(1) {
        visit[start] = 1;
        for(it = arr[start].begin(); it != arr[start].end(); ++it){
            Line line = *it;
            if(!visit[line.end]){
                vals[line.end] = vals[start] + line.value;
                s.push(line.end);
            }
        }
        if(s.empty()) break;
        start = s.top();
        s.pop();
    }

    max = -1;
    idx = -1;
    for(int i = 1; i <= n; ++i){
        if(vals[i] > max){
            max = vals[i];
            idx = i;
        }
    }

    cout << max;

    





    return 0;
}