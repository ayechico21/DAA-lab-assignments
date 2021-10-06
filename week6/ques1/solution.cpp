#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

bool visited[100005]; //keep track of visited nodes

void bfs(vector<vector<int>>& adj,int start,int end){
    queue<int> q; //keep track of nodes
    q.push(start); //traverse from start node
    visited[start]=true; //start is visited
    while(!q.empty()){
        int node= q.front();
        q.pop();
        for(int x: adj[node]){ //traversing all childs of current node
            if(visited[x] == false){ //if unvisited ,push and mark visited
                q.push(x);
                visited[x]=true;
            }
            else if(x == end){ //if current node is destination
                cout<<"Path Found\n";
                return;
            }
        }
    }
    cout<<"No Path found\n"; //since traversal nodes from from start are traversed
}

void dfs(vector<vector<int>>& adj,int start,int end){
    stack<int> q; //keep track of nodes
    q.push(start); //traverse from start node
    visited[start]=true; //start is visited
    while(!q.empty()){
        int node= q.top();
        q.pop();
        for(int x: adj[node]){ //traversing all childs of current node
            if(visited[x] == false){ //if unvisited ,push and mark visited
                q.push(x);
                visited[x]=true;
            }
            else if(x == end){ //if current node is destination
                cout<<"Path Found\n";
                return;
            }
        }
    }
    cout<<"No Path found\n"; //since traversal nodes from from start are traversed
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    memset(visited,0,sizeof(visited)); //marking all nodes as unvisited
    int n;
    cin>>n;
    int x;
    vector<vector<int>> adj;
    vector<int> v;
    adj.push_back(v); //since no 0 node

    //making a adjacency list
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x) v.push_back(j);
        }
        adj.push_back(v);
    }
    //start and end nodes
    int start,end;
    cin>>start>>end;


    bfs(adj,start,end);
    //dfs(adj,start,end);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" <<"\n";

    return 0;
}