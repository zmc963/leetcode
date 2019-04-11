class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if( words.empty() || words.front().empty() )
        {
            return {};
        }

        const auto WORD_LENGTH = words.front().size();
        const auto WORDS_SIZE = words.size();
        const auto END = s.size() - WORDS_SIZE*WORD_LENGTH;
        if( s.size() <= END )
        {
            return {};
        }

        std::unordered_map<std::string, int> word_hash;
        for( auto w : words ) ++word_hash[w];
        std::vector<int> ans;

        for( std::string::size_type i=0; i<=END; ++i )
        {
            std::unordered_map<std::string, int> t_word_hash;
            int count = 0;
            for( auto j=i; count<WORDS_SIZE; ++count )
            {
                auto t = s.substr( j, WORD_LENGTH );
                if( word_hash.end() == word_hash.find(t) )
                {
                    break;
                }
                ++t_word_hash[t];
                if( t_word_hash[t] > word_hash[t] )
                {
                    break;
                }

                j += WORD_LENGTH;
            }

            if( WORDS_SIZE == count ) ans.push_back(i);
        }

        return ans;
    }
};
