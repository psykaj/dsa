#include <iostream>
using namespace std;

int main()
{
    int row = 3;
    int col = 3;
    int arr[row][col];
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>arr[i][j];
        }
    }
    
    cout<<"Print 2D matrix : "<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}