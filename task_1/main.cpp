#include <iostream>
#include <utility> 
#include <algorithm> 
#include <cstring> 
#include <cctype> 
 
using Word = std::pair<std::size_t, std::size_t>;
 
// Принадлежит ли символ слову
bool IsSymbolWord(const char &Ch)
{
    return std::isalnum(Ch);
}
 
// Является ли символ разделителем слов
bool IsDelim(const char &Ch)
{
    return (std::isspace(Ch) || std::ispunct(Ch));
}
 
Word FindWord(const char *startStr, const std::size_t &start_pos, const std::size_t &end_pos)
{
    if (start_pos < end_pos)
    {
        const char *First = startStr + start_pos;
        const char *Last = startStr + end_pos;
        const char *ptr_start_word = std::find_if(First, Last, IsSymbolWord);
        if (ptr_start_word != Last)
        {
            const char *ptr_end_word = std::find_if(ptr_start_word, Last, IsDelim);
            const std::size_t idx_start_word = std::distance(startStr, ptr_start_word);
            const std::size_t idx_end_word = std::distance(ptr_start_word, ptr_end_word) + idx_start_word;
            return {idx_start_word, idx_end_word};
        }
    }
    return {-1, -1};
}
 
int main()
{
    const std::size_t N = 80;
    
    char str[N + 1]{'\0'}, substr[N + 1]{'\0'}; // '+ 1' для '\0'(конца строки), если длина строки будет равна N
    std::size_t len{};
    
    std::cout << "Enter word> ";
    std::cin.getline(str, N + 1);
    std::cout << "Enter substr> ";
    std::cin.getline(substr, N + 1);
    std::cout << "Enter length> ";
    std::cin >> len;
    
    const std::size_t substr_len = std::strlen(substr);
    std::size_t start_pos{}, end_pos = std::strlen(str);
    
    std::cout << std::endl
        << "str(" << end_pos << "): " << str << std::endl
        << "substr(" << substr_len << "): " << substr << std::endl;
    
    Word pos{};
    // Пока находятся слова...
    while ((pos = FindWord(str, start_pos, end_pos)) != Word{-1,-1})
    {
        std::size_t word_len = pos.second - pos.first;
        // Если указанная длина равна длине найденного слова...
        if (len == word_len)
        {
            // сдвигаем часть строки, от конца найденного слова, вправо, тем самым освобождая место для подстроки
            std::size_t src_start_substr = pos.first + substr_len;
            if (src_start_substr <= N)
            {
                std::strncpy(str + src_start_substr, str + pos.second, end_pos - src_start_substr);
            }
            // заменяем слово на подстроку
            const std::size_t len_insert_substr = substr_len - (src_start_substr <= N ? 0 : src_start_substr - N);
            std::strncpy(str + pos.first, substr, len_insert_substr);
            // Увеличиваем/уменьшаем длину исходной строки (если найденное слово != подстроке)
            end_pos += (substr_len - word_len);
            if (end_pos >= N)
            {
                end_pos = N;
            }
            // пропускаем подстроку
            start_pos = pos.first + substr_len + 1;
        }
        else
        {
            start_pos = pos.second + 1; // пропускаем слово
        }
    }
    std::cout << std::endl
        << "result str(" << std::strlen(str) << "): " << str << std::endl;
}