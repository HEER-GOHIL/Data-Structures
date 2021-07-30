class Solution {
    
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string>ans;
        int n=digits.length();
        if(n==0)return ans;
        for(int i=0;i<n;i++){
            maker(m,ans,digits[i]);
        }
        return ans;
    }
    void maker(unordered_map<char,string>m,vector<string>&ans,char a){
        if(ans.size()==0){
            for(int i=0;i<m[a].length();i++){
                string s;
                s+=m[a][i];
                ans.push_back(s);
            }
        }
        else{
            vector<string>k;
            for(int i=0;i<ans.size();i++){
                string s=ans[i];
                for(int j=0;j<m[a].length();j++){
                    string p=s+m[a][j];
                    k.push_back(p);
                }
            }
            ans=k;
        }
    }
};
//not my code :/
