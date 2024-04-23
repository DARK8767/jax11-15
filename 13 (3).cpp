// Q2.Write a C++ program to read the contents of a text file. Count and display number of characters,
// words and lines from a file. Find the number of occurrences of a given word present in a file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int count_characters(string text) {
    int count = 0;
    for(char c : text) {
        if(c != ' ' && c != '\n') {
            count++;
        }
    }
    return count;
}

int count_words(string text) {
    int count = 0;
    bool in_word = false;
    for(char c : text) {
        if(c == ' ' || c == '\n') {
            in_word = false;
        } else if(!in_word) {
            count++;
            in_word = true;
        }
    }
    return count;
}

int count_lines(string text) {
    int count = 1;
    for(char c : text) {
        if(c == '\n') {
            count++;
        }
    }
    return count;
}

int count_occurrences(string text, string word) {
    int count = 0;
    size_t pos = text.find(word);
    while(pos != string::npos) {
        count++;
        pos = text.find(word, pos+1);
    }
    return count;
}

int main() {
    ifstream file("example.txt");
    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    cout << "Number of characters: " << count_characters(text) << endl;
    cout << "Number of words: " << count_words(text) << endl;
    cout << "Number of lines: " << count_lines(text) << endl;

    string search_word = "the";
    int occurrences = count_occurrences(text, search_word);
    cout << "Number of occurrences of \"" << search_word << "\": " << occurrences << endl;

    file.close();
    return 0;
}
