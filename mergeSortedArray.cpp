#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Lc -> 88. Merge Sorted Array
// Problem link -> https://leetcode.com/problems/merge-sorted-array/

// Brute force 
// Tc = O(N2) + (NlogN);
// Sc = O(1);
// void mergeSortedArray(vector<int>& arr1,int n1,vector<int>& arr2,int n2) {
//     for(int i=0;i<n2;i++) {
//         arr1[n1+i] = arr2[i];
//     }
//     sort(arr1.begin(),arr1.end());
// }

// Better approch 
// Tc = O(N)
// Sc = O(N);
// void mergeSortedArray(vector<int>& arr1,int n1,vector<int>& arr2,int n2) {
//     vector<int> arr1Copy(arr1.begin(),arr1.begin()+n1);
//     // cout<<"print arr1Copy : "<<endl;
//     // for(int i=0;i<n1;i++) {
//     //     cout<<arr1Copy[i]<<" ";
//     // }
//     // cout<<endl;
    
//     int ptr1 = 0;
//     int ptr2 = 0;
//     // to traverse result 
//     int p = 0;
    
//     while(ptr1 < n1 && ptr2 < n2) {
//         if(arr1Copy[ptr1] <= arr2[ptr2]) {
//             arr1[p] = arr1Copy[ptr1];
//             ptr1++;
//         } else {
//             arr1[p] = arr2[ptr2];
//             ptr2++;
//         }
//         p++;
//     }
    
//     // for remaining element for arr1Copy
//     while(ptr1 < n1) {
//         arr1[p] = arr1Copy[ptr1];
//         ptr1++;
//         p++;
//     }
    
//     // For remaining element for arr2
//     while(ptr2 < n2) {
//         arr1[p] = arr2[ptr2];
//         ptr2++;
//         p++;
//     }
// }

// Optimal Approch 
// Tc = O(N);
// Sc = O(1);
void mergeSortedArray(vector<int>& arr1,int n1,vector<int>& arr2,int n2) {
    int ptr1 = n1-1;
    int ptr2 = n2-1;
    // to traverse the result 
    int p = n1 + n2 - 1;
    
    while(ptr1 >= 0 && ptr2 >= 0) {
        if(arr1[ptr1] >= arr2[ptr2]) {
            arr1[p] = arr1[ptr1];
            ptr1--;
        } else {
            arr1[p] = arr2[ptr2];
            ptr2--;
        }
        p--;
    }
    // first arr1 will set into while loop 
    // only 2 array will traverse
    while(ptr2 >= 0) {
        arr1[p] = arr2[ptr2];
        ptr2--;
        p--;
    }
}

void printArray(vector<int>& arr,int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr1 = {1,2,3,0,0,0};
    int n1 = arr1.size();
    vector<int> arr2 = {2,5,6};
    int n2 = arr2.size();
    mergeSortedArray(arr1,n2,arr2,n2);
    cout<<"After sort array is : "<<endl;
    printArray(arr1,n1);
    return 0;
}