//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>meetings(n);
       for(int i=0;i<n;i++)
       {
           meetings[i]={end[i],start[i]};
       }
       sort(meetings.begin(),meetings.end());
       
       int cnt=0,lastEndTime=-1;
       
       for(int i=0;i<n;i++)
       {
           if(meetings[i].second > lastEndTime)
           {
               cnt++;
               lastEndTime=meetings[i].first;
           }
       }
       return cnt;
        
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends