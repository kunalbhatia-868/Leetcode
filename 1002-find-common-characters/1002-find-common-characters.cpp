class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int charCount[26]={0};
        for(int i=0;i<words[0].size();i++)
        {
            char ch=words[0][i];
            charCount[ch-'a']+=1;
        }
        
        for(int i=1;i<words.size();i++){
            string curr=words[i];
        
            int charCurrCount[26]={0};
            
            for(int j=0;j<curr.size();j++)
            {
                char ch=curr[j];
                charCurrCount[ch-'a']+=1;
            }
            
            for(int k=0;k<26;k++)
            {
                charCount[k]=min(charCount[k],charCurrCount[k]);
            }
        }
        
        vector<string> output;
        
        for(int i=0;i<26;i++)
        {
            // cout<<charCount[i]<<endl;
            char ch='a'+i;
            string str;
            str += ch;
            int count=charCount[i];
            while(count){
                output.push_back(str);
                count--;
            }
        }
        
        return output;
    }
};