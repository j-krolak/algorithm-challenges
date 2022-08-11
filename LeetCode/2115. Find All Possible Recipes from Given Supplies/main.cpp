class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       
        
        map< string, vector<string>> G;
        map< string, int> S;
        map< string, int> Result;
        
        for(int i = 0; i < recipes.size(); i++)
        {       
            Result[recipes[i]];
            for(int j = 0; j < ingredients[i].size(); j++)
            {
                G[ingredients[i][j]].push_back(recipes[i]);
                if(S.find(recipes[i]) == S.end())
                    S[recipes[i]] = 0;
                S[recipes[i]]++;
            }
        }
        
        stack<string> next;
        
        for(int i = 0; i < supplies.size(); i++)
        {
            next.push(supplies[i]);
            S[supplies[i]] = 0;
            Result[supplies[i]]=1;
        }
        
        while(!next.empty())
        {
            string sup = next.top();
            next.pop();
            
            for(int i = 0; i < G[sup].size(); i++)
            {
                if(Result.find(G[sup][i]) == Result.end())
                    continue;
                S[G[sup][i]]--;
                Result[G[sup][i]]++;
                if(S[G[sup][i]] == 0)
                    next.push(G[sup][i]);
                
            }
        }
        
        vector<string> ans;
        
        for(int i = 0; i < recipes.size(); i++)
        {
            if(Result[recipes[i]] == ingredients[i].size())
                ans.push_back(recipes[i]);
        }
        
        return ans;
    }
};
