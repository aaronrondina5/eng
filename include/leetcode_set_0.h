#ifndef INCLUDED_ARONDINAENG_LEETCODE_SET_0
#define INCLUDED_ARONDINAENG_LEETCODE_SET_0


// std
#include <vector>
#include <string>
#include <unordered_map>

namespace arondina
{
namespace eng
{

/**
 * 1624. https://leetcode.com/problems/largest-substring-between-two-equal-characters/
*/
class LargestSubstringBetweenChars
{
public:
    int execute(const std::string& input) const;
};

/**
 * 875. https://leetcode.com/problems/koko-eating-bananas/
*/
class KokoEatingBananas
{
public:
    int min_eating_speed(const std::vector<int>& piles, int hours_to_eat);
private:
    long long takes_hours_to_eat(const std::vector<int>& piles, int rate);
};

/**
 * 735. https://leetcode.com/problems/asteroid-collision/
*/
class AsteroidCollision
{
public:
    std::vector<int> determine_final_state(std::vector<int>& asteroids) const;
};

/**
 * 209. https://leetcode.com/problems/minimum-size-subarray-sum/
*/
class MinLengthSubArraySum
{
public:
    int min_sub_array_len(int target, const std::vector<int>& nums) const;
};

/**
 * 17. https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class LetterCombinationsInPhone
{
public:
    LetterCombinationsInPhone();
    void build_letter_combinations(std::vector<std::string>& result, const std::string& digits) const;

private:
    std::unordered_map<char, std::string> m_chars;

    void init_chars();
    void backtrack(std::vector<std::string>& result
    , int i
    , int n
    , const std::string& digits
    , std::string& current) const;
};


} // eng
} // arondina

#endif
