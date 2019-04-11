class Solution
{
public:
    string reverseWords(string s)
    {
        std::string ans;
        std::string word;
        std::istringstream is(s);

        while( is >> word )
        {
            std::reverse( word.begin(), word.end() );
            ans += word + " ";
        }

        ans.pop_back();
        return ans;
    }
};
