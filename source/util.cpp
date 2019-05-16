//
// Created by jeza on 19-5-15.
//
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../include/util.h"

using namespace std;

vector<string> split_str(const string &str, const string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

std::string read_file_all(const std::string &filename) {
    ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open input file \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::stringstream ret;
    ret << file.rdbuf();  // 输出全部内容
    file.close();
    return ret.str();
}

void write_to_file(const std::string &filename, const std::string &content) {
    ofstream file(filename);
    if (!file) {
        std::cerr << "Cannot open output file \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    file << content;
    file.close();
}