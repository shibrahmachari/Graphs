  static  bool iscompare(pair<int, int>a, pair<int, int>b){
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        else{
            return a.first<b.first;
        }
    }
    int countbfs(int x){
        queue<pair<int, int>>q;
      set<int>visited;
        q.push({x,0});
        int dist;
        //visited.insert(x);
        while(!q.empty()){
            pair<int, int> t=q.front();
            q.pop();
            if(t.first==1){
                dist=t.second;
                break;
            }
            if(t.first%2==0){
                q.push({t.first/2,t.second+1});
                //visited.insert(t.first/2);
            }
            if(t.first%2!=0){
                q.push({t.first*3+1,t.second+1});
                //visited.insert(t.first*3+1);
            }
        }
        return dist;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>>ans;
        for(int i=lo;i<=hi;i++){
            int cnt= countbfs(i);
            ans.push_back({cnt,i});
        }
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
