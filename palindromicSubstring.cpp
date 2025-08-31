#include <iostream>
using namespace std;

// bool isPalindrome(string str,int start,int end) {
//     while(start < end) {
//         if(str[start] != str[end]) {
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }

// Brute force -> find all substring compare each substring palindrom or not 
// Tc = O(N^2) [nested loop] + O(N) [checking palindrom] => O(N^3);
// Sc = O(1);
// int countSubstrings(string str,int n) {
//     int totalCount = 0;
//     for(int i=0;i<n;i++) {
//         for(int j=i;j<n;j++) {
//             if(isPalindrome(str,i,j)) {
//                 totalCount++;
//             } 
//         }
//     }
//     return totalCount;
// }

// Better approch -> using recursion (Include/Exclude)
// Optimal approch -> Expand around center approch
// Tc = O(N^2) 
// Sc = O(1);
int expand(string str,int start,int end) {
    int count = 0;
    while(start >= 0 && end <= str.length() && str[start] == str[end]) {
        count++;
        start--;
        end++;
    }
    return count;
}

int countSubstrings(string str,int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        // Odd case 
        int oddCase = expand(str,i,i);
        
        // Even case 
        int evenCase = expand(str,i,i+1);
        
        count = count + oddCase + evenCase;
    }
    return count;
}

int main()
{
    string str = "aaa";
    int n = str.length();
    int ans = countSubstrings(str,n);
    cout<<"The total palindromic substring count is : "<<ans<<endl;

    return 0;
}