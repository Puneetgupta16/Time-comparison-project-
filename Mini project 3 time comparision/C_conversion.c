#include <stdio.h>
#include <ctype.h>
#include <time.h>

void convertToUppercase(const char* inputFile, const char* outputFile) {
    clock_t start_time = clock();

    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    if (input == NULL) {
        printf("Error opening input file: %s\n", inputFile);
        return;
    }

    if (output == NULL) {
        printf("Error creating output file: %s\n", outputFile);
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        int uppercaseCh = toupper(ch);
        fputc(uppercaseCh, output);
    }

    fclose(input);
    fclose(output);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("File conversion complete: %s -> %s\n", inputFile, outputFile);
    printf("Execution time for %s: %.3f seconds\n", inputFile, execution_time);
}

int main() {
    const char* filePairs[][2] = {
         {"file 200MB.txt", "output200.txt"},
        {"file 400MB.txt", "output400.txt"},
        {"file 600MB.txt", "output600.txt"},
        {"file 800MB.txt", "output800.txt"},
        {"file 1000MB.txt", "output1000.txt"},
        // Add more file pairs here if needed
    };
    int numPairs = sizeof(filePairs) / sizeof(filePairs[0]);

    for (int i = 0; i < numPairs; i++) {
        const char* inputFile = filePairs[i][0];
        const char* outputFile = filePairs[i][1];

        convertToUppercase(inputFile, outputFile);
    }

    return 0;
}
