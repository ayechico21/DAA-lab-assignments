#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

int colour[10005]; //keep track of node colour
/*
    0: set not alloted yet
    1:set 1:
    -1: set 2;
*/

void bfs(vector<vector<int>>& adj){
    queue<pair<int,int>> q;
    q.push(make_pair(0,1)); //start node 0 with colour 1;
    while(!q.empty()){
        int parent= q.front().first; //node value
        int pcolour=q.front().second; //node set
        q.pop();
        for(int x: adj[parent]){
            if(colour[x] == 0){
                colour[x]=pcolour*-1; // child should be in diffrent set than parent
                q.push(make_pair(x,colour[x]));
            }
            else if(colour[x] == pcolour){ //both child and parent in same set
                cout<<"Not a Bipartite Graph\n";
                return;
            }
        }
    }
    //Graph can be divided in two set
    cout<<"Bipartite Graph\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    memset(colour,0,sizeof(colour)); //all nodes are not in any set
    int n;
    cin>>n;
    int x;
    vector<vector<int>> adj;
    //making a adjacency list
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            cin>>x;
            if(x) v.push_back(j);
        }
        adj.push_back(v);
    }
    bfs(adj);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}