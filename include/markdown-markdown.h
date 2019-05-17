//
// Created by jeza on 19-5-14.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_MARKDOWN_H
#define MARKDOWN_PARSER_MARKDOWN_MARKDOWN_H

#include "markdown-abstract-markdown.h"


namespace Markdown {

    class MarkdownP : public AbstractMarkdown {
    private:
        /**UPDATE: 为了支持嵌套列表，将状态改成了状态栈，用于存储前面的"深度值"，即前面连续多行开头的空白字符数目，
         * 根据栈顶可以分析出当前行是否深入一层嵌套还是从深层列表中出去**/
        std::stack<int> ul_level;
        std::stack<int> ol_level;

        /**UPDATE: 为了支持嵌套blockquote，将状态改成数值，表示该行处于多少层的blockquote中**/
        int blockquote_level;

        /**
         * @name regex_handler
         * @brief 处理行元素的正则处理器，元素为markdown_regex_expression(std::pair)，第一个元素为匹配用的正则表达式，第二个元素为处理函数
         * **/
        std::vector<markdown_regex_expression> regex_handler;

        /**
         * @name regex_handler_block
         * @brief 处理块元素的正则处理器，元素为markdown_regex_expression(std::pair)，第一个元素为匹配用的正则表达式，第二个元素为处理函数
         * **/
        std::vector<markdown_regex_expression> regex_handler_block;


    protected:
        parse_result parse_headline(const std::string &line, const std::regex &reg) override;

        parse_result parse_code(const std::string &line, const std::regex &reg) override;

        parse_result parse_inline_code(const std::string &line, const std::regex &reg) override;

        parse_result parse_hr(const std::string &line, const std::regex &reg) override;

        parse_result parse_bullet_list(const std::string &line, const std::regex &reg) override;

        parse_result parse_numbered_list(const std::string &line, const std::regex &reg) override;

        parse_result parse_bold(const std::string &line, const std::regex &reg) override;

        parse_result parse_italic(const std::string &line, const std::regex &reg) override;

        parse_result parse_link(const std::string &line, const std::regex &reg) override;

        parse_result parse_table(const std::string &line, const std::regex &reg) override;

        parse_result parse_image(const std::string &line, const std::regex &reg) override;

        parse_result parse_blockquoting(const std::string &line, const std::regex &reg) override;

        parse_result parse_del(const std::string &line, const std::regex &reg) override;

        /**
         * @name parse_line
         * @brief 读取一行数据并解析该行的数据，转化成html格式的代码
         * @param line 一行数据
         * @return std::string 该行数据解析后的html代码，注意此时已经可能不止一行了
         * **/
        std::string parse_line(std::string line);

        /**
         * @name parse_block
         * @brief 读取整篇文档，解析匹配到特定格式的块(表格、代码)，将该块转化成html格式的代码
         * @param text 全文
         * @return std::string 转化后的全文，局部是html代码
         * **/
        std::string parse_block(std::string text);

    public:
        MarkdownP();

        std::string parse(std::string text) override;

    };
}

#endif //MARKDOWN_PARSER_MARKDOWN_MARKDOWN_H
