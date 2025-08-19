#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute force 
// Tc = O(N^2);
// Sc = O(1);
// int majorityEle(vector<int>& arr,int n) {
//     int count = 0;
//     for(int i=0;i<n;i++) {
//         for(int j=i;j<n;j++) {
//             if(arr[i] == arr[j]) {
//                 count++;
//             }
//         }
//         if(count > n/2) {
//             return arr[i];
//         }
//     }
//     return -1;
// }

// Better approch 
// Tc = O(N) + O(N) => O(2N);
// Sc = O(N) -> using map 
// int majorityEle(vector<int>& arr,int n) {
//     map<int,int> mp;
//     for(int i=0;i<n;i++) {
//         mp[arr[i]]++;
//     }
    
//     for(auto m:mp) {
//         if(m.second > n/2) {
//             return m.first;
//         }
//     }
//     return -1;
// }

// Optimal approch -> Moore voting algo
// Tc = O(N);
// Sc = O(1);
int majorityEle(vector<int>& arr,int n) {
    int count = 0;
    int ele = arr[0];
    for(int i=0;i<n;i++) {
        if(count == 0) {
            ele = arr[i];
            count = 0;
        } else if(arr[i] == ele) {
            count++;
        } else {
            count--;
        }
    }
    
    int count1 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == ele) {
            count1++;
        }
    }
    
    if(count1 > n/2) {
        return ele;
    }
    
    return -1;
}

int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};
    int n = arr.size();
    int ans = majorityEle(arr,n);
    cout<<"The majority element is : "<<ans<<endl;

    return 0;
}