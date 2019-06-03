//soj 2772

#include <iostream>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int graph[102][102];
int n, k;
const int MAX = 1e9; 
const int MIN = -MAX;
set<int> p;
vector<int> connect[102];
bool in_queue[102];
int enter_times[102];
int dist[102];


void bfs(int src){
    bool visited[102];
    memset(visited, 0, sizeof(visited));
    queue<int> f;
    f.push(src);
    visited[src] = 1;
    p.insert(src);
    while(!f.empty()){
        int temp = f.front();
        f.pop();
        for(int i = 2; i <= n; i++)
            if(!visited[i] && graph[temp][i] != MAX){
                p.insert(i);
                f.push(i);
                visited[i] = 1;
            }
    }
}

bool bfs_through_p(int src){
    set<int> t;
    bool visited[102];
    memset(visited, 0, sizeof(visited));
    queue<int> f;
    f.push(src);
    visited[src] = 1;
    t.insert(src);
    while(!f.empty()){
        int temp = f.front();
        f.pop();
        for(int i = 2; i <= n; i++)
            if(!visited[i] && graph[temp][i] != MAX){
                t.insert(i);
                f.push(i);
                visited[i] = 1;
            }
    }
    if(t.find(n) == t.end()) return 1;
    return 0;
}

bool spfa(){
    memset(in_queue, 0, sizeof(in_queue));
    memset(enter_times, 0, sizeof(enter_times));
    for(int i = 0; i < 102; i++) dist[i] = MAX;
    // cout << dist[2];
    dist[1] = 0;
    queue<int> line;
    line.push(1);
    in_queue[1] = 1;
    enter_times[1] = 1;
    while(!line.empty()){
        int temp = line.front();
        line.pop();
        in_queue[temp] = 0;
        for(auto i : connect[temp]){
             // cout << i << " " << dist[i] << " " << graph[temp][i] << endl;
            if(dist[i] > dist[temp] + graph[temp][i]){
                dist[i] = dist[temp] + graph[temp][i];
                // cout << dist[i];
                if(!in_queue[i]){
                    line.push(i);
                    in_queue[i] = 1;
                    enter_times[i] ++ ;
                    if(enter_times[i] >= p.size()) return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++)
            graph[i][j] = MAX;
        graph[i][i] = 0;
    }
    
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a, b, d;
        cin >> a >> b >> d;
        graph[a][b] = min(graph[a][b], d);
    }
    p.insert(1);
    bfs(1);
    if(p.find(n) == p.end()){
        cout << -1 << endl;
        return 0;
    }
    for(auto i = p.begin(); i != p.end(); i++){
        if(bfs_through_p(*i))
            p.erase(i);
    }
    // for(auto i : p) cout << i << ' ';
    for(auto i = p.begin(); i != p.end(); i++){
        for(auto j = p.begin(); j != p.end(); j++)
            if(graph[*i][*j] != MAX && graph[*i][*j] != 0)
                connect[*i].push_back(*j);
    }
    if(spfa())
        cout << dist[n] << endl;
    else cout << 0 << endl;
}