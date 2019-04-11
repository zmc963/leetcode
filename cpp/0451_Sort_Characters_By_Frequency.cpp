class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    string frequencySort(string s)
    {
        std::unordered_map<VALUE_TYPE, SIZE_TYPE> hash;
        for( auto c : s ) ++hash[c];

        // O(nlgn)
        std::sort( s.begin(), s.end(), [&hash]( const auto& left, const auto& right )
            {
                assert( hash.count(left) && hash.count(right) );
                auto& hash_left = hash.at(left);
                auto& hash_right = hash.at(right);

                return hash_left==hash_right ? left<right : hash.at(left)>hash.at(right);
            });

        return s;

        // counting sort: O(n) but O(n) memory
//         const auto SIZE = s.size();
//         std::vector<std::string> res(SIZE);
//         for( auto&& h : hash ) res.at(h.second-1) += std::string( h.second, h.first );  // note +=

//         std::string ans;
//         for( SIZE_TYPE i=SIZE-1; i<SIZE; --i ) ans += res.at(i);

//         return ans;
    }
};
