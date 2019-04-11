class Solution {
public:
    int longestValidParentheses(string s)
    {
        using IDX_TYPE = std::string::size_type;
        std::stack<std::pair<std::string::value_type, IDX_TYPE>> w_stack;

        const auto SIZE = s.size();
        IDX_TYPE max_len = 0;
        IDX_TYPE left = 0;
        for( IDX_TYPE i=0; i<SIZE; ++i )
        {
            auto c = s.at(i);

            if( ')' == c )
            {
                if( !w_stack.empty() && '(' == w_stack.top().first )
                {
                    max_len = std::max( max_len, i-w_stack.top().second+1 );
                    w_stack.pop();

                    if( w_stack.empty() )
                    {
                        std::cout << i << " " << left <<std::endl;
                        max_len = std::max( max_len, i-left+1 );
                    }
                    else
                    {
                        max_len = std::max( max_len, i-w_stack.top().second );
                    }
                }
                else
                {
                    assert( w_stack.empty() );
                    left = i+1;
                    // decltype(w_stack) t;
                    // w_stack.swap( t );
                }
            }
            else
            {
                // pair_cnt = 0;
                w_stack.push( {c, i} );
            }
        }

        return max_len;
    }

  // int longestValidParentheses(string s) {
  //       int res = 0, start = 0;
  //       stack<int> m;
  //       for (int i = 0; i < s.size(); ++i) {
  //           if (s[i] == '(') m.push(i);
  //           else if (s[i] == ')') {
  //               if (m.empty()) start = i + 1;
  //               else {
  //                   m.pop();
  //                   if( m.empty() )
  //                   {
  //                       std::cout << start << " " << i << std::endl;
  //                       res = max(res, i - start + 1) ;
  //                   }
  //                   else
  //                   {
  //                       res = max(res, i - m.top() );
  //                   }
  //               }
  //           }
  //       }
  //       return res;
  //   }
};
