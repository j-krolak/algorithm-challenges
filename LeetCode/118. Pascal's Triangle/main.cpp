class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
       init();
        
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j <= i; j++)
                tmp.push_back(pascal[i][j]);
            
            res.push_back(tmp);
            tmp.resize(0);
        }
        
        return res;
    }
private:
    int pascal[32][32]; 
    
    void init()
    {
        pascal[0][0] = 1;
        for(int i = 1; i < 32; i++)
        {
            for(int j = 1; j < i; j++)
            {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            
            pascal[i][0] =1;
            pascal[i][i] = 1;
        }
    }
};
