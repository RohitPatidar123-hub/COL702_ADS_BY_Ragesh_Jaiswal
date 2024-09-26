//1308 1605
#include<iostream>
#include<vector>
#include<fstream>    //for classes i/o of file
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int  file_read(int &N,vector<int>& array1,vector<int>& array2)
{
              std::ifstream inputFile("input-3.txt");
    
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int n;
    std::string line;
    
    // Read the first line (integer)
    std::getline(inputFile, line);
    n = std::stoi(line);
    N=n;
    

    // Read the second line (first array)
    std::getline(inputFile, line);
    std::stringstream ss1(line);
    std::string number;

    while (std::getline(ss1, number, ',')) {
        array1.push_back(std::stoi(number));
    }

    // Read the third line (second array)
    std::getline(inputFile, line);
    std::stringstream ss2(line);

    while (std::getline(ss2, number, ',')) {
        array2.push_back(std::stoi(number));
    }

    

    inputFile.close();
    return 1;
};
int sum_of_row(vector<int>&RowSum)
{
    int sum=0;
    for(int i=0;i<RowSum.size();i++)
             {
                      sum+=RowSum[i];
             }
             return sum;
};
int max_in_row(vector<int>&RowSum)
{
     int max=0;
    for(int i=0;i<RowSum.size();i++)
             {
                  if(max<RowSum[i])
                    {
                        max=RowSum[i];
                    }   
             }
             return max;
}
int sum_of_col(vector<int>&ColSum)
{
    int sum=0;
    for(int i=0;i<ColSum.size();i++)
             {
                      sum+=ColSum[i];
             }
             return sum;
};
int max_in_col(vector<int>&ColSum)
{
    int max=0;
    for(int i=0;i<ColSum.size();i++)
             {
                  if(max<ColSum[i])
                    {
                        max=ColSum[i];
                    }   
             }
             return max;

}
int non_zero_col(vector<int> &ColSum)
{
        int non_zero=0;
        for(int i=0;i<ColSum.size();i++)
             {
                  if(ColSum[i]!=0)
                    {
                        non_zero=non_zero+1;
                    }   
             }
             return non_zero;
}
int non_zero_row(vector<int> &RowSum)
{
        int non_zero=0;
        for(int i=0;i<RowSum.size();i++)
             {
                  if(RowSum[i]!=0)
                    {
                        non_zero=non_zero+1;
                    }   
             }
             return non_zero;
}

bool check_matrix(int &N,vector<int> & RowSum,vector<int >& ColSum)
 {
            int r_sum=0,c_sum=0,r_max,c_max,r_non,c_non;
            r_sum=sum_of_row(RowSum);                      //return sum of all row
            c_sum=sum_of_col(ColSum);                      //return sum of all col
            r_max=max_in_row(RowSum);                      //return max in row
            c_max=max_in_col(ColSum);                      //return max in col
            r_non=non_zero_row(RowSum);                    // return no. of non-zero in row
            c_non=non_zero_col(ColSum);                     //return no. of non-zero in col
            cout<<"r_sum : "<<r_sum<<" c_sum : "<<c_sum<<" r_max : "<<r_max<<" c_max : "<<c_max<<" r_non : "<<r_non<<" c_non : "<<c_non<<" N : "<<N;
            if(r_sum!=c_sum || r_max>N || c_max>N || r_max>c_non ||c_max>r_non)
                return 0;
            else return 1;    

 };
  
//  int  create_matrix(vector<vector<int> >&M,int &N,vector<int> & rowSum,vector<int >& colSum,int i,int j)
//  {
//                     if(i==N || j==N)
//                       {
                           
//                       }
//                     else {
//                                    if(rowSum[i]>0 && colSum[j]>0)
//                                     {
//                                         if(M[i][j]==0)
//                                             {M[i][j]++;
//                                             rowSum[i]--;
//                                             colSum[j]--;
//                                             };
//                                         create_matrix(M,N,rowSum,colSum,i+1,j);
//                                         create_matrix(M,N,rowSum,colSum,i,j+1);
//                                     }
//                                     else if(rowSum[i]>0 && colSum[j]==0)
//                                            {
//                                                 create_matrix(M,N,rowSum,colSum,i,j+1);

//                                            }
//                                            else if(rowSum[i]==0 && colSum[j]>0 )
//                                              { 
//                                                  create_matrix(M,N,rowSum,colSum,i+1,j);
//                                              }
//                                              else if(rowSum[i]==0 && colSum[j]==0)
//                                                    {
//                                                       create_matrix(M,N,rowSum,colSum,i+1,j+1);
//                                                    }

//                                   }  
//                              return 1;     
//  }
//  int  create_matrix(vector<vector<int> >&M,int &N,vector<int> & rowSum,vector<int >& colSum,int i,int j)
//  {
//                  vector<pair<int,int>> rowpair,colpair;
//                 for(int i=0;i<N;i++)
//                     {
//                            rowpair.emplace_back(rowSum[i],i);
//                            colpair.emplace_back(colSum[i],i);
//                     }  
//                     // for(int i=0;i<N;i++)
//                     // {
//                     //       cout<<rowpair[i].first<<" "<<rowpair[i].second<<" "<<colpair[i].first<<" "<<colpair[i].second<<" "<<endl;
//                     // }
//                     sort(rowpair.begin(), rowpair.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
//                         if (a.first != b.first)
//                         return a.first > b.first;
//                         else
//                     return a.second < b.second; 
//                     });

//                     sort(colpair.begin(), colpair.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
//                         if (a.first != b.first)
//                         return a.first > b.first;
//                         else
//                     return a.second < b.second; 
//                     });

//                           for(int i=0;i<N;i++)
//                        {
//                             cout<<rowpair[i].first<<" "<<rowpair[i].second<<" "<<colpair[i].first<<" "<<colpair[i].second<<" "<<endl;
//                        }

                
//                     return 1;
                    
                               
 //}
int main() {

    int N,r=0,c=0,i,j;       //order of matrix 
    bool  S;     //0 is not possible 1 if possible
    vector<int> RowSum,ColSum;
    file_read(N,RowSum,ColSum);
    vector<vector<int> > M(N, vector<int>(N, 0));
    cout<<"no. of element in row :"<<RowSum.size()<<endl;
    cout<<"no. of element in col :"<<ColSum.size()<<endl<<endl;
    cout<<"Row Sum : ";
    for (int num =0;num<RowSum.size();num++) {
        std::cout << RowSum[num] << " ";
    }
    cout<<endl<<endl;
    cout<<"Col Sum : ";
    for (int num =0;num<ColSum.size();num++) {
        std::cout << ColSum[num] << " ";
    }
    cout<<endl<<endl;
    S=check_matrix(N,RowSum,ColSum);
    cout<<endl<<"Possible or not"<< S <<endl<<endl;
    vector<int> total_col,remaing_col;
    if(S)
      {
           for(i=0;i<N;i++)                       // converge rowsum
              {
                for(int j=0;j<RowSum[i];j++)
                    {
                        M[i][j]=1;
                    }
              }
             for(int i=0;i<N;i++)                    //for finding total_col ,remaing_col
              { r=0;
                for(int j=0;j<N;j++)
                   {
                    
                    r=r+M[j][i];
                   }
                total_col.push_back(r);  
                remaing_col.push_back(r-ColSum[i]);
                cout<<r<<" "; 
              }
              cout<<endl;
              for(int i=0;i<N;i++)                   //print colsum
                 cout<<ColSum[i]<<" ";
              cout<<endl;
              r=0;
              for(int i=0;i<N;i++)                  //print remaing 
              { r=r+remaing_col[i];
                 cout<<remaing_col[i]<<" ";

              }
              cout<<endl<<"Remaing sum:"<<r<<endl;
           //create_matrix(M,N,RowSum,ColSum,0,0);
            if(r==0)
                {
                     i=0;
                     j=N-1;
                     while(i<j)
                      {
                            for(int k=0;k<N  && remaing_col[i]!=0 && remaing_col[j]!=0;k++)
                               {
                                                if(M[k][i]==1 && M[k][j]==0)
                                                    {
                                                        M[k][i]=0;
                                                        M[k][j]=1;
                                                        remaing_col[i]-=1;
                                                        remaing_col[j]+=1;

                                                    } 
                                                                                        
                               }
                            if(remaing_col[i]==0 && remaing_col[j]==0) 
                               {
                                   i+=1;
                                   j-=1;
                               }
                            else if(remaing_col[i]!=0 && remaing_col[j]==0) 
                                 {
                                
                                    j=j-1;
                                 }  
                                 else if(remaing_col[i]==0 && remaing_col[j]!=0)
                                       {
                                           i=i+1;
                                       }


                      }    
  


                }
            else if (r==0  && S==false )
                    {
                        cout<<"0";
                    }
            vector<int >check_row,check_col;       
           for(int i=0;i<N;i++)        //print matrix 
              { r=0;
                for(int j=0;j<N;j++)
                   {
                    cout<<M[i][j]<<" ";
                    r=r+M[i][j];
                    
                
                   }
                   check_row.push_back(r);
                   cout<<"\n";
                  
              }
              for(int i=0;i<N;i++)        //print matrix 
              { r=0;
                for(int j=0;j<N;j++)
                   {
                    r=r+M[j][i];
            
                   }  
                   check_col.push_back(r);  
              }
               cout<<"\n";
            for(int i=0;i<N;i++)
               {
                  cout<<check_row[i]<<" ";
               } 
               cout<<"\n";
            for(int i=0;i<N;i++)
               {
                  cout<<check_col[i]<<" ";
               } 
               

      }
    
    else  cout<<endl<<S;  
    return 1 ;

};
     