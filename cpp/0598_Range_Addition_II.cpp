class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        for( auto& o : ops )
        {
            if( 0!=o.at(0) && 0!=o.at(1) )
            {
                m = std::min( m, o.at(0) );
                n = std::min( n, o.at(1) );
            }
        }

        return m*n;
    }
};

