#include <iostream>
#include <string>
#include <vector>

int main() {
    // Input string
    std::string input = "Hello, World! (123) -456\t789";

    // Set of delimiters
    std::string delimiters = " .,;()!\"-_1234567890\t\n\r";

    // Vector to store tokens
    std::vector<std::string> tokens;

    // Find the position of the first non-delimiter
    size_t start_pos = input.find_first_not_of(delimiters);

    // Tokenize the string using the specified delimiters
    while (start_pos != std::string::npos) {
        // Find the position of the next delimiter
        size_t end_pos = input.find_first_of(delimiters, start_pos);

        // Extract the token
        std::string token = input.substr(start_pos, end_pos - start_pos);

        // Add the token to the vector
        tokens.push_back(token);

        // Find the position of the next non-delimiter
        start_pos = input.find_first_not_of(delimiters, end_pos);
    }

    // Display the tokens
    std::cout << "Tokens:" << std::endl;
    for (const auto& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}