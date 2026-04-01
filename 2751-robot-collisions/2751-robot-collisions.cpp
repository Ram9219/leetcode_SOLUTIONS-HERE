class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        //  index ko store karte jao 
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        
        //  position by sort karte jao 
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        
        stack<int> st; // store indices of 'R'
        
        for(int i : idx){
            if(directions[i] == 'R'){
                st.push(i);
            } else {
                // 'L'
                while(!st.empty() && healths[i] > 0){
                    int j = st.top();
                    
                    if(healths[j] > healths[i]){
                        healths[j]--;
                        healths[i] = 0;
                    }
                    else if(healths[j] < healths[i]){
                        healths[i]--;
                        healths[j] = 0;
                        st.pop();
                    }
                    else{
                        healths[i] = 0;
                        healths[j] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // collect survivors
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};