#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

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
        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) 
            cin>>arr[i];
        cin>>k;
        bool flag=false;
        int low=0,high=n-1,mid,cnt=0;
        while(low<=high){
            cnt++;
            mid= (low+high)/2;
            if(arr[mid] == k){
                flag=true;
                break;
            }
            if(arr[mid] < k)
                low=mid+1;
            else
                high= mid-1;
        }
        if(flag) cout<<"Present\t";
        else cout<<"Not Present\t";
        cout<<cnt<<endl;

    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}