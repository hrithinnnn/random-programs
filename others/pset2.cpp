#include<bits/stdc++.h>
using namespace std;

void prefixsum(vector<int> &n) {
    for(int i=1;i<n.size();i++) {
        n[i] = n[i-1] + n[i];
    }
}

void check(vector<int> n, int n1, vector<int> q, int q1) {
    sort(n.begin(), n.end(), greater<int>());
    int sum = accumulate(n.begin(), n.end(), 0);
    prefixsum(n);
    for(int i=0;i<q1;i++) {
        if(q[i] > sum) cout<<"-1"<<endl;
        else {
            int j=0;
            while(q[i]>0) {
                if(n[j] >= q[i]) {
                    q[i]-=n[j];
                }
                else j++;
            }
            cout<<j+1<<endl;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n1, q1;
        cin>>n1>>q1;
        vector <int> n(n1), q(q1);
        for(int i=0;i<n1;i++) cin>>n[i];
        for(int i=0; i<q1;i++) cin>>q[i];
        check(n,n1,q,q1);
    }
    return 0;
}