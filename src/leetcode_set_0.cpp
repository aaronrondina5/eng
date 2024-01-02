#include "leetcode_set_0.h"


// std
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <map>
#include <vector>

namespace arondina
{
namespace eng
{

int DestroySequentialTargets::first_approach(std::vector<int>&& nums, int space) const
{
    // keep track of the counts of the mods
    std::unordered_map<int, int> mod_counts;
    for(int i = 0; i < nums.size(); ++i)
    {
        ++mod_counts[nums[i] % space];
    }

    // determine the highest count
    auto max_pair_it = std::max_element(
        mod_counts.begin(), mod_counts.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        }
    );
    int highest_mod_count = max_pair_it->second;

    // determine all the viable mods that equal the highest count
    std::unordered_set<int> mod_check;
    for(auto it = mod_counts.begin(); it != mod_counts.end(); ++it)
    {
        if(it->second == highest_mod_count)
        {
            mod_check.insert(it->first);
        }
    }

    // O(nlogn)
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i)
    {
        int mod = nums[i] % space;
        if(mod_check.find(mod) != mod_check.end())
        {
            return nums[i];
        }
    }

    // should never get here
    return -1;
}


bool CourseSchedule::can_finish(int num_courses, const std::vector<std::vector<int>>& prerequisites) const
{
    /**
     * so need to build a graph here that tells us if we can finish.
     * The way we couldnt finish is if we have a cycle.
     * 
     * So if course 1 depends on finishing course 2 which depends on 3 which depends on 1 for example.
     * 
     * So we need to build up our graph, and then DFS for cycles.
     * 
     * We also need to figure out what is the "top" of the graph.
    */
    
    // build graph
    std::vector<std::vector<int>> adjacency_matrix(num_courses, std::vector<int>());
    for(const auto& prerequisite : prerequisites)
    {
        adjacency_matrix[prerequisite[1]].emplace_back(prerequisite[0]);
    }

    // loop through the top values of the graph and check for cycles
    std::vector<bool> visited(num_courses, false);
    std::vector<bool> in_path(num_courses, false);

    for(int course = 0; course < num_courses; ++course)
    {
        if(!visited[course] && cycle_exists(course, visited, in_path, adjacency_matrix))
        {
            return false;
        }
    }
    return true;
}

bool CourseSchedule::cycle_exists(int node
    , std::vector<bool>& visited
    , std::vector<bool>& in_path
    , const std::vector<std::vector<int>>& graph) const
{
    visited[node] = true;
    in_path[node] = true;

    for(const int& neighbor : graph[node])
    {
        if(in_path[neighbor])
        {
            return true;
        }
        if(!visited[neighbor] && cycle_exists(neighbor, visited, in_path, graph))
        {
            return true;
        }
    }

    in_path[node] = false;
    return false;
}

int LargestSubstringBetweenChars::execute(const std::string& input) const
{
    /**
     * could just keep track of the first index for a character &
     * update the max.
    */
    std::vector<int> char_last_indexes(26, -1);
    int res = -1;
    for(int i = 0; i < input.size(); ++i)
    {
        int char_index = input[i] - 'a';
        if(char_last_indexes[char_index] > -1)
        {
            res = std::max(res, i - char_last_indexes[char_index] - 1);
        }
        else
        {
            char_last_indexes[char_index] = i;
        }
    }
    return res;
}

std::vector<int> AsteroidCollision::determine_final_state(std::vector<int>& asteroids) const
{
    // stack problem - to keep the state of the asteroids 
    
    std::vector<int> stack_asteroids;
    stack_asteroids.reserve(asteroids.size());

    for(int& asteroid : asteroids)
    {
        if(!stack_asteroids.empty() && asteroid < 0)
        {
            bool should_keep = true;

            // there are asteroids to smash AND the asteroid is moving left
            while(!stack_asteroids.empty() && stack_asteroids.back() > 0)
            {
                // the last asteroid is moving to the right

                // should break
                int last = stack_asteroids.back();

                if(last + asteroid == 0)
                {
                    // both asteroids destroyed
                    stack_asteroids.pop_back();
                    should_keep = false;
                    break;
                }
                else if(last + asteroid < 0)
                {
                    // asteroid smashes last
                    stack_asteroids.pop_back();
                }
                else
                {
                    // asteroid is destroyed
                    should_keep = false;
                    break;
                }
            }

            if(should_keep)
            {
                stack_asteroids.push_back(asteroid);
            }
        }
        else
        {
            // there are no asteroids to smash
            // OR the current asteroid is moving right
            stack_asteroids.push_back(asteroid);
        }
    }

    return stack_asteroids;
}

int MinLengthSubArraySum::min_sub_array_len(int target, const std::vector<int>& nums) const
{
    // so move along the array, keep the total
    // if you breach the value, then increment left pointer

    int min_sub_len = INT_MAX;
    int l_window = 0;
    int curr_sum = 0;
    for(int r_window = 0; r_window < nums.size(); ++r_window)
    {
        curr_sum += nums[r_window];

        while(curr_sum >= target)
        {
            min_sub_len = std::min(min_sub_len, r_window - l_window + 1);
            curr_sum -= nums[l_window];
            ++l_window;
        }

    }

    return min_sub_len == INT_MAX ? 0 : min_sub_len;
}

int KokoEatingBananas::min_eating_speed(const std::vector<int>& piles, int hours_to_eat)
{
    /**
     * assume hours to eat >= length piles
     * 
     * max possible is the maximum bananas
     * 
     * Binary search between 1 (min) and max
     * 
     * O(piles.length * log(max_value))
    */

    auto maxIt = std::max_element(piles.begin(), piles.end());
    int hi = *maxIt;
    int lo = 1;

    while (lo <= hi)
    {
        // try the mid point rate
        int try_rate = lo + (hi - lo) / 2;

        if(takes_hours_to_eat(piles, try_rate) <= hours_to_eat)
        {
            // this is a valid rate
            // so lets try lower!
            hi = try_rate - 1;
        }
        else
        {
            // this isnt fast enough
            lo = try_rate + 1;
        }
    }

    return lo;
}

long long KokoEatingBananas::takes_hours_to_eat(const std::vector<int>& piles, int rate)
{
    long long hours_spent = 0;
    for(const int& p : piles)
    {
        hours_spent += (p / rate);
        if(p % rate != 0)
        {
            // left over
            hours_spent++;
        }
    }
    return hours_spent;   
}

LetterCombinationsInPhone::LetterCombinationsInPhone()
{
    init_chars();
}

void LetterCombinationsInPhone::init_chars()
{
    m_chars['1'] = "";
    m_chars['2'] = "abc";
    m_chars['3'] = "def";
    m_chars['4'] = "ghi";
    m_chars['5'] = "jkl";
    m_chars['6'] = "mno";
    m_chars['7'] = "pqrs";
    m_chars['8'] = "tuv";
    m_chars['9'] = "wxyz"; 
}

void LetterCombinationsInPhone::build_letter_combinations(std::vector<std::string>& result, const std::string& digits) const
{
    int n = digits.length();
    if(n == 0)
    {
        return;
    }

    std::string current;
    backtrack(result, 0, n, digits, current);
}

void LetterCombinationsInPhone::backtrack(std::vector<std::string>& result
    , int i
    , int n
    , const std::string& digits
    , std::string& current) const
{
    if(i == n)
    {
        result.emplace_back(current);
        return;
    }
    auto letters = m_chars.find(digits[i]);
    for(const char& c : letters->second)
    {
        current += c;
        backtrack(result, i + 1, n, digits, current);
        current.pop_back();
    }
}

} // eng
} // arondina