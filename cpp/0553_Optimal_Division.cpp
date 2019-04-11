class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    struct LocalRes
    {
        double m_max = std::numeric_limits<decltype(m_max)>::min();
        double m_min = std::numeric_limits<decltype(m_min)>::max();

        std::string m_max_str;
        std::string m_min_str;

        LocalRes() {}

        LocalRes( double maxVal, double minVal, std::string maxStr, std::string minStr ) :
             m_max(maxVal)
            ,m_min(minVal)
            ,m_max_str(std::move(maxStr))
            ,m_min_str(std::move(minStr))
        {}
    };

    LocalRes OptimalDivisionImp(
        const std::vector<int>& nums,
        SIZE_TYPE left,
        SIZE_TYPE right ) const
    {
        if( left>right || right>=nums.size() )
        {
            return {};
        }
        else if( left == right )
        {
            double val = static_cast<double>(nums.at(left));
            return {val, val, std::to_string(nums.at(left)), std::to_string(nums.at(left))};
        }

        LocalRes local_res;
        for( SIZE_TYPE i=left; i<right; ++i )
        {
            auto left_res = OptimalDivisionImp( nums, left, i );
            auto right_res = OptimalDivisionImp( nums, i+1, right );

            auto local_max_val = left_res.m_max / right_res.m_min;
            auto local_min_val = left_res.m_min / right_res.m_max;

            if( local_max_val > local_res.m_max )
            {
                local_res.m_max = local_max_val;
                auto right_str = i+1==right ? right_res.m_min_str : "(" + right_res.m_min_str + ")";

                local_res.m_max_str = left_res.m_max_str + "/" + right_str;
            }

            if( local_min_val < local_res.m_min )
            {
                local_res.m_min = local_min_val;
                auto right_str = i+1==right ? right_res.m_max_str : "(" + right_res.m_max_str + ")";

                local_res.m_min_str = left_res.m_min_str + "/" + right_str;
            }
        }

        return local_res;
    }

public:
    string optimalDivision( std::vector<int>& nums )
    {
        if( nums.empty() ) return {};

        // return OptimalDivisionImp( nums, 0, nums.size()-1 ).m_max_str;

        // bottom-up DP
        const auto SIZE = nums.size();
        std::vector<std::vector<LocalRes>> dp( SIZE, std::vector<LocalRes>(SIZE) );

        for( SIZE_TYPE right=0; right<SIZE; ++right )
        {
            double val = static_cast<double>(nums.at(right));
            dp.at(right).at(right) =
                {val, val, std::to_string(nums.at(right)), std::to_string(nums.at(right))};

            for( SIZE_TYPE left=right-1; left<SIZE; --left )
            {
                LocalRes local_res;
                for( SIZE_TYPE i=left; i<right; ++i )
                {
                    auto& left_res = dp.at(left).at(i);
                    auto& right_res = dp.at(i+1).at(right);

                    auto local_max_val = left_res.m_max / right_res.m_min;
                    auto local_min_val = left_res.m_min / right_res.m_max;

                    if( local_max_val > local_res.m_max )
                    {
                        local_res.m_max = local_max_val;
                        auto right_str = i+1==right ? right_res.m_min_str : "(" + right_res.m_min_str + ")";

                        local_res.m_max_str = left_res.m_max_str + "/" + right_str;
                    }

                    if( local_min_val < local_res.m_min )
                    {
                        local_res.m_min = local_min_val;
                        auto right_str = i+1==right ? right_res.m_max_str : "(" + right_res.m_max_str + ")";

                        local_res.m_min_str = left_res.m_min_str + "/" + right_str;
                    }
                }

                dp.at(left).at(right) = std::move(local_res);
            }
        }

        return dp.front().back().m_max_str;
    }
};




