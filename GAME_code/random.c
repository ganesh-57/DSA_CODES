#include <stdio.h>

int main() {
    FILE *file;
    long int number;

    // Open the file in read mode
    file = fopen("reports.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read long integer numbers until the end of the file
    while (fscanf(file, "%d", &number) == 1) {
        // Process the number (e.g., print it)
        printf("%d\n", number);
    }

    // Close the file
    fclose(file);

    return 0;
}
