//
// Created by jeza on 19-5-15.
//

#ifndef MARKDOWN_PARSER_UTIL_H
#define MARKDOWN_PARSER_UTIL_H

#include <string>
#include <vector>

/**
 * @name split_str
 * @brief 按delim切割字符串
 * @param str 要切割的字符串
 * @param delim 分隔符
 * @return std::vector<std::string> 切割后的子字符串集合
 * **/
std::vector<std::string> split_str(const std::string &str, const std::string &delim);

/**
 * @name ltrim
 * @brief 修剪字符串s左侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void ltrim(std::string &s);

/**
 * @name rtrim
 * @brief 修剪字符串s右侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void rtrim(std::string &s);

/**
 * @name rtrim
 * @brief 修剪字符串s两侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void trim(std::string &s);

/**
 * @name ltrim_copy
 * @brief 修剪字符串s左侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string ltrim_copy(std::string s);

/**
 * @name ltrim_copy
 * @brief 修剪字符串s右侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string rtrim_copy(std::string s);

/**
 * @name ltrim_copy
 * @brief 修剪字符串s两侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string trim_copy(std::string s);

std::string read_file_all(const std::string &filename);

void write_to_file(const std::string &filename, const std::string &content);



#endif //MARKDOWN_PARSER_UTIL_H
