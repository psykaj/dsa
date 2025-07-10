#include <iostream>
#include <stack>
using namespace std;
// Do Atleast 5 dry run to understand 
// Brute force approch 
// Tc = O(N^2);
// Sc = O(1);
int celebrityProblem(int arr[3][3]) {
    for(int i=0;i<3;i++) {
        bool flag1 = true;
        // check for the rows
        for(int j=0;j<3;j++) {
            if(i != j && arr[i][j] != 0) {
                flag1 = false;
                break;
            }
        }
        
        // if flag1 is true then 
        if(flag1) {
            // check for the cols 
            bool flag2 = true;
            for(int j=0;j<3;j++) {
                if(i != j && arr[j][i] != 1) {
                    flag2 = false;
                    break;
                }
            }
            
            if(flag2) {
                // i'th Index is the Celeb 
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[3][3] = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int ans = celebrityProblem(arr);
    cout<<"The Index number is the celebrity : "<<ans<<endl;
    return 0;
}

// Optimal Solution 
// Tc = O(N);
// Sc = O(N); -> using stack DS 
int celebrityProblem(int arr[3][3]) {
    stack<int> st;
    // push all the Index into the stack 
    for(int i=0;i<3;i++) {
        st.push(i);
    }
    
    // pop top 2 index and check their element till stack has 1 element
    while(st.size() != 1) {
        int firstElement = st.top();
        st.pop();
        
        int secondElement = st.top();
        st.pop();
        
        // firstElement knows secondElement  
        if(arr[firstElement][secondElement]) {
            //firstElement is not then secondElement might  celeb
            st.push(secondElement);
        } else {
            //secondElement is not then firstElement might be celeb
            st.push(firstElement);
        }
    }
    
    // when stack has last element in it 
    // chcek single element is actually a celeb 
    int mightBeCeleb = st.top();
    st.pop();
    
    // first check the rows 
    for(int i=0;i<3;i++) {
        if(arr[mightBeCeleb][i] != 0) {
            return -1;
        }
    }
    
    // second check the cols 
    for(int i=0;i<3;i++) {
        if(arr[i][mightBeCeleb] != 1 && i != mightBeCeleb) {
            return -1;
        }
    }
    return mightBeCeleb;
    
}

int main()
{
    int arr[3][3] = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int ans = celebrityProblem(arr);
    cout<<"The Index number is the celebrity : "<<ans<<endl;
    return 0;
}