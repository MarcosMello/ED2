#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void naiveStringMatcher(char *string, char *pattern){
    int stringSize = strlen(string);
    int patternSize = strlen(pattern);

    for (int i = 0; i < (stringSize - patternSize) + 1; i++){
        int stringMatchingCounter = 0;

        for (int j = i; (j - i) < patternSize && string[j] == pattern[stringMatchingCounter]; j++){
            stringMatchingCounter++;
        }

        if (stringMatchingCounter == patternSize){
            printf("Pattern found in %d - %d.\n", i, i + (patternSize - 1));
            return;
        }
    }
}

// int *prefixKMP(char *pattern){
//     int patternSize = strlen(pattern);

//     int prefix
// }