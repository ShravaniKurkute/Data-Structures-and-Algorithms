class Solution {
public:
    void fun(vector<string>& ans, int left, int right, int n, string s){
        if(s.size() == n*2){
            ans.push_back(s);
            return;
        }
        if(left < n) fun(ans, left+1, right, n, s+'(');
        if(right < left) fun(ans, left, right+1, n, s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(ans, 0, 0, n, "");
        return ans;
    }
};