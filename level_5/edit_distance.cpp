#include <iostream>
#include <vector>
#include <algorithm>

std::vector<char> set_string_vector(std::string word)
{
    std::vector<char> v_word(word.length() + 1, '0');
    for (int i = 0; i < word.length(); i++)
    {
        v_word[i + 1] = word[i];
    }
    return v_word;
}

int edit_distane(std::string word_i, std::string word_j)
{
    if (word_i == word_j)
    {
        return 0;
    }

    std::vector<char> v_word_i;
    std::vector<char> v_word_j;
    std::vector<std::vector<int>> v_work;

    v_word_i = set_string_vector(word_i);
    v_word_j = set_string_vector(word_j);
    v_work.resize(v_word_i.size(), std::vector<int>(v_word_j.size(), 0));

    for (int j = 0; j < v_word_j.size(); j++)
    {
        v_work[0][j] = j;
    }

    for (int i = 0; i < v_word_i.size(); i++)
    {
        v_work[i][0] = i;
    }

    for (int j = 1; j < v_word_j.size(); j++)
    {
        for (int i = 1; i < v_word_i.size(); i++)
        {
            if (v_word_i[i] == v_word_j[j])
            {
                //insertion deletion match
                v_work[i][j] = std::min({v_work[i][j - 1] + 1, v_work[i - 1][j] + 1, v_work[i - 1][j - 1]});
            }
            else 
            {
                //insertion deletion mismatch
                v_work[i][j] = std::min({v_work[i][j - 1] + 1, v_work[i - 1][j] + 1, v_work[i - 1][j - 1] + 1});
            }
        }
    }

    /*for (int i = 0; i < v_word_i.size(); i++)
    {
        for (int j = 0; j < v_word_j.size(); j++)
        {
            std::cout << v_work[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    return v_work[word_i.length()][word_j.length()];
}

int main()
{
    std::string word_i;
    std::string word_j;

    std::cin >> word_i;
    std::cin >> word_j;

    std::cout << edit_distane(word_i, word_j) << std::endl;

    return 0;
}