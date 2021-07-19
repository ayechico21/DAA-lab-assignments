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

        int i=2,cnt=0;
        while(i <n){
            cnt++;
            if(k < arr[i]){
                break;
            }
            i+=2;
        }

        bool flag= false;
        i= i-2;
        while(i<n){
            cnt++;
            if(arr[i] == k){
                flag= true;
                break;
            }
            i++;
        }
        if(flag) cout<<"Present\t";
        else cout<<"Not Present\t";
        cout<<cnt<<endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}