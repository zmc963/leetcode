class Solution
{
public:
    vector<int> exclusiveTime( int n, vector<string>& logs )
    {
        std::vector<int> ans(n);
        std::stack<int> st;
        int preTime = 0;

        for( auto&& l : logs )
        {
            auto first_pos = l.find_first_of(':');
            auto second_pos = l.find_last_of(':');
            if( std::string::npos==first_pos || std::string::npos==second_pos || second_pos==l.size()-1 ) continue;

            int func_id = std::stoi( l.substr(0, first_pos) );
            std::string info = l.substr(first_pos, second_pos);
            int time =  std::stoi( l.substr(second_pos+1) );

            if( func_id<0 || func_id>=n || time<0 ) continue;

            if( !st.empty() )
            {
                ans.at(st.top()) += time - preTime;
            }

            preTime = time;
            if( ":start:" == info )
            {
                st.push(func_id);
            }
            else if( ":end:" == info )
            {
                auto t = st.top();
                st.pop();

                ++ans.at(t);
                ++preTime;
            }
        }

        return ans;
    }
};
