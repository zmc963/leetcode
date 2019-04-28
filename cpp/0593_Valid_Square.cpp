class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        std::unordered_map<int, SIZE_TYPE> dist;
        std::vector<std::vector<int>> points{ p1, p2, p3, p4 };

        for( SIZE_TYPE i=0; i<4; ++i )
        {
            for( SIZE_TYPE j=i+1; j<4; ++j )
            {
                auto distane = std::pow(points.at(i).at(0)-points.at(j).at(0), 2) + std::pow(points.at(i).at(1)-points.at(j).at(1), 2);
                ++dist[distane];

                if( 0==distane || dist.size()>2 ) return false;
            }
        }

        return dist.size()==2;
//         if( 2!=dist.size() ||
//             (!(dist.begin()->second==4 && (++dist.begin())->second==2) &&
//              !(dist.begin()->second==2 && (++dist.begin())->second==4)) ) return false;

//         auto dist_1 = dist.begin()->first;
//         auto dist_2 = (++dist.begin())->first;

//         return (dist_1*2==dist_2) || (dist_2*2==dist_1);
    }
};
