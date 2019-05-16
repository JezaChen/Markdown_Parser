//
// Created by jeza on 19-5-14.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_ABSTRACT_MARKDOWN_H
#define MARKDOWN_PARSER_MARKDOWN_ABSTRACT_MARKDOWN_H

#include <string>
#include <regex>
#include "markdown-common.h"

namespace Markdown {
    /***
     * 抽象类 AbstractMarkdown
     * 提供多个抽象函数，用于解析字符串并转成html文档格式，函数需要由子类来实现
     * todo 一般用法：具体实现函数放在private域内，暴露接口用于接受字符串并能自动选择相应的函数进行处理
     * ***/
    class AbstractMarkdown {
    protected:

        /*************************
         * @name parse_headline
         * @brief 解析标题
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_headline(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_code
         * @brief 解析代码
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_code(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_code
         * @brief 解析内联代码
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_inline_code(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_hr
         * @brief 解析分隔符
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_hr(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_bullet_list
         * @brief 解析无序列表
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_bullet_list(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_numbered_list
         * @brief 解析有序列表
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_numbered_list(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_bolditalic
         * @brief 解析加粗文字
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_bold(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_italic
         * @brief 解析斜体文字
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_italic(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_link
         * @brief 解析链接
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_link(const std::string &line, const std::regex &reg) = 0;

        //virtual parse_result parse_reflink(const std::string &str) = 0;

        //virtual parse_result parse_smlink(const std::string &str) = 0;

        /*************************
         * @name parse_table
         * @brief 解析表格
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_table(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_image
         * @brief 解析图像
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_image(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_del
         * @brief 解析删除
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_del(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_blockquoting
         * @brief 解析块内引用
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parse_blockquoting(const std::string &line, const std::regex &reg) = 0;

        /****
         * 下面是每一个Markdown格式对应的正则表达式pattern
         * 需要子类进行定义
         * ****/
        /**处理标题的正则表达式pattern**/
        std::regex headline_pattern;
        /**处理粗体的正则表达式pattern**/
        std::regex bold_pattern;
        /**处理斜体的正则表达式pattern**/
        std::regex italic_pattern;
        /**处理删除线的正则表达式pattern**/
        std::regex del_pattern;
        /**处理分隔符的正则表达式pattern**/
        std::regex hr_pattern;
        /**处理无序列表项的正则表达式pattern**/
        std::regex ul_li_pattern;
        /**处理有序列表项的正则表达式pattern**/
        std::regex ol_li_pattern;
        /**处理链接的正则表达式pattern**/
        std::regex link_pattern;
        /**处理图片的正则表达式pattern**/
        std::regex img_pattern;
        /**处理代码块的正则表达式pattern**/
        std::regex code_pattern;
        /**处理内联代码的正则表达式pattern**/
        std::regex inline_code_pattern;
        /**处理块引用的正则表达式pattern**/
        std::regex blockquoting_pattern;
        /**处理表格的正则表达式pattern**/
        std::regex table_pattern;

    public:
        AbstractMarkdown() {};

        /*************************
         * @name parse
         * @brief 接受数据，并返回html的格式
         * @param line 数据
         * @return std::string html格式的数据
         * **********************/
        virtual std::string parse(std::string text) = 0;
    };
}


#endif //MARKDOWN_PARSER_MARKDOWN_ABSTRACT_MARKDOWN_H
