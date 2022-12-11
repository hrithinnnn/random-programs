#include<bits/stdc++.h>
    int main() {
        int matrix[100][100],n=3;
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                std::cin>>matrix[i][j];
              //  std::cout<<matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                std::cout<<matrix[i][j];
            }
            std::cout<<"\n";
        }
        //int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=n/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
                std::cout<<"x";

            }
        }
         for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                std::cout<<matrix[i][j];
            }
            std::cout<<"\n";
        }

        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                int temp=matrix[j][i];
                matrix[j][i]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                std::cout<<matrix[i][j];
            }
            std::cout<<"\n";
        }
        
    }
