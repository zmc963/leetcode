class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    // impossible DP
    // key, (prev key, current price)
//     using DP_TYPE = std::map<std::vector<int>, std::pair<std::vector<int>, int>>;

//     void Compute(
//         const std::vector<int>& offer,
//         int offer_price,
//         const std::vector<int>& needs,
//         SIZE_TYPE idx,
//         DP_TYPE& dp,
//         std::vector<int>& currKey ) const
//     {
//         assert( offer.size()==needs.size() && !offer.empty() && idx<needs.size() && currKey.size()<=needs.size() );

//         if( needs.empty() ) return;

//         const auto MAX_VAL = needs.at(idx);
//         if( idx == needs.size()-1 )
//         {
//             for( SIZE_TYPE i=offer.at(idx); i<=MAX_VAL; ++i )
//             {
//                 currKey.push_back(i);

//                 assert( offer.size() == currKey.size() );
//                 std::vector<int> new_key(offer.size());
//                 std::transform( currKey.begin(), currKey.end(), offer.begin(), new_key.begin(), std::minus<int>() );
//                 auto new_gain = dp[new_key].second + offer_price;

//                 // for( auto n : currKey ) std::cout << n << " "; std::cout << std::endl;
//                 // for( auto n : new_key ) std::cout << n << " "; std::cout << std::endl;
//                 // std::cout << dp[currKey].second << " " << new_gain << std::endl << std::endl;

//                 auto& target = dp[currKey];
//                 if( target.first.empty() || target.second < new_gain )
//                 {
//                     target.second = new_gain;
//                     target.first = new_key;
//                 }

//                 currKey.pop_back();
//             }

//             return;
//         }

//         for( SIZE_TYPE i=offer.at(idx); i<=MAX_VAL; ++i )
//         {
//             currKey.push_back( i );
//             Compute( offer, offer_price, needs, idx+1, dp, currKey );
//             currKey.pop_back();
//         }
//     }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
//         if( price.size() != needs.size() ) return -1;

//         DP_TYPE dp;

//         for( auto&& offer : special )
//         {
//             if( offer.size() != price.size()+1 ) return -1;

//             std::vector<int> curr_key;
//             auto offer_price = offer.back();
//             offer.pop_back();

//             Compute( offer, offer_price, needs, 0, dp, curr_key );
//         }

//         auto remaining = needs;
//         while( !dp[remaining].first.empty() )
//         {
//             remaining = dp[remaining].first;
//         }

//         auto prices_w_offer = dp[needs].second;
//         assert( price.size() == remaining.size() );
//         std::transform( price.begin(), price.end(), remaining.begin(), remaining.begin(),
//             [&prices_w_offer] ( const auto& left, const auto& right )
//             {
//                 prices_w_offer += left * right;
//                 return right;
//             });

//         auto prices_wo_offer = 0;
//         assert( price.size() == needs.size() );
//         std::transform( price.begin(), price.end(), needs.begin(), needs.begin(),
//             [&prices_wo_offer] ( const auto& left, const auto& right )
//             {
//                 prices_wo_offer += left * right;
//                 return right;
//             });

//         // for( auto n : dp[needs].first ) std::cout << n << " "; std::cout << std::endl;
//         // for( auto n : remaining ) std::cout << n << " "; std::cout << std::endl;
//         // std::cout << dp[needs].second << " " << prices_w_offer << " " << prices_wo_offer << std::endl;

//         return std::min( prices_w_offer, prices_wo_offer );

        auto cost = 0;
        const auto SIZE = price.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            cost += price[i] * needs[i];
        }

        for( auto&& offer : special )
        {
            bool is_valid = true;

            for( SIZE_TYPE i=0; i<SIZE; ++i )
            {
                if( needs[i] < offer[i] ) is_valid = false;

                needs[i] -= offer[i];
            }

            if( is_valid )
            {
                cost = std::min( cost, shoppingOffers(price, special, needs) + offer.back());
            }

            for( SIZE_TYPE i=0; i<SIZE; ++i )
            {
                needs[i] += offer[i];
            }
        }

        return cost;
    }
};
