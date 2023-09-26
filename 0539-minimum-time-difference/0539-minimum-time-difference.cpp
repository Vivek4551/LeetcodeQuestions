class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(int i= 0; i<timePoints.size(); i++)
        {
            string curr = timePoints[i];

            int hours = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));

            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        sort(minutes.begin(),minutes.end());

        int mini = INT_MAX;
        for(int i=0; i<minutes.size()-1;i++)
        {
            int diff = minutes[i+1] - minutes[i];
            if( diff < mini)
            {
                mini = min(mini,diff);
            }
        }

        int lastDiff1 = (minutes[0]+1440) - minutes[minutes.size()-1];
        int lastDiff2 = minutes[minutes.size()-1] - minutes[0];
        int lastDiff = min(lastDiff1 , lastDiff2);
        mini = min(mini,lastDiff);

        return mini;
    }
};