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
        bool flag= false;

        //sorting
        int i,j,key;
        for(i=1;i<n;i++){
            j=i-1;
            key=arr[i];
            while(j>=0 && key < arr[j]){
                arr[j+1]= arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        //checking for duplicate
        for(i=1;i<n;i++){
            if(arr[i] == arr[i-1]){
                flag=true; //duplicate found
                break;
            }
        }

        cout<< (flag?"Yes":"No")<<endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}