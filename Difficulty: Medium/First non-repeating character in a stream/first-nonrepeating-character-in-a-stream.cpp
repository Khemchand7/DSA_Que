//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    //using array for freq 
    string FirstNonRepeating1(string A){
        queue<char> q;  // Queue to store characters that might be non-repeating
        int freq[26] = {0};  // Frequency array to count occurrences of characters, assuming only lowercase letters ('a' to 'z')
        
        string result = "";  // Initialize an empty string to store the result
        
        // Iterate through each character in the input string
        for(int i = 0; i < A.size(); i++){
            char ch = A[i];  // Get the current character
            
            // Increment the frequency of the current character
            freq[ch - 'a']++;
            
            // Push the current character into the queue (might be a candidate for non-repeating)
            q.push(ch);
            
            // Remove characters from the front of the queue if they are no longer non-repeating
            while(!q.empty() && freq[q.front() - 'a'] > 1){
                q.pop();  // Pop the character if its frequency is more than 1 (it is repeating)
            }
            
            // Check the queue status
            if(q.empty()){
                // If the queue is empty, no non-repeating character, so append '#'
                result += '#';
            }
            else{
                // If the queue is not empty, the front of the queue is the first non-repeating character
                result += q.front();
            }
        }
        
        return result;  // Return the final result string after processing the entire input
    }
    //using map function
    string FirstNonRepeating(string A){
        map<char,int>freq;
        string result = "";
        queue<char>q;
        
        for(int i=0;i<A.size();i++){
            char ch = A[i];
            
            freq[ch]++;
            
            q.push(ch);
            
            while(!q.empty() && freq[q.front()] > 1){
                q.pop();
            }
            if(q.empty()) result+='#';
            else result+=q.front();
        }
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
