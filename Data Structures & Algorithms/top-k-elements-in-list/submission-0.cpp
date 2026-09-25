class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > count ;
        for(auto x : nums)
        {
            count[x]++;
        }

        priority_queue< pair<int,int> , vector< pair<int , int> > , greater <pair<int,int> >> pq ; 

        for(auto a : count)
        {
            pq.push(make_pair(a.second , a.first));
            if(pq.size() > k)
                pq.pop();

        }

        vector<int> ans ;
        while(!pq.empty())
        {
            pair<int , int > temp = pq.top();
            pq.pop();

            ans.push_back(temp.second);
        }
           
        return ans ;
    }
};
