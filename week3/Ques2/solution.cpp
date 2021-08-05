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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int cmp=0,swaps=0,temp,k;
        for(int i=0;i<n-1;i++){
            k=i;
            for(int j=i+1;j<n;j++){
                cmp++;
                if(arr[j] < arr[k])  
                    k=j;
            }
            temp=arr[i];
            arr[i]=arr[k];
            arr[k]=temp;
            swaps++;
        }
        for(int x: arr) cout<<x<<" ";
        cout<<endl;
        cout<<"Comparisons: "<<cmp<<endl<<"Shifts: "<<swaps<<endl;
        
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}