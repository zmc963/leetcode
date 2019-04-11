class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        std::vector<std::string> ans;

        // sort first value
        std::map<int, std::string> mapping{ {3, "Fizz"}, {5, "Buzz"} };

        for( auto i=1; i<=n; ++i )
        {
            std::string res;
            for( auto& m : mapping )
            {
                if( 0 == i%m.first )
                {
                    res += m.second;
                }
            }

            ans.push_back( res.empty() ? std::to_string(i) : res );

            // if( 0 == i%15 )
            // {
            //     ans.push_back( "FizzBuzz" );
            // }
            // else if( 0 == i%3 )
            // {
            //     ans.push_back( "Fizz" );
            // }
            // else if( 0 == i%5 )
            // {
            //     ans.push_back( "Buzz" );
            // }
            // else
            // {
            //     ans.push_back( std::to_string(i) );
            // }
        }

        return ans;
    }
};
