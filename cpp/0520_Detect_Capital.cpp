class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool detectCapitalUse(string word)
    {
        auto is_my_upper = [](auto c) { return 'A'<=c && c<='Z'; };
        auto upper_cnt = count_if( word.begin(), word.end(), is_my_upper );

        return (upper_cnt==word.size()) || (!upper_cnt) || (upper_cnt==1 && is_my_upper(word.front()));
    }
};
