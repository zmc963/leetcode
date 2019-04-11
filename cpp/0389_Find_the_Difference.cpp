class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char res = 0;
        for( auto c : s ) res ^= c;
        for( auto c : t ) res ^= c;

        return res;
    }
};
