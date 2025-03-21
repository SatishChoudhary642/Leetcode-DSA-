class Solution {
public:
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set <string> available (supplies.begin(), supplies.end());
        unordered_map <string, vector<string>> recipe_ingredients;
        unordered_map <string, int> indegree;
        vector <string> result;

        for(int i=0; i<recipes.size(); i++){
            recipe_ingredients[recipes[i]]=ingredients[i];
        }
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (string& ing : ingredients[i]) {
                recipe_ingredients[ing].push_back(recipes[i]);
            }
        }
        queue <string> q(supplies.begin(), supplies.end());
        while(!q.empty()){
            string item = q.front();
            q.pop();
            for (string& recipe : recipe_ingredients[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    result.push_back(recipe);
                    q.push(recipe);
                }
            }
        }
        return result;
    }
};