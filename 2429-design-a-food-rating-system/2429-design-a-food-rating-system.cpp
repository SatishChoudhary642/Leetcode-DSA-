struct cmp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};
class FoodRatings {
public:
    unordered_map<string, pair<int, string>> f;
    unordered_map<string, set<pair<int, string>, cmp>> c;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            f[foods[i]] = {ratings[i], cuisines[i]};
            c[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        c[f[food].second].erase({f[food].first, food});
        f[food].first = newRating;
        c[f[food].second].insert({newRating, food});
    }

    string highestRated(string cuisine) { 
        return c[cuisine].begin()->second; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */