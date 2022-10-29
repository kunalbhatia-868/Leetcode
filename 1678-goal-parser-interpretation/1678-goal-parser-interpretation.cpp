class Solution {
public:
    string interpret(string command) {
        for(int i=0;i<command.size();i++)
        {
            if(command[i]=='(')
            {
                if(command[i+1]==')')
                {
                    command=command.substr(0,i)+"o"+command.substr(i+2);
                }
                else
                {
                    command=command.substr(0,i)+"al"+command.substr(i+4);
                }
            }       
        }
        return command;
    }
};