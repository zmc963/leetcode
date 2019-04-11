class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        std::unordered_map<int, int> half_sum;

        for( auto a : A )
        {
            for( auto b : B )
            {
                ++half_sum[a+b];
            }
        }

        int count = 0;
        for( auto c : C )
        {
            for( auto d : D )
            {
                auto target = 0 - c - d;
                if( half_sum.count(target) ) count += half_sum.at(target);
            }
        }

        return count;
    }
};
