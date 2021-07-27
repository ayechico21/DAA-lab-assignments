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
        for(int i=0;i<n;i++) 
            cin>>arr[i];
        int key;
        cin>>key;

        int low,high,mid,cnt;
        low=0;
        high=n-1;
        cnt=0;
        while(low<= high){ //Binary search for key
            mid=(low+high)/2;
            if(arr[mid] == key) {
                cnt=1; // key found
                break;
            }
            if(arr[mid] < key)
                low=mid+1;
            else
                high=mid-1;
        }
        
       if(cnt){ //if key exist
       //mid is index of key
           int i;

           i=mid-1;
           while(i >= 0 && arr[i] == key){ //counting keys present on left side of key index
               i--;
               cnt++;
            }

           i=mid+1;
           while(i<n && arr[i] == key) { //counting keys present on right side of key index
               i++;
               cnt++;
            }

           cout<<key<<" - "<<cnt<<endl;
       }
       else
        cout<<"Key not present\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}