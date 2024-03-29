#include <string.h>

int regex_match(char const *str, char const *pattern) {
    if (*pattern == '\0') return *str == '\0';

    if (*(pattern + 1) != '*') {
        if (*str == '\0' || (*str != *pattern && *pattern != '.'))
            return 0;
        return regex_match(str + 1, pattern + 1);
    }

    while (*str != '\0' && (*str == *pattern || *pattern == '.')) {
        if (regex_match(str, pattern + 2))
            return 1;
        str++;
    }

    return regex_match(str, pattern + 2);
}
