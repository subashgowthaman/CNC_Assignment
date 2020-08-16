

using namespace std;

class Range
{
    private:

    	map<int, pair<double,double>> RangeMapper;
    
    public:
        
        Range()
        {
         
	        RangeMapper[0] = make_pair(std::numeric_limits<double>::min(), 35.0f);
			RangeMapper[1] = make_pair(std::numeric_limits<double>::min(), 0.05f);
			RangeMapper[2] = make_pair(std::numeric_limits<double>::min(), 360.0f);

        }
        pair<double, double> FetchLimits(int id){ return RangeMapper[id];}      
}