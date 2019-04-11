class Solution
{
public:
    int trap(vector<int>& height)
    {
        using IDX_TYPE = std::vector<int>::size_type;
        const auto SIZE = height.size();

        stack<IDX_TYPE> st;
        int ans = 0;
        for( IDX_TYPE i=0; i<SIZE; ++i )
        {
            auto curr_height = height.at(i);

            while (!st.empty() && curr_height > height[st.top()])
            {
                auto top = st.top();
                st.pop();

                if( st.empty() )
                {
                    break;
                }

                auto distance = i - st.top() - 1;
                auto bounded_height = std::min( curr_height, height[st.top()] ) - height[top];
                ans += distance * bounded_height;
            }

            st.push(i);
        }

        return ans;
    }
};
