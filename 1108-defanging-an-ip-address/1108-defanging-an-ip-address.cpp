class Solution {
public:
    string defangIPaddr(string address) {
        // for(int i=0;i<address.size();i++)
        // {
        //     if(address[i]=='.')
        //     {
        //         address=address.substr(0,i)+"[.]"+address.substr(i+1);
        //     }
        // }
        // return address;
        string output;
        for(int i=0;i<address.size();i++)
        {
            if(address[i]=='.')
            {
                output+="[.]";
            }
            else
            {
                output+=address[i];
            }
        }
        return output;
    }
};