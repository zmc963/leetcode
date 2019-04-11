class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};

        const auto MAG_SIZE = magazine.size();
        for( SIZE_TYPE i=0; i<MAG_SIZE; ++i )
        {
            ++hash[std::tolower(magazine.at(i))-'a'];
        }

        const auto RANSOM_SIZE = ransomNote.size();
        for( SIZE_TYPE i=0; i<RANSOM_SIZE; ++i )
        {
            if( --hash[std::tolower(ransomNote.at(i))-'a'] < 0 ) return false;
        }

        return true;
    }
};
