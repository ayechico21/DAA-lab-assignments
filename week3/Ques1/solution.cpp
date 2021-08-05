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
        int key,i,j;
        int cmp=0,shifts=0;
        for(i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            while(j>=0 && key < arr[j]){
                arr[j+1]= arr[j];
                j--;
                cmp++;
                shifts++;
            }
            arr[j+1]=key;
            shifts++;
        }
        for(int x: arr) cout<<x<<" ";
        cout<<endl;
        cout<<"Comparisons: "<<cmp<<endl<<"Shifts: "<<shifts<<endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}