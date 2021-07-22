class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
            vector<string>v;
            backtrack(v,0,0,n,"");
            return v;    
    }
     void backtrack(vector<string>& output,int open,int close,int max,string curr){
        if(curr.length()==max*2)
        {
            output.push_back(curr);
            return;
        }
        if(open<max)
        {
            backtrack(output,open + 1,close,max,curr + "(");
        }
        if(close<open)
        {
            backtrack(output,open,close+1,max,curr + ")");
        }
    }
};
   
