class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int strStr(string haystack, string needle)
    {
        if( needle.empty() ) return 0;

        const auto CHARACER_SET_SIZE = 256; // ASCII code
        const auto N_SIZE = needle.size();
        std::vector<std::vector<SIZE_TYPE>> dfa( CHARACER_SET_SIZE, std::vector<SIZE_TYPE>( N_SIZE, 0 ) );

        dfa.at(needle.at(0)).at(0) = 1;
        for( SIZE_TYPE state=1, prev_state=0; state<N_SIZE; ++state )
        {
            for( SIZE_TYPE i=0; i<CHARACER_SET_SIZE; ++i )
            {
                dfa.at(i).at(state) = dfa.at(i).at(prev_state);
            }

            auto next_c = needle.at(state);
            dfa.at(next_c).at(state) = state+1;

            prev_state = dfa.at(next_c).at(prev_state);
        }

        const auto H_SIZE = haystack.size();
        for( SIZE_TYPE i=0, state=0; i<H_SIZE; ++i )
        {
            auto next_c = haystack.at(i);
            state = dfa.at(next_c).at(state);

            if( N_SIZE == state ) return i+1-N_SIZE;
        }

        return -1;

//         if( needle.empty()  )
//         {
//             return 0;
//         }

//         const auto H_SIZE = haystack.size();
//         const auto N_SIZE = needle.size();
//         if( H_SIZE < N_SIZE )
//         {
//             return -1;
//         }

//         using IDX_TYPE = std::string::size_type;
//         for( IDX_TYPE i=0; i<=H_SIZE-N_SIZE; ++i )
//         {
//             IDX_TYPE t_j = 0;
//             while( (t_j<N_SIZE) && (haystack.at(t_j+i) == needle.at(t_j)) )
//             {
//                 ++t_j;
//             }

//             if( N_SIZE == t_j )
//             {
//                 return i;
//             }
//         }

//         return -1;
    }
};
