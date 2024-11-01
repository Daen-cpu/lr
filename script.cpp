#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Функция для подсчета слов, начинающихся с 'a'
int wordcount_a_started(const vector<string>& words) {
    int count = 0;
    for (const auto& word : words) {
        if (word[0] == 'a' || word[0] == 'A') {
            count++;
        }
    }
    return count;
}

// Функция для нахождения длины самого короткого слова
int length_of_shortest(const vector<string>& words) {
    int min_length = INT_MAX;
    for (const auto& word : words) {
        if (word.length() < min_length) {
        	min_length = word.length();
        }
    }
    return min_length;
}

// Функция для подсчета букв 'a' в последнем слове
int wordcount_a_in_last_word(const vector<string>& words) {
    if (words.empty()) return 0;
    const string& last_word = words.back();
    return count(last_word.begin(), last_word.end(), 'a') + count(last_word.begin(), last_word.end(), 'A');
}

// Функция для замены верхнего регистра на нижний
void to_lower(vector<string>& words) {
    for (auto& word : words) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
}

// Функция для нахождения количества слов с одинаковыми первым и последним символами
int wordcount_same_simbols_inout(const vector<string>& words) {
    int count = 0;
    for (const auto& word : words) {
        if (word.length() > 0 && word[0] == word.back()) {
            count++;
        }
    }
    return count;
}

// Функция для нахождения самой короткой общей подстроки
string shortest_substring(const string& word1, const string& word2) {
    int min_length = INT_MAX;
    string result;

    for (size_t i = 0; i < word1.length(); i++) {
        for (size_t j = 0; j < word2.length(); j++) {
            string common = "";
            size_t k = 0;
            while (i + k < word1.length() and j + k < word2.length() and word1[i + k] == word2[j + k]) {
                common += word1[i + k];
                k++;
            }
            if (!common.empty() and common.length() < min_length) {
            	min_length = common.length();
                result = common;
            }
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Введите строку из 10 слов на латинице: ";
    getline(cin, input);

    istringstream iss(input);
    vector<string> words;
    string word;

    // Считываем слова из строки
    while (iss >> word) {
        words.push_back(word);
    }

    // Выполняем поставленные задачи
    cout << "Количество слов, начинающихся с 'a': " << wordcount_a_started(words) << endl;
    cout << "Длина самого короткого слова: " << length_of_shortest(words) << endl;
    cout << "Количество букв 'a' в последнем слове: " << wordcount_a_in_last_word(words) << endl;

    to_lower(words);
    cout << "Слова в нижнем регистре: ";
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;

    cout << "Количество слов, у которых первый и последний символы совпадают: " << wordcount_same_simbols_inout(words) << endl;


    if (words.size() >= 2) {
        string commonSubstring = shortest_substring(words[0], words[1]);
        cout << "Самая короткая общая подстрока между первым и вторым словом: " << commonSubstring << endl;
    } else {
        cout << "Недостаточно слов для поиска общей подстроки." << endl;
    }

    return 0;
}
