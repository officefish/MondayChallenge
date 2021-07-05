// MondayChallenge.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

// split string by list of selimeters
std::vector<std::string> split(std::string x, std::vector<char> delim)
{
    x += delim[0];
    std::vector<std::string> splitted;
    std::string temp = "";
    for (int i = 0; i < x.length(); i++)
    {
        for (int j = 0; j < delim.size(); j++) {

            if (x[i] == delim[j])
            {
                splitted.push_back(temp); //store words in "splitted" vector
                temp = "";
                i++;
            }
        }
        temp += x[i];
    }
    return splitted;
}

// string tolovercase
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}


int main(int argc, char** argv)
{
    // TODO: relative path
    std::string path = "C:\\Users\\RIK\\source\\repos\\MondayChallenge\\x64\\Debug\\";

    if (!argv[1]) {
        std::cout << "No console argument found" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];

    std::unordered_map<std::string, int32_t> WordsMap;
    std::vector<char> delim{ '\'', ',', ' ', '.', '!', '?', '-' };

    std::ifstream source(path + fileName);
    if (source.is_open())
    {
        std::string line;
        while (getline(source, line)) {
            std::vector<std::string> words = split(line, delim);
            for (auto& word : words) {
                // TODO: validate word and split it recursion way until it is not valid
                std::transform(word.begin(), word.end(), word.begin(), asciitolower);
                WordsMap[word]++;
            }
        }
        source.close();
    }
    else {
        std::cout << "Text file: \" "<< path << " \" not found, or not valid" << std::endl;
    }

    for (auto const& [key, val] : WordsMap)
    {
        std::cout << key
            << ':'
            << val
            << std::endl;
    }
}
