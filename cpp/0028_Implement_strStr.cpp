class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if( needle.empty()  )
        {
            return 0;
        }

        const auto H_SIZE = haystack.size();
        const auto N_SIZE = needle.size();
        if( H_SIZE < N_SIZE )
        {
            return -1;
        }

        using IDX_TYPE = std::string::size_type;
        for( IDX_TYPE i=0; i<=H_SIZE-N_SIZE; ++i )
        {
            IDX_TYPE t_j = 0;
            while( (t_j<N_SIZE) && (haystack.at(t_j+i) == needle.at(t_j)) )
            {
                ++t_j;
            }

            if( N_SIZE == t_j )
            {
                return i;
            }




//             if( haystack.at(i) == needle.front() )
//             {
//                 if( H_SIZE-i < N_SIZE )
//                 {
//                     return -1;
//                 }

//                 std::string::size_type j = 1;
//                 for( ; j<N_SIZE; ++j )
//                 {
//                     if( haystack.at(i+j) != needle.at(j) )
//                     {
//                         break;
//                     }
//                 }

//                 if( j == N_SIZE )
//                 {
//                     return i;
//                 }
//             }
        }

        return -1;
    }
};
