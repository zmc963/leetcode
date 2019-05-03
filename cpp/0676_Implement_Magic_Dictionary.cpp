class MagicDictionary
{
    using SIZE_TYPE = std::string::size_type;

    std::unordered_map<int, std::vector<std::string>> m;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for( auto&& d : dict )
        {
            m[d.size()].push_back(d);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        if( !m.count(word.size()) ) return false;

        const auto SIZE = word.size();
        for( auto&& w : m[word.size()] )
        {
            assert( w.size() == SIZE );
            SIZE_TYPE cnt = 0;

            for( SIZE_TYPE i=0; i<SIZE && cnt<2; ++i )
            {
                if( w.at(i) != word.at(i) ) ++cnt;
            }

            if( 1 == cnt ) return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
