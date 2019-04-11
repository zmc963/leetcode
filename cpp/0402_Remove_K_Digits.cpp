class Solution
{
    using SIZE_TYPE = std::string::size_type;

    void Combination(
        const std::string& num,
        SIZE_TYPE start,
        int chosenMaxCnt,
        int currChosenCnt,
        std::string currAns,
        std::string& ans ) const
    {
        assert( currChosenCnt <= chosenMaxCnt );
        assert( chosenMaxCnt <= num.size() );
        assert( start <= num.size() );

        const auto SIZE = num.size();
        if( start==SIZE || currChosenCnt==chosenMaxCnt )
        {
            if( currChosenCnt == chosenMaxCnt )
            {
                ans = ans.empty() ? currAns : std::min(ans, currAns);
            }

            return;
        }

        for( SIZE_TYPE i=start; i<SIZE; ++i )
        {
            Combination( num, i+1, chosenMaxCnt, currChosenCnt+1, currAns+num.at(i), ans );
        }
    }

public:
    string removeKdigits(string num, int k)
    {
        if( k>num.size() || k<0 ) return {};

        string ans;
        const auto KEEP = num.size() - k;
        for( auto c : num )
        {
            while( k>0 && !ans.empty() && ans.back()>c )
            {
                ans.pop_back();
                --k;
            }

            //if( ans.size() < KEEP )
            ans += c;
        }
        ans.resize(KEEP);

        for( SIZE_TYPE i=0; i<KEEP; ++i )
        {
            if( '0' != ans.at(i) )
            {
                return ans.substr(i);
            }
        }

        return "0";

        // TLE
        // std::string ans;
        // Combination( num, 0, num.size()-k, 0, "", ans );
    }
};
