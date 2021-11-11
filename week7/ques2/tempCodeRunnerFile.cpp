int p;
    for(int i=1;i<=5;i++){
        p=i;
        while(par[p] != -1){
            cout<<p<<" ";
            p = par[p];
        }
        cout<<source<<": "<<dis[i]<<endl;
    }