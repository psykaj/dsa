#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Tc = O(NLogN);
// Sc = O(1);
// void sort012(vector<int>& arr,int n) {
//     sort(arr.begin(),arr.end());
// }

// better approch 
// Tc = O(N);
// Sc = O(1);
// void sort012(vector<int>& arr,int n) {
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;
    
//     for(int i=0;i<n;i++) {
//         if(arr[i] == 0) {
//             count0++;
//         } else if(arr[i] == 1) {
//             count1++;
//         } else if(arr[i] == 2) {
//             count2++;
//         }
//     }
    
//     for(int i=0;i<count0;i++) {
//         arr[i] = 0;
//     }
    
//     for(int i=count0;i<=count1;i++) {
//         arr[i] = 1;
//     }
    
//     for(int i=count0+count1;i<n;i++) {
//         arr[i] = 2;
//     }
// }

// Optimal approch -> 3 pointer 
// Tc = O(N);
// Sc = O(1);
void sort012(vector<int>& arr,int n) {
    int start = 0;
    int mid = 0;
    int end = n-1;
    
    while(mid <= end) {
        if(arr[mid] == 0) {
            swap(arr[mid],arr[start]);
            start++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else if(arr[mid] == 2) {
            swap(arr[mid],arr[end]);
            end--;
        }
    }
}

void printArray(vector<int> arr,int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // 2,0,2,1,1,0
    // 2,0,1
    vector<int> arr = {2,0,2,1,1,0};
    int n = arr.size();
    sort012(arr,n);
    printArray(arr,n);
    return 0;
}