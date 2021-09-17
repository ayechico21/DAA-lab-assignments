#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

int partition(int arr[],int l,int r){
    int pivot= arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j] < pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[++i],arr[r]);
    return i;
}

int quicksort(int arr[], int l, int r,int k){
    int p= partition(arr,l,r); //Pivot element position
    if(p == k) return arr[p];
    if(l >= r) return -1;
    if(p > k) return quicksort(arr,l,p-1,k);
    else return quicksort(arr,p+1,r,k);
}

void solve(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int& x: arr) cin>>x;
    cin>>k;
    for(int x: arr) cout<<x<<" ";
    cout<<endl;
    cout<<quicksort(arr,0,n-1,k-1)<<endl;
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