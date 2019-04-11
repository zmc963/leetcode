class Solution
{
    using SIZE_TYPE = std::string::size_type;

    const std::string DICT = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int ENCODED_LEN = 6;

    std::unordered_map<std::string, std::string> m_short_to_long_hash;
    std::unordered_map<std::string, std::string> m_long_to_short_hash;

    std::random_device m_rd;
    std::default_random_engine m_gen;
    std::uniform_int_distribution<int> m_dis;

public:
    Solution() :
         m_gen(std::default_random_engine(m_rd()))
        ,m_dis(0, DICT.size()-1)
    {
        assert( 62 == DICT.size() );
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if( m_long_to_short_hash.count(longUrl) ) return "http://tinyurl.com/" + m_long_to_short_hash[longUrl];

        std::string encoded;
        for( auto i=0; i<ENCODED_LEN; ++i ) encoded += DICT.at(m_dis(m_gen));
        SIZE_TYPE idx = 0;
        while( m_short_to_long_hash.count(encoded) )
        {
            encoded.at( (idx++) % ENCODED_LEN ) = DICT.at(m_dis(m_gen));
        }

        m_short_to_long_hash.emplace( encoded, longUrl );
        m_long_to_short_hash.emplace( longUrl, encoded );

        return "http://tinyurl.com/" + encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        auto encoded = shortUrl.substr( shortUrl.find_last_of("/") + 1 );

        if( m_short_to_long_hash.count(encoded) ) return m_short_to_long_hash[encoded];

        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
