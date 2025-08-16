#include <iostream>
#include <vector>
using namespace std;

// Brute force
// Tc = [O(N*M) + O(N+M)] + O(N*M) => [O(N*M) + O(N+M)];
// Sc = O(1);
// void setMatrixZeros(vector<vector<int>>& arr) {
//     int n = arr.size();
//     int m = arr[0].size();
    
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             if(arr[i][j] == 0) {
//                 // markRow(i);
//                 for(int k=0;k<n;k++) {
//                     if(arr[i][k] != 0) {
//                         arr[i][k] = -1;
//                     }
//                 }
//                 // markCol(j);
//                 for(int k=0;k<m;k++) {
//                     if(arr[k][j] != 0) {
//                         arr[k][j] = -1;
//                     }
//                 }
//             }
//         }
//     }
    
//     // Now convert -1 to 0 
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             if(arr[i][j] == -1) {
//                 arr[i][j] = 0;
//             }
//         }
//     }
// }

// Better Aprroch 
// Tc = O(2*N*M);
// Sc = O(N) + O(M) -> for extra vector for hashing 
// void setMatrixZeros(vector<vector<int>>& arr) {
//     int rowSize = arr.size();
//     int colSize = arr[0].size();
    
//     vector<int> row(rowSize,0),col(colSize,0);
    
//     for(int i=0;i<rowSize;i++) {
//         for(int j=0;j<colSize;j++) {
//             if(arr[i][j] == 0) {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
    
//     for(int i=0;i<rowSize;i++) {
//         for(int j=0;j<colSize;j++) {
//             if(row[i] || row[j]) {
//                 arr[i][j] = 0;
//             }
//         }
//     }
    
// }

// Optimal Approch 
// Tc = O(2*N*M) => O(N*M);
// Sc = O(1);
void setMatrixZeros(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    // for reference 
    // int row[n] = {0} -> arr[..][0]
    // int col[m] = {0} -> arr[0][..]
    int col0 = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                // mark ith row
                arr[i][0] = 0;
                // mark jth col
                if(j != 0) {
                    arr[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(arr[i][j] != 0) {
                // check for row & col 
                if(arr[i][0] == 0 || arr[0][j] == 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    
    if(arr[0][0] == 0) {
        // col all first element 0
        for(int j=0;j<m;j++) {
            arr[0][j] = 0;
        }
    }
    
    if(col0 == 0) {
        // row all first element 0
        for(int i=0;i<n;i++) {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    int row = 3;
    int col = 4;
    vector<vector<int>> arr = {{0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    
    cout<<"Before converting : "<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    setMatrixZeros(arr);
    
    cout<<"After converting : "<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}