class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort( g.begin(), g.end() );
        std::sort( s.begin(), s.end() );

        const auto G_SIZE = g.size();
        const auto S_SIZE = s.size();

        SIZE_TYPE g_idx = 0;
        for( SIZE_TYPE s_idx=0; s_idx<S_SIZE && g_idx<G_SIZE; ++s_idx )
        {
            if( s.at(s_idx) >= g.at(g_idx) ) ++g_idx;
        }

        return g_idx;
    }
};
