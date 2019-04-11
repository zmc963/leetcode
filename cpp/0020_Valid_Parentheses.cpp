class Solution {
public:
    bool isValid( const string& s )
    {
        if( s.empty() ) return true;

        std::unordered_map<std::string::value_type, std::string::value_type> close_mapping
        {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        std::stack<std::string::value_type> working_stack;

        for( auto c : s )
        {
            auto itr = close_mapping.find(c);
            if( close_mapping.end() != itr )
            {
                if( !working_stack.empty() && (itr->second==working_stack.top()) )
                {
                    working_stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                working_stack.push(c);
            }
        }

        return working_stack.empty();

//         std::stack<std::string::value_type> working_stack;

//         auto judge = []( std::string::value_type c, std::stack<std::string::value_type>& w_stack )
//         {
//             if( w_stack.empty() )
//             {
//                 return false;
//             }

//             auto top = w_stack.top();
//             if( c != top )
//             {
//                 return false;
//             }
//             w_stack.pop();

//             return true;
//         };

//         for( auto c : s )
//         {
//             if( '(' == c || '{' == c || '[' == c )
//             {
//                 working_stack.push(c);
//             }
//             else if( ')' == c )
//             {
//                 if( !judge( '(', working_stack ) )
//                 {
//                     return false;
//                 }
//             }
//             else if( ']' == c )
//             {
//                 if( !judge( '[', working_stack ) )
//                 {
//                     return false;
//                 }
//             }
//             else if( '}' == c )
//             {
//                 if( !judge( '{', working_stack ) )
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 assert(0);
//             }
//         }

//         return working_stack.empty();
    }
};
