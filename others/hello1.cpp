 #include<bits/stdc++.h>
 using namespace std;
 int main() {
    int start=1;
    int a[100][100];
    int t[100][100];
    int ans[100][100];
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        a[i][j]=start;
        start++;
        t[j][i]=a[i][j];
    }
}

//

for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        ans[i][j]=0;
        for(int k=0;k<n;k++){
            ans[i][j]+=a[i][k]+t[k][j];
        }
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

    }

