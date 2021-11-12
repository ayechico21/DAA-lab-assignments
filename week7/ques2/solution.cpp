#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

void bellmanFord(int n, int source, vector<pair<int,int>> adj[]){
    vector<int> dis(n+1, INT_MAX);
    vector<int> par(n+1, -1);
    dis[source]= 0;
    int dist, node, wt, adjnode;
    for(int j=1;j<n;j++){
        for(int i=1;i<=n;i++){
            for(auto it: adj[i]){
                wt= it.first;
                adjnode= it.second;
                if(wt + dis[i] < dis[adjnode]){
                    dis[adjnode] = wt + dis[i];
                    par[adjnode]= i;
                }
            }
        }
    }

    int p;
    for(int i=1;i<=n;i++){
        p=i;
        while(par[p] != -1){
            cout<<p<<" ";
            p = par[p];
        }
        cout<<source<<" : "<<dis[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int n; 
    cin>>n;
    vector<pair<int,int>> adj[n+1];
    int wt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>wt;
            if(wt > 0){
                adj[i].push_back(make_pair(wt,j));
            }
        }
    }
    int source;
    cin>>source;
    bellmanFord(n, source, adj);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}