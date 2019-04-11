class Solution
{
    void Preorder( int start, int n, std::vector<int>& res )
    {
        start *= 10;
        for( int i=0; i<=9 && start+i<=n; ++i )
        {
            res.push_back(start+i);
            Preorder( start+i, n, res );
        }
    }

public:
    vector<int> lexicalOrder(int n)
    {
        if( n < 1 ) return {};

        std::vector<int> res;

        for( int i=1; i<=9 && i<=n; ++i )
        {
            res.push_back(i);
            Preorder( i, n, res );
        }

        return res;
    }
};


