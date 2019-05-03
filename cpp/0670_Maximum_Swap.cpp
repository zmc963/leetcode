class Solution
{
    using SIZE_TYPE = std::string::size_type;
public:
    int maximumSwap(int num)
    {
        if( 10 > num ) return num;

        auto num_str = std::to_string(num);

        const auto SIZE = num_str.size();
        std::vector<std::pair<int, SIZE_TYPE>> right_max(SIZE);
        right_max.back() = { num_str.back(), SIZE-1 };

        for( SIZE_TYPE i=SIZE-2; i<SIZE; --i )
        {
            // note no '==' here
            if( right_max.at(i+1).first < num_str.at(i) )
            {
                right_max.at(i).first = num_str.at(i);
                right_max.at(i).second = i;
            }
            else
            {
                right_max.at(i).first = right_max.at(i+1).first;
                right_max.at(i).second = right_max.at(i+1).second;
            }
        }

        for( SIZE_TYPE i=0; i<SIZE-1; ++i )
        {
            auto n = num_str.at(i);

            if( right_max.at(i+1).first>n )
            {
                std::swap( num_str.at(i), num_str.at(right_max.at(i+1).second) );

                return std::stoi(num_str);
            }
        }

        return num;
    }
};
