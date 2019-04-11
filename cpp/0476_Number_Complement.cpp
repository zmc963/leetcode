class Solution
{
    double m_radius;
    double m_x_center;
    double m_y_center;

public:
    Solution(double radius, double x_center, double y_center) :
        m_radius(radius)
       ,m_x_center(x_center)
       ,m_y_center(y_center)
    {}

    vector<double> randPoint()
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());
        std::uniform_real_distribution<> dis(0, 1);

        double theta = 2 * M_PI * dis(gen);
        double len = sqrt(dis(gen)) * m_radius;
        return {m_x_center + len * std::cos(theta), m_y_center + len * std::sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
