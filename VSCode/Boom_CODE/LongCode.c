#include <stdio.h>
#include <string.h>

#define MAX_MONTHS 12
#define MAX_TYPES 26
#define MAX_STRING 100

int main() {
    char data_str[MAX_STRING];
    int banana_types_per_month[MAX_MONTHS][MAX_TYPES] = {0};
    int counts_per_month[MAX_MONTHS] = {0};

    printf("Enter the string: ");
    scanf("%s", data_str);

    int length = strlen(data_str);
    for (int i = 0; i < length; i += 2) {
        char month = data_str[i];
        int month_index;
        if (month >= '1' && month <= '9') {
            month_index = month - '1';
        } else {
            month_index = 9 + (month - 'A');
        }
        int banana_type_index = data_str[i+1] - 'A';

        if (!banana_types_per_month[month_index][banana_type_index]) {
            banana_types_per_month[month_index][banana_type_index] = 1;
            counts_per_month[month_index]++;
        }
    }

    int max_count = 0;
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (counts_per_month[i] > max_count) {
            max_count = counts_per_month[i];
        }
    }

    printf("Counts per month:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d: %d\n", i + 1, counts_per_month[i]);
    }
    for (int i = 9; i < 12; i++) {
        printf("%c: %d\n", 'A' + i - 9, counts_per_month[i]);
    }
    printf("Maximum Type Count: %d\n", max_count);

    return 0;
}