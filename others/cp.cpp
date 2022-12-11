#include<iostream>
#include<bits/stdc++.h>
#include<map>
int main()
{
    using namespace std;
    int m,n,t,a[100];
    map<int, int> m;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        m.insert(pair<int,int>(a[i],0));
    }
    for (int i = 0; i < n; i++){
        m[a[i]]+=1;
    }
    
    }
}