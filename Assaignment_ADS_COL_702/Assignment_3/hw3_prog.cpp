//1308 1605
#include<iostream>
#include<vector>
#include<fstream>    //for classes i/o of file
#include <sstream>
#include <vector>
#include <string>
/*
   1.fstreambase
   2.ifstream ->derived from fstreambase
   3.ofstrea ->derived from fstreambase
   2 way to open file 1.) using constructor  2.) using the member function open() of the class
*/
using namespace std;

int  file_read(int &N,vector<int>& array1,vector<int>& array2)
{
              std::ifstream inputFile("input-2.txt");
    
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
  
 bool create_matrix(vector<vector<int> >&M,int &N,vector<int> & rowSum,vector<int >& colSum,int i,int j)
 {
            for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rowSum[i] > 0 && colSum[j] > 0) {
                M[i][j] = 1;  // Place a 1 in the matrix
                rowSum[i]--;  // Reduce the row and column sums
                colSum[j]--;
            }
        }
            }
            return true; 
 }
int main() {

    int N;       //order of matrix 
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
    cout<<endl<<"Possible or not"<<S<<endl<<endl;
    int r=0,c=0;
    if(S)
      {
           create_matrix(M,N,RowSum,ColSum,0,0);
           for(int i=0;i<N;i++)
              { r=0;
                for(int j=0;j<N;j++)
                   {
                    cout<<M[i][j]<<" ";
                    r=r+M[i][j];
                   }
                   cout<<r<<" "<<endl;
              }
      }
    else  cout<<endl<<S;  
    return 1 ;

};