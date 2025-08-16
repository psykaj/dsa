#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimal Approch 
// Tc = O(N/2 * N/2) [transpose] + O(N * N/2) [Reversal];
// Sc = O(1);
void rotateImage(vector<vector<int>>& arr) {
    // row size 
    int n = arr.size();
    // int m = arr[0].size();
    
    // transpose Matrix 
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }
    
    // Reverse array 
    for(int i=0;i<n;i++) {
        reverse(arr[i].begin(),arr[i].end());
    }
}

int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    cout<<"Before rotate : "<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    rotateImage(arr);
    
    cout<<"After rotate : "<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}