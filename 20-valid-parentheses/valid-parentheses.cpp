class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return false;
        vector<char> st(s.size());
        int ptr = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st[ptr++] = ')';
            else if(s[i] == '[') st[ptr++] = ']';
            else if(s[i] == '{') st[ptr++] = '}';
            else{
                if(ptr == 0 || st[--ptr] != s[i]) return false;
            }
        }
        return ptr == 0;
    }
};