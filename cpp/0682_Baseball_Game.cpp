class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;

public:
    int calPoints(vector<string>& ops)
    {
        std::vector<int> points;
        int sum = 0;

        for( auto&& s : ops )
        {
            if( "+" == s )
            {
                auto score = 0;
                if( points.size() >= 2 ) score = points.back() + *(points.rbegin()+1);
                else if( points.size() >= 1 ) score = points.back();

                sum += score;
                points.push_back( score );
            }
            else if( "D" == s )
            {
                auto score = 0;
                if( !points.empty() ) score = 2 * points.back();

                sum += score;
                points.push_back( score );
            }
            else if( "C" == s )
            {
                if( !points.empty() )
                {
                    sum -= points.back();
                    points.pop_back();
                }
            }
            else
            {
                points.push_back( std::stoi(s) );
                sum += points.back();
            }
        }

        return sum;
    }
};
