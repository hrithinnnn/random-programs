#include <bits/stdc++.h>
using namespace std;
#define ppi pair<int,int>

class Compare {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.first == b.first) 
                return a.second > b.second; 
            return a.first < b.first; 
        }
};
 
void solve(vector<int> &arr){
    int N = arr.size();
    unordered_map<int ,int> mpp; 
    for(int a : arr){
        mpp[a]++;
    }

    priority_queue<ppi,vector<ppi>, Compare> maxH;
     
    for( auto m : mpp){
        maxH.push({m.second, m.first}); 
    }

    int i=0; 
    while(maxH.size()>0){
        int val = maxH.top().second; 
        int freq = maxH.top().first; 
         
        while(freq-- ){
            arr[i] = val;
            i++;
        }
        maxH.pop(); 
    }
     
}
 
int main()
{
    vector<int> vec{ 2, 5, 2, 8, 5, 6, 8, 8 };
    int n = vec.size();
  
    solve(vec);
  
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
      cout<<"\n";
    return 0;
}