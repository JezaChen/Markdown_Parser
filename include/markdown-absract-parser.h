//
// Created by jeza on 19-5-16.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_ABSRACT_PARSER_H
#define MARKDOWN_PARSER_MARKDOWN_ABSRACT_PARSER_H

#include "markdown-common.h"

namespace Markdown {
    /**
     * @brief 解析器的抽象类
     * **/
    class AbstractParser {
    public:
        AbstractParser() = default;

        /**
         * @brief 解析字符串，返回html格式
         * @param content md格式的字符串
         * @return html格式的字符串
         * **/
        virtual parse_result parse_string(const std::string &content) = 0;

        /**
         * @brief 给定一个文件，解析其字符串并返回html格式
         * @param filename 文件名
         * @return html格式的字符串
         *
         * **/
        virtual parse_result parse_file(const std::string &filename) = 0;
    };
}
#endif //MARKDOWN_PARSER_MARKDOWN_ABSRACT_PARSER_H
