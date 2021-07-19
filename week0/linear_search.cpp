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
        int comparisons =0; //store comparisons
        bool flag=false;
        for(int i=0;i<n;i++){
            comparisons++; 
            if(arr[i] ==  k){
                flag=true; //element found
                break;
            }
        }
        if(flag)
            cout<<"Present\t";
        else
            cout<<"Not Present\t";
        cout<<comparisons<<endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}