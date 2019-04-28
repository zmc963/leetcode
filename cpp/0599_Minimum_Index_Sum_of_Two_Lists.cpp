class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;

public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        std::unordered_map<std::string, SIZE_TYPE> hash_1;
        const auto SIZE_1 = list1.size();
        for( SIZE_TYPE i=0; i<SIZE_1; ++i )
        {
            auto curr_restaurant = list1.at(i);
            if( !hash_1.count(curr_restaurant) ) hash_1.emplace( curr_restaurant, i ); // keep min i for curr_restaurant
        }

        std::vector<std::string> ans;

        const auto SIZE_2 = list2.size();
        auto min_idx_sum = std::numeric_limits<SIZE_TYPE>::max();
        for( SIZE_TYPE i=0; i<SIZE_2; ++i )
        {
            auto curr_restaurant = list2.at(i);
            if( hash_1.count(curr_restaurant) )
            {
                auto new_idx_sum = hash_1[curr_restaurant] + i;
                if( min_idx_sum > new_idx_sum )
                {
                    min_idx_sum = new_idx_sum;
                    ans.clear();
                    ans.push_back(curr_restaurant);
                }
                else if( min_idx_sum == new_idx_sum )
                {
                    ans.push_back(curr_restaurant);
                }
            }
        }

        return ans;
    }
};
