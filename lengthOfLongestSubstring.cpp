#include <iostream>
using namespace std;

// Brute force 
// Tc = O(N^2);
// Sc = O(256);
// int lengthOfLongestSubstring(string str,int n) {
//     int len = 0;
//     int maxLen = 0;
//     for(int i=0;i<n;i++) {
//         bool temp[255] = {0};
//         for(int j=i;j<n;j++) {
//             if(temp[str[j]] == 1) {
//                 break;
//             }
//             int len = j-i+1;
//             maxLen = max(maxLen,len);
//             temp[str[j]] = 1;
//         }
//     }
//     return maxLen;
// }

// Two Pointer/sliding window (substring)
// Optimal Approch -> Dry Run 
// Tc = O(N);
// Sc = O(1);
int lengthOfLongestSubstring(string str,int n) {
    int temp[255] = {-1};
    int left = 0;
    int right = 0;
    int maxLen = 0;
    
    while(right < n) {
        if(temp[str[right]] != -1) {
            if(temp[str[right]] >= left) {
                left = temp[str[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxLen = max(maxLen,len);
        temp[str[right]] = right;
        right++;
    }
    return maxLen;
}

int main()
{
    string str = "abcabcbb";
    int n = str.length();
    int ans = lengthOfLongestSubstring(str,n);
    cout<<"The length of longest substring is : "<<ans<<endl;
    return 0;
}