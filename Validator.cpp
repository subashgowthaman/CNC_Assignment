


using namespace std;

bool isBetweenPassingRange(double value_in, pair<float,float> range)
{
    bool passStatus = false;

    if((value_in < range.first) || (value_in > ranage.second))
    {
        passStatus = false;
    }
    else 
    {
    	passStatus = true;
    }

    return passStatus;
}



