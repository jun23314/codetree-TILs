#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005][1005] = {0, };
int leng[1005] = {0, };
bool visited[1005][1005] = {0, };
int n, m;

void initVisited(){
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            visited[i][j] = 0;
        }
    }
}

void initLeng(){
    for(int i = 0; i <= n; ++i){
        leng[i] = 1001;
    }
}

void dfs(int node){
    for(int i = 1; i <= n; ++i){
        if ( arr[node][i] != 0 ){//간선이 존재한다면
            if( !visited[node][i] ){ // 아직 방문 안했으면
                visited[node][i] = 1; //방문해야지
                leng[i] = min(leng[i], leng[node] + arr[node][i]);
                //cout << node << " " << i << endl;
                dfs(i);
            }
        }

    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n-1; ++i) {
        int s, e, v;
        cin >> s >> e >> v;
        arr[s][e] = v;
        arr[e][s] = v;
    }

    for(int i = 0; i < m; ++i){
        int start, end;
        cin >> start >> end;
        
        initVisited();
        initLeng();

        //visited[start][end] = 1;
        leng[start] = 0;
        dfs(start);

        cout << leng[end] << endl;
    }


    return 0;
}