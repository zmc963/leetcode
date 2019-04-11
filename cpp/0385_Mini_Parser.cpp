/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
    using SIZE_TYPE = std::string::size_type;

    NestedInteger DeserializeImp( const std::string& s, SIZE_TYPE& start )
    {
        NestedInteger curr;
        assert( !curr.isInteger() && curr.getList().empty() );
        const auto SIZE = s.size();

        for( ; start<SIZE; ++start )
        {
            auto c = s.at(start);
            if( '-'==c || std::isdigit(c) )
            {
                auto end = start+1;
                while( end<SIZE && std::isdigit(s.at(end)) ) ++end;

                auto num = std::stoi( s.substr(start, end+1-start) );
                start = end - 1;

                // simply an add is fine...it will destroy the original int
                curr.add( num );
            }
            else if( '[' == c )
            {
                curr.add( DeserializeImp(s, ++start) );
            }
            else if( ']' == c )
            {
                break;
            }
        }

        return curr;
    }

public:
    NestedInteger deserialize(string s)
    {
        SIZE_TYPE start = 0;
        auto res = DeserializeImp( s, start );
        assert( !res.isInteger() && 1==res.getList().size() );

        return res.getList().front();
    }
};
