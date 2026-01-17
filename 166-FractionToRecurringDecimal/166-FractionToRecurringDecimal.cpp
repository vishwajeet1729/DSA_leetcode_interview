// Last updated: 1/17/2026, 12:33:44 PM
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        // If the numerator is 0, the result is simply "0".
        if (numerator == 0) {
            return "0";
        }
        
        // This string will be used to build our final answer.
        std::string result = "";
        
        // Determine the sign of the result. Using XOR is a neat trick:
        // (pos ^ pos) = false, (neg ^ neg) = false, (pos ^ neg) = true.
        if ((numerator > 0) ^ (denominator > 0)) {
            result += "-";
        }
        
        // Use long long for numerator and denominator to handle potential overflow,
        // especially when dealing with the absolute value of INT_MIN.
        long long num = std::abs((long long)numerator);
        long long den = std::abs((long long)denominator);
        
        // Append the integer part of the division to the result.
        result += std::to_string(num / den);
        
        // Calculate the initial remainder.
        long long remainder = num % den;
        
        // If the remainder is 0, there is no fractional part, so we are done.
        if (remainder == 0) {
            return result;
        }
        
        // If there is a remainder, we append the decimal point.
        result += ".";
        
        // This map will store the remainder and the position in the string where it first occurred.
        std::unordered_map<long long, int> remainder_map;

        // Loop to calculate the fractional part as long as there's a remainder.
        while (remainder != 0) {
            // Check if we have seen this remainder before.
            if (remainder_map.count(remainder)) {
                // If we have, a cycle is detected. Insert the opening parenthesis
                // at the position where this remainder first appeared.
                result.insert(remainder_map[remainder], "(");
                // Append the closing parenthesis to the end.
                result += ")";
                // Break the loop as we are done.
                break;
            }
            
            // If this is a new remainder, store it and its current position in the result string.
            remainder_map[remainder] = result.length();
            
            // Multiply the remainder by 10 to continue the long division process.
            remainder *= 10;
            
            // Append the next digit of the fractional part to the result.
            result += std::to_string(remainder / den);
            
            // Update the remainder for the next iteration.
            remainder %= den;
        }
        
        // Return the final constructed string.
        return result;
    }
};