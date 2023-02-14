#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int i, j, k, wl, sl, found, idx;
    int *indices = NULL;
    int *count = calloc(MAX_WORDS, sizeof(int));
    char *map = calloc(MAX_WORDS * (nb_words + 1), sizeof(char));

    wl = strlen(words[0]);
    sl = strlen(s);

    if (sl < wl * nb_words)
        return NULL;

    for (i = 0; i < nb_words; i++)
    {
        for (j = 0; j < nb_words; j++)
        {
            if (!strcmp(words[i], words[j]))
            {
                map[j * (nb_words + 1) + count[j]] = i;
                count[j]++;
            }
        }
    }

    for (i = 0; i <= sl - wl * nb_words; i++)
    {
        memset(count, 0, MAX_WORDS * sizeof(int));
        found = 1;

        for (j = 0; j < nb_words; j++)
        {
            idx = -1;

            for (k = 0; k < nb_words; k++)
            {
                if (map[k * (nb_words + 1) + count[k]] == j)
                {
                    idx = k;
                    break;
                }
            }

            if (idx == -1)
            {
                found = 0;
                break;
            }

            count[idx]++;

            if (strncmp(s + i + j * wl, words[idx], wl))
            {
                found = 0;
                break;
            }
        }

        if (found)
        {
            indices = realloc(indices, (*n + 1) * sizeof(int));
            indices[(*n)++] = i;
        }
    }

    free(count);
    free(map);

    return indices;
}
