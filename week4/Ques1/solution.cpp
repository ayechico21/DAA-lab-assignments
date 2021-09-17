#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Mod 1000000007
using namespace std;
int com; // comparions
int inv; //Total inversions
//Inversion: arr[i]>arr[j] for i < j

void merge(int arr[],int l,int m, int r){
    int n1,n2; //size of temp array
    n1=m-l + 1;
    n2=r-m;
    //Creating and filling both temp array
    int left[n1],right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[l+i];
    for(int i=0;i<n2;i++) right[i]=arr[m+1+i];

    int i,j,k;
    i=0;
    j=0;
    k=l;
    //Arranging elements in arr in sorted order using temp arrays
    while(i < n1 && j < n2){
        com++;
        if(left[i] <= right[j]) arr[k++]=left[i++];
        else {
            arr[k++]=right[j++];
            inv+= (n1-i);
            /*If b[j] < a[j] then b[j] < all remaining elements in a(i+1,i+2..n1)since a is sorted*/
            }
    }
    //If any temp array is not empty
    while(i < n1) arr[k++]= left[i++];
    while(j < n2) arr[k++]= right[j++];
}

void mergesort(int arr[], int l, int r){
    if(l >= r) return;
    int m= (l+r)/2; // finding mid point
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
}

void solve(){
    com=0;
    inv=0;
    int n;
    cin>>n;
    int arr[n];
    for(int& x: arr) cin>>x;
    mergesort(arr,0,n-1);
    for(int x :arr) cout<<x<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<com<<endl;
    cout<<"Inversions: "<<inv<<endl;
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