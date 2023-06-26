#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <chrono>

void convertToUppercase(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input) {
        std::cout << "Error opening input file: " << inputFile << std::endl;
        return;
    }

    if (!output) {
        std::cout << "Error creating output file: " << outputFile << std::endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        char uppercaseCh = std::toupper(ch);
        output.put(uppercaseCh);
    }

    input.close();
    output.close();

    std::cout << "File conversion complete: " << inputFile << " -> " << outputFile << std::endl;
}

int main() {
    std::vector<std::pair<std::string, std::string>> filePairs = {
         {"file 200MB.txt", "output200.txt"},
        {"file 400MB.txt", "output400.txt"},
        {"file 600MB.txt", "output600.txt"},
        {"file 800MB.txt", "output800.txt"},
        {"file 1000MB.txt", "output1000.txt"},
        // Add more file pairs here if needed
    };

    for (const auto& pair : filePairs) {
        const std::string& inputFile = pair.first;
        const std::string& outputFile = pair.second;

        auto startTime = std::chrono::high_resolution_clock::now();

        convertToUppercase(inputFile, outputFile);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        std::cout << "Execution time for " << inputFile << ": " << duration.count() << " milliseconds" << std::endl;
    }

    return 0;
}
