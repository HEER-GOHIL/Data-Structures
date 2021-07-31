class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		set<string>st;
        int flag = 0;
        for(auto email : emails)
        {
            int i= 0;
            flag = 0;
            string s;

                while(flag==0)
                {
                    if(email[i]=='@' || email[i]=='+')
                    {
                        flag = 1;
                        break;
                    }
                    else if(email[i]=='.')
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        s = s + email[i];
                        i++;
                    }
                }
            if(email[i]=='+')
            {
                while(email[i]!='@')
                {
                    i++;
                }
            }
            s.append(email,i,email.length()-1);
            st.insert(s);
            
        }
        return st.size();
	}
};
