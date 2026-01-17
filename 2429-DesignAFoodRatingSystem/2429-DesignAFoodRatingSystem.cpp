// Last updated: 1/17/2026, 12:29:08 PM
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

class FoodRatings {
public:
    // A map to store the cuisine for each food for quick lookup.
    std::unordered_map<std::string, std::string> food_to_cuisine;
    
    // A map to store the current rating of each food.
    std::unordered_map<std::string, int> food_to_rating;
    
    // A map where each cuisine has a sorted set of its foods.
    // The set stores pairs of {-rating, food_name} to keep the highest-rated,
    // lexicographically smallest food at the beginning.
    std::map<std::string, std::set<std::pair<int, std::string>>> cuisine_to_foods;

    // Constructor to initialize the system.
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        // Loop through all the initial food items.
        for (int i = 0; i < foods.size(); ++i) {
            // Store the food's cuisine.
            food_to_cuisine[foods[i]] = cuisines[i];
            // Store the food's initial rating.
            food_to_rating[foods[i]] = ratings[i];
            // Insert the food into the corresponding cuisine's sorted set.
            // Note the negative rating to ensure descending order of ratings.
            cuisine_to_foods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    // Function to update the rating of a food item.
    void changeRating(std::string food, int newRating) {
        // Find the cuisine of the given food.
        std::string cuisine = food_to_cuisine[food];
        // Get the old rating of the food.
        int oldRating = food_to_rating[food];
        
        // Remove the old entry { -oldRating, food } from the cuisine's set.
        cuisine_to_foods[cuisine].erase({-oldRating, food});
        
        // Insert the new entry { -newRating, food } into the set.
        cuisine_to_foods[cuisine].insert({-newRating, food});
        
        // Update the food's rating in our rating map.
        food_to_rating[food] = newRating;
    }

    // Function to find the highest-rated food of a given cuisine.
    std::string highestRated(std::string cuisine) {
        // Get the sorted set for the given cuisine.
        auto& food_set = cuisine_to_foods[cuisine];
        // The first element in the set is the highest-rated due to our {-rating, name} trick.
        // The .second attribute of the pair is the food's name.
        return food_set.begin()->second;
    }
};