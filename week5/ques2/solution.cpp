#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

void solve(){
    int n,key;
    cin>>n;
    int arr[n];
    for(int& x: arr) cin>>x;
    cin>>key;
    sort(arr,arr+n);
    int i=0,j=n-1,sum=0;
    bool flag=true;
    while(i<j){
        sum=arr[i]+arr[j];
        if(sum == key){
            flag=false;
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(sum < key) i++;
        else j--;
    }
    if(flag) cout<<"No pair found...\n";
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