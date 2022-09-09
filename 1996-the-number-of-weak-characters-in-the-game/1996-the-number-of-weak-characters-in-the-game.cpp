class Solution {
private:
    bool static sortByAttack(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, vector<vector<int>>, greater<int>> m;
        
        sort(properties.begin(), properties.end(), sortByAttack);
        
        int count = 0;
        int n = properties.size();
        int maxDefense = properties[0][1];
        
        for(int i = 1; i < n; i++) {           
            if(properties[i][1] < maxDefense) {
                count++;
            }
            
            if(properties[i][1] > maxDefense) {
                maxDefense = properties[i][1];
            }
        }
        
        return count;
    }
};