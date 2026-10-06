class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0) return 0;
        int open = 0, toadd = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else{
                if(open > 0) open--;
                else toadd++;
            }
        }
        return open+toadd;
    }
};