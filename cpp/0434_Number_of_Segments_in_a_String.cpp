class Solution
{
public:
    int countSegments(string s)
    {
        auto count = 0;
        std::istringstream is(s);
        std::string t;

        while( std::getline(is, t, ' ') )
        {
            if( !t.empty() ) ++count;
        }

        return count;
    }
};
