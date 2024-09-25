//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertSorted(stack<int>&s, int x){//yahan by reference pass nhi kia tha mistake ki
    //base case
    if(s.empty() || x > s.top()){//jab bhi top ko access kar rhe hai make sure stack is not empty
        s.push(x);
        return;
    }
    //ek case solve
    int temp = s.top();
    s.pop();
    //recursive call
    insertSorted(s,x);
    //backtracking
    s.push(temp);
}
void SortedStack :: sort()
{
    //Base case
   if(s.empty()){
       return;
   }
   //ek case solve
   int temp = s.top();
   s.pop();
   //RECURSIVE CALL
   sort();
   //backtracking
   insertSorted(s,temp);
   
   
}