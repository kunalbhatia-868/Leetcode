class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> strMap;
        
        for(int i=0;i<words.size();i++){
            strMap[words[i]]++;
        }
        
        int total=0;
        bool flag=true;
        for(int i=0;i<words.size();i++){
            string curr=words[i];

            if(words[i][0]==words[i][1])
            {
                int ct=strMap[curr];
                if(ct%2==0)
                {
                    total+=(ct*2);
                }
                else{
                    if(flag){
                        total+=(ct*2);
                        flag=false;
                    }
                    else{
                        total+=((ct-1)*2);
                    }
                }
                strMap.erase(curr);
            }
            else
            {
                string rev;
                rev+=words[i][1];
                rev+=words[i][0];
            
                int ct=min(strMap[rev],strMap[curr]);
                total+=(ct*4);
                strMap.erase(rev);
                strMap.erase(curr);
            }
        }
        
        return total;
        
    }
};