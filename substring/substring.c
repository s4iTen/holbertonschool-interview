#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_valid_substr(char const *s, char const **words, int nb_words,
int word_len, int start)
{
	int *seen = calloc(nb_words, sizeof(int));
	int words_found = 0;
	int i, j;
	char *word;

	for (i = 0; i < nb_words; i++)
	{
		word = (char *)malloc((word_len + 1) * sizeof(char));
		strncpy(word, s + start + i * word_len, word_len);
		word[word_len] = '\0';

		for (j = 0; j < nb_words; j++)
		{
			if (!seen[j] && strcmp(word, words[j]) == 0)
			{
				seen[j] = 1;
				words_found++;
				break;
			}
		}
		free(word);
	}

	free(seen);
	return (words_found == nb_words);
}
/**
 * find_substring - Finds all possible substrings containing all specified words.
 * @s: The string to scan.
 * @words: Array of words to find within the string.
 * @nb_words: The number of words in the array `words`.
 * @n: Pointer to an integer to store the number of substrings found.
 * 
 * Return: An array of the starting indices of each found substring,
 * or NULL if none are found.
 * If no valid substrings are found, `n` will be set to 0.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, str_len, substr_count = 0, i;
	int *indices = NULL;

	if (!s || !words || nb_words <= 0)
	{
		*n = 0;
		return (NULL);
	}

	word_len = strlen(words[0]);
	str_len = strlen(s);

	for (i = 0; i <= str_len - nb_words * word_len; i++)
	{
		if (is_valid_substr(s, words, nb_words, word_len, i))
		{
			substr_count++;
			indices = realloc(indices, substr_count * sizeof(int));
			indices[substr_count - 1] = i;
		}
	}

	*n = substr_count;
	return (indices);
}
