#include <iostream>
using namespace std;

// Brute force approch 
// Tc = O(N^3);
// Sc = O(1);
// void printAllSubstring(string str,int n) {
//     for(int i=0;i<n;i++) {
//         for(int j=i;j<n;j++) {
//             for(int k=i;k<=j;k++) {
//                 cout<<str[k];
//             }
//             cout<<endl;
//         }
//     }
// }

// Better approch 
// Tc = O(N^2);
// Sc = O(1);
// void printAllSubstring(string str,int n) {
//     for(int i=0;i<n;i++) {
//         string ans = "";
//         for(int j=i;j<n;j++) {
//             ans += str[j];
//             cout<<ans<<endl;
//         }
//     }
// }

// Prefix / Suffix Substring 
// Tc = O(N);
// Sc = O(1);
void printPreSuffSubstring(string str,int n) {
    string temp = "";
    // for prefix 
    for(int i=0;i<n;i++) {
        temp += str[i];
        cout<<temp<<endl;
    }
    
    // for suffix 
    for(int i=n-1;i>=0;i--) {
        temp += str[i];
        cout<<temp<<endl;
    }
}

int main()
{
    string str = "abc";
    int n = str.length();
    // cout<<"Printing all the substring : "<<endl;
    // printAllSubstring(str,n);
    cout<<"Printing prefix/suffix substring : "<<endl;
    printPreSuffSubstring(str,n);
    return 0;
}