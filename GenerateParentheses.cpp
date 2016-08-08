class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        if(n > 0)
            generate(n, path, result, 0, 0);
        return result;
    }
    
    void generate(int n, string& path, vector<string>& result, int l, int r)
    {
        if(l == n)
        {
            string s(path);
            result.push_back(s.append(n - r, ')'));
            return;
        }
        
        path.push_back('(');
        generate(n, path, result, l + 1, r);
        path.pop_back();
        
        if(l > r)
        {
            path.push_back(')');
            generate(n, path, result, l, r + 1);
            path.pop_back();
        }
    }
};