#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

int search(int arr[], int n, int sum){ //function to search if sum of i,j exist in array
    int low=0,high=n-1,mid;
    while(low <= high){
        mid= (low+high)/2;
        if(arr[mid] == sum) return mid;
        if(arr[mid] > sum) high=mid-1;
        else low=mid+1;
    }
    return -1;
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

        int i,j,k;
        bool flag= false;
        for(i=0;i<n-2;i++){ //fix first element of pair
            for(j=i+1;j<n-1;j++){ //fix second element of pair
                k=search(arr,n,arr[i]+arr[j]); //Binary search to find index of sum if it exist
                if( k != -1){
                    flag=true; //pair found
                    break;
                }
            }
            if(flag) break; 
        }
        if(flag) cout<<i<<" "<<j<<" "<<k<<endl;
        else cout<<"No sequence found\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}