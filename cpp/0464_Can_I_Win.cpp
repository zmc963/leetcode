class Solution
{
    using SIZE_TYPE = std::vector<bool>::size_type;

    // this func means under current state, is the win condition met?
    bool CanWinImp(
        int desiredTotal,
        SIZE_TYPE countChosenInt,
        int chosenIntEncoding,
        std::vector<bool>& visitedInt,
        std::unordered_map<int, bool>& memo ) const
    {
        // since the func works based on the logic true -> false -> true -> false
        // so if "visitedInt.size() >= countChosenInt", we should return false all the way up
        // which contradicts with the functionality of this func
        assert( visitedInt.size() >= countChosenInt );
        assert( desiredTotal >= 0 );

        if( memo.count(chosenIntEncoding) )
        {
            return memo.at(chosenIntEncoding);
        }

        const auto SIZE = visitedInt.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( visitedInt.at(i) ) continue;

            int cur = (1 << i);
            visitedInt.at(i) = true;
            if( (i+1>=desiredTotal) || !CanWinImp( desiredTotal-(i+1), countChosenInt+1, cur|chosenIntEncoding, visitedInt, memo ) )
            {
		// we only need to encoding true, false is not important here
                memo[chosenIntEncoding] = true;
                visitedInt.at(i) = false;
                return true;
            }
            visitedInt.at(i) = false;
        }

        memo[chosenIntEncoding] = false;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        // this line can be deleted
        if (maxChoosableInteger >= desiredTotal) return true;

        // this line cannot be deleted
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;

        std::vector<bool> visited_int( maxChoosableInteger, false );
        std::unordered_map<int, bool> memo;

        return CanWinImp( desiredTotal, 0, 0, visited_int, memo );
    }
};
