class Solution {
public:
    string defangIPaddr(string ip) {
       string str;
        for(int i=0; i <ip.length(); i++){
            if(ip[i] == '.'){
                str.push_back('[');
                str.push_back('.');
                str.push_back(']');
            }
            else{
                str.push_back(ip[i]);
            }
        }
        return str;
    }
};
