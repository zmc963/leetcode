class Solution {
public:
    vector<vector<int>> threeSum( vector<int>& nums )
    {
//         std::sort( nums.begin(), nums.end() );

//         std::vector<std::vector<int>> ans;

//         const auto SIZE = nums.size();
//         for( std::vector<int>::size_type i=0; i<SIZE; )
//         {
//             auto a = nums.at(i);
//             auto target = -a;

//             std::unordered_set<int> hash; // map due to prohibited same elements
//             for( std::vector<int>::size_type j=i+1; j<SIZE; )
//             {
//                 auto b = nums.at(j);
//                 auto c = target - b;

//                 auto itr = hash.find(c);
//                 if( hash.end() != itr )
//                 {
//                     ans.push_back( {a, b, c} );

//                     while( (SIZE>j) && (b==nums.at(j)) ) ++j;
//                 }
//                 else ++j;

//                 hash.insert( b );
//             }

//             while( (SIZE>i) && (a==nums.at(i)) ) ++i;
//         }

        std::sort( nums.begin(), nums.end() );

        std::vector<std::vector<int>> ans;
        const auto SIZE = nums.size();
        for( std::vector<int>::size_type i=0; i<SIZE; )
        {
            auto a = nums.at(i);
            auto target = -a;

            auto lo = i+1;
            auto hi = SIZE-1;

            while( lo < hi )
            {
                auto b = nums.at(lo);
                auto c = nums.at(hi);
                auto sum = b+c;

                if( target == sum )
                {
                    ans.push_back( {a, b, c} );

                    while( lo < hi && nums.at(lo) == b) lo++;
                    while( lo < hi && nums.at(hi) == c) hi--;
                }
                else if( target < sum ) --hi;
                else ++lo;
            }

            // jump to next value different from a
            while( (SIZE>i) && (a==nums.at(i)) ) ++i;
        }

        return ans;
    }
};
