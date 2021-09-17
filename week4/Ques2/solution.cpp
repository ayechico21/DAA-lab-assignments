#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;

int com;
int swaps;

int partition(int arr[],int l, int r){
    int pivot= arr[r]; //taking last element as pivot
    int i=l-1;
    for(int j=l;j<r;j++){
        com++;
        //arranging all element less than pivot before pivot's correct position
        if(arr[j] < pivot){
            swaps++;
            swap(arr[++i],arr[j]);
        }
    }
    swaps++;
    swap(arr[++i],arr[r]); //swapping pivot element at its correct position
    return i;
}
void quicksort(int arr[], int l, int r){
    if(l >= r) return;
    int p= partition(arr,l,r); //Pivot element position
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
}

void solve(){
    com=0;
    swaps=0;
    int n;
    cin>>n;
    int arr[n];
    for(int&x : arr) cin>>x;
    quicksort(arr,0,n-1);
    for(int x: arr) cout<<x<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<com<<endl;
    cout<<"Swaps: "<<swaps<<endl;
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