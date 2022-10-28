class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords=0;
        int curr=1;
        for(int i=0;i<sentences.size();i++)
        {
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                {
                    curr++;
                }
            }
            maxWords=max(maxWords,curr);
            curr=1;
        }
        return maxWords;
    }
};