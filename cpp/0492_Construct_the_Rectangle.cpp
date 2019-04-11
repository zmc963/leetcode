class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int min_len = std::sqrt( area );

        while( 0 != area%min_len )
        {
            --min_len;
        }

        return {area/min_len, min_len};
    }
};
