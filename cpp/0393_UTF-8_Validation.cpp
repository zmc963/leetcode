class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool validUtf8(vector<int>& data)
    {
        auto IsValidByte = []( int b )
        {
            return b>=128 && b<=191;
        };

        const auto SIZE = data.size();

        for( SIZE_TYPE i=0; i<SIZE; )
        {
            auto first_byte = data.at(i);
            if( first_byte>=0 && first_byte<=127 )
            {
                ++i;
            }
            else if( first_byte>=192 && first_byte<=223 && i+1<SIZE )
            {
                if( !IsValidByte(data.at(i+1)) ) return false;
                i += 2;
            }
            else if( first_byte>=224 && first_byte<=239 && i+2<SIZE )
            {
                if( !IsValidByte(data.at(i+1)) || !IsValidByte(data.at(i+2)) ) return false;

                i += 3;
            }
            else if( first_byte>=240 && first_byte<=247 && i+3<SIZE )
            {
                if( !IsValidByte(data.at(i+1)) || !IsValidByte(data.at(i+2)) || !IsValidByte(data.at(i+3)) ) return false;

                i += 4;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
