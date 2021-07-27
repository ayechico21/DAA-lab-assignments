#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

bool search(int arr[], int n, int i, int x){ //return if x exist in array or not
    int low=i+1,high=n-1,mid;
    while(low<=high){
        mid= (low+high)/2;
        if(arr[mid] == x) return true;
        if(arr[mid] > x) high=mid-1;
        else low=mid+1;
    }
    return false;
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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int key;
        cin>>key;

        sort(arr,arr+n);
        int cnt=0;
        for(int i=0;i<n-1;i++){ //fix one element of pair
            if(search(arr,n,i,key+arr[i])) cnt++; //Binary search for the other element
        }
        cout<<cnt<<endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}