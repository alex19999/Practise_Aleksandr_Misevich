#include "words_counter.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main() {
    std::ifstream file("file.txt");
    std::ofstream fout("fout.txt");
    std::map<string, int> map;
    if(file.is_open()) {
        string word;
        while(!file.eof()) {
            file >> word;
            word = prepare(word);
            map[word]++;
        }
        std::vector< std::pair< string, int > > vec(map.begin(), map.end());
        std::sort(vec.begin(), vec.end(), compare);
        for (const auto& p : vec) {
            std::cout << p.first << ' ' << p.second << std::endl;
            fout << p.first << ' ' << p.second << "\n";
        }
        fout.close();
        file.close();
    }
}

