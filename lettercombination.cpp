#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Tc = 
// Sc = 
void helper(string str,vector<string>& res,string temp,int index,
string mapping[]) {
    if(index >= str.size()) {
        res.push_back(temp);
        return;
    }
    
    // get the number and their corresponding letters 
    int number = str[index] - '0'; 
    string value = mapping[number];
    
    for(int i=0;i<value.size();i++) {
        temp.push_back(value[i]);
        helper(str,res,temp,index+1,mapping);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string str,int n) {
    vector<string> res;
    
    if(n == 0) {
        return res;
    }
    
    string temp = "";
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    helper(str,res,temp,index,mapping);
    return res;
}

int main()
{
    string str = "23";
    int n = str.length();
    vector<string> ans = letterCombinations(str,n);
    cout<<"After performing letter cobination : "<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}