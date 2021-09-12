//there I want to split string on words
// main -> words in string parser -> work with commands
// echo -n 1111 fff    555

//1) spaces опускаются, пробелы могут идти в самом начале перед командой - опускаются.
// До команды не может идти ничего, кроме пробелов
// текст, слитный с командой - ршибка


#include "minishell.h"


size_t	words_count(char const *s, char sp)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != sp && (s[i + 1] == sp || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}
