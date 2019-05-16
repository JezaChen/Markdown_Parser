//
// Created by jeza on 19-5-14.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_COMMON_H
#define MARKDOWN_PARSER_MARKDOWN_COMMON_H

#include <utility>
#include <string>
#include <vector>
#include <functional>
#include <regex>
#include <unordered_map>

namespace Markdown {
    /************************************************
     *Markdown解释单个结点的结果数据类型
     ************************************************/
    using parse_result = std::string;


    /************************************************
     * Markdown解释器所用的markdown_regex_expression类型
     * 第一个元素为正则表达式，第二个元素为匹配后处理的函数 std::function<parse_result (const std::smatch&)>
     ************************************************/
    using markdown_regex_expression = std::pair<std::regex, std::function<parse_result(const std::string &,
                                                                                       const std::regex &)>>;

    /**用于存储配置的数据类型**/
    using setting_type = std::unordered_map<std::string, std::string>;
};


#endif //MARKDOWN_PARSER_MARKDOWN_COMMON_H
