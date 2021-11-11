#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

void dijskstra(int n, int source,  vector<pair<int,int>> adj[]){
    vector<int> dis(n+1,INT_MAX);
    vector<int> par(n+1,-1);
    dis[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,source));
    int dist, adjnode, wt, node;
    while(!pq.empty()){
        dist= pq.top().first;
        node= pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            wt= it.first;
            adjnode= it.second;
            if(dist + wt < dis[adjnode]){
                pq.push(make_pair(dist+ wt, adjnode));
                par[adjnode]= node;
                dis[adjnode]= dist+wt;
            }
        }
    }
    int p;
    for(int i=1;i<=5;i++){
        p=i;
        while(par[p] != -1){
            cout<<p<<" ";
            p = par[p];
        }
        cout<<source<<": "<<dis[i]<<endl;
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
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>wt;
            if(wt > 0){
                adj[i].push_back(make_pair(wt,j));
            }
        }
    }
    int source;
    cin>>source;
    dijskstra(n, source, adj);
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}