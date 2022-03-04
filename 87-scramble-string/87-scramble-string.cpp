class Solution {
public:
    bool solve(const string A,const string B,unordered_map<string,bool>& strMap)
    {
        if(A==B)
        {
            return true;
        }

        if(A.size()<=1)
        {
            return false;
        }

        string c=A;
        c.append(" ");
        c.append(B);

        if(strMap.count(c))
        {
            return strMap[c];
        }

        for(int i=1;i<A.size();i++)
        {
            bool cond1=solve(A.substr(0,i),B.substr(B.size()-i,i),strMap) && solve(A.substr(i,A.size()-i),B.substr(0,B.size()-i),strMap);
            bool cond2=solve(A.substr(0,i),B.substr(0,i),strMap) && solve(A.substr(i,A.size()-i),B.substr(i,B.size()-i),strMap);

            if(cond1==true || cond2==true)
            {
                strMap[c]=true;
                return true;
            } 
        }
        strMap[c]=false;
        return false;

    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())
        {
            return false;
        }
        unordered_map<string,bool> strMap;

        return solve(s1,s2,strMap); 
    }
};