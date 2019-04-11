class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> ans;
        Parenthesis( n, 0, 0, "", ans );

        return ans;
    }

private:
    void Parenthesis( int n, int currN, int open, const std::string& currS, std::vector<std::string>& ans ) const
    {
        assert( n >= currN );
        // assert( currN >= open );

        if( (n==currN) || (n<currN+open) )
        {
            if( 0 == open )
            {
                ans.push_back(currS);
            }
            return;
        }

        if( 0 != open )
        {
            Parenthesis( n, currN, open+1, currS+'(', ans );

            Parenthesis( n, currN+1, open-1, currS+')', ans );
        }
        else
        {
            Parenthesis( n, currN, open+1, currS+'(', ans );
        }
    }
};
