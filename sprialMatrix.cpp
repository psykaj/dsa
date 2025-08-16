#include <iostream>
#include <vector>
using namespace std;

// It has only one soltion & make it easy implementation 
// Optimal Approch
// Tc = O(N*M);
// Sc = O(N) -> store final ans 
vector<int> sprialOrder(vector<vector<int>>& arr) {
    int rowSize = arr.size();
    int colSize = arr[0].size();
    vector<int> ans;
    
    int left = 0;
    int right = colSize-1;
    int top = 0;
    int bottom = rowSize-1;
    
    while(top <= bottom && left <= right) {
        
        for(int i=left;i<right;i++) {
        ans.push_back(arr[top][i]);
        }
        
        top++;
        
        for(int i=top;i<bottom;i++) {
            ans.push_back(arr[i][right]);
        }
        
        right--;
        if(top <= bottom) {
            for(int i=right;i>=left;i--) {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i=bottom;i>=top;i--) {
                ans.push_back(arr[i][left]);
            }
            // print another sprial matrix 
            left++;
        }
    }
    return ans;
}

int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    
    cout<<"Before sprial Order : "<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<int> ans = sprialOrder(arr);
    
    cout<<"After sprial Order : "<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}