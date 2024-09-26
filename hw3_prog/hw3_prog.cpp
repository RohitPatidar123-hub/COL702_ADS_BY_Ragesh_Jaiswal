//1308 1605
#include<iostream>
#include<vector>
#include<fstream>    //for classes i/o of file
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int file_read(int &N, vector<int>& array1, vector<int>& array2)
{
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;

    // Read the first line (integer N)
    if (std::getline(inputFile, line)) {
        if (!line.empty()) {
            try {
                N = std::stoi(line);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid input for N: '" << line << "'" << std::endl;
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Input for N out of range: '" << line << "'" << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Error: First line is empty, cannot convert to integer!" << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Error: Failed to read the first line!" << std::endl;
        return 1;
    }

    // Read the second line (first array)
    if (std::getline(inputFile, line)) {
        std::stringstream ss1(line);
        std::string number;

        while (std::getline(ss1, number, ',')) {
            // Trim whitespace
            number.erase(0, number.find_first_not_of(" \t\n\r\f\v"));
            number.erase(number.find_last_not_of(" \t\n\r\f\v") + 1);

            if (!number.empty()) {
                try {
                    array1.push_back(std::stoi(number));
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number in first array: '" << number << "'" << std::endl;
                    return 1;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Number out of range in first array: '" << number << "'" << std::endl;
                    return 1;
                }
            } else {
                std::cerr << "Error: Empty value found in first array." << std::endl;
                return 1;
            }
        }
    } else {
        std::cerr << "Error: Failed to read the second line!" << std::endl;
        return 1;
    }

    // Read the third line (second array)
    if (std::getline(inputFile, line)) {
        std::stringstream ss2(line);
        std::string number;

        while (std::getline(ss2, number, ',')) {
            // Trim whitespace
            number.erase(0, number.find_first_not_of(" \t\n\r\f\v"));
            number.erase(number.find_last_not_of(" \t\n\r\f\v") + 1);

            if (!number.empty()) {
                try {
                    array2.push_back(std::stoi(number));
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid number in second array: '" << number << "'" << std::endl;
                    return 1;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Number out of range in second array: '" << number << "'" << std::endl;
                    return 1;
                }
            } else {
                std::cerr << "Error: Empty value found in second array." << std::endl;
                return 1;
            }
        }
    } else {
        std::cerr << "Error: Failed to read the third line!" << std::endl;
        return 1;
    }

    inputFile.close();
    return 0; // Success
}

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
            //cout<<"r_sum : "<<r_sum<<" c_sum : "<<c_sum<<" r_max : "<<r_max<<" c_max : "<<c_max<<" r_non : "<<r_non<<" c_non : "<<c_non<<" N : "<<N;
            if(r_sum!=c_sum || r_max>N || c_max>N || r_max>c_non ||c_max>r_non)
                return 0;
            else return 1;    

 };
  

int main() {

    int N,r=0,i,j;      //order of matrix 
    bool  S;                 //0 is not possible 1 if possible
    ofstream outputFile("output.txt");
    vector<int> RowSum,ColSum;
    file_read(N,RowSum,ColSum);
    vector<vector<int> > M(N, vector<int>(N, 0));
    S=check_matrix(N,RowSum,ColSum);
    vector<int> total_col,remaing_col;
    if(S)//main code 
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
               
              }
            
              r=0;
              for(int i=0;i<N;i++)                  
              { r=r+remaing_col[i];
                

              }
              
           
            if(r==0)
                {
                     i=0;
                     j=N-1;
                     while(i<j)
                      {
                            int k=0;
                            for(k=0;k<N  && remaing_col[i]!=0 && remaing_col[j]!=0;k++)
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
                                       else if(k==N && remaing_col[i]!=0 && remaing_col[j]!=0)
                                              { 
                                                 outputFile<<"0";
                                                 return 0;
                                              }
                                               


                      }    

                }
            else if (r==0  && S==false )
                    {
                        outputFile<<"0";
                        return 0;
                    }  
            outputFile<<"1\n";   
            for(int i=0;i<N;i++)         
              { 
                r=0;
                for(int j=0;j<N;j++)
                   {
                    if(j<N-1)
                    outputFile<<M[i][j]<<",";
                    else outputFile<<M[i][j];
                   }
                   if(i<N-1)
                      outputFile<<"\n";   
              }   
        }
    else  outputFile<<"0";  
    return 0;
};
     