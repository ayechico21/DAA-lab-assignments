#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

void solve(){
    int n;
    cin>>n;
    char arr[n];
    for(char &x: arr) cin>>x;

    int count[26];
    memset(count,0,sizeof(count)); //initialising occurence array with 0's
    for(char x: arr){
        count[x-'a']++;
    }
    char ans;
    int occur=INT_MIN;
    for(int i=0;i<26;i++){ //finding max occurence element index
        if(occur < count[i]){
            occur=count[i];
            ans= 'a'+i;
        }
    }
    if(occur == 1) cout<<"No Duplicates\n";
    else cout<<ans<<"-"<<occur<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}