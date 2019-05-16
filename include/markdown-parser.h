//
// Created by jeza on 19-5-14.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_PARSER_H
#define MARKDOWN_PARSER_MARKDOWN_PARSER_H

#include "markdown-common.h"
#include "markdown-abstract-markdown.h"
#include "markdown-abstract-decorator.h"
#include "markdown-absract-parser.h"
#include "markdown-configurable.h"

namespace Markdown {
    class Parser : AbstractParser, Configurable {
    private:
        AbstractMarkdown *_md;  //Markdown 解释器
        AbstractDecorator *_decorator; //装饰器

        /**
         * @brief 内部函数，加上html标签<html><head>...</head><body>...</body></html>，使之成为符合规范的html文档
         * **/
        std::string add_html_tag(const std::string &content, const std::string &style);

    public:
        Parser(AbstractMarkdown *md, AbstractDecorator *decorator) : _md{md}, _decorator(decorator) {}

        Parser(AbstractMarkdown *md, AbstractDecorator *decorator, const setting_type &settings) : Configurable(settings), _md(md), _decorator(decorator) {}

        /**
         * @brief 解析字符串，返回html格式
         * @param content md格式的字符串
         * @return html格式的字符串
         * **/
        parse_result parse_string(const std::string &content) override;

        /**
         * @brief 给定一个文件，解析其字符串并返回html格式
         * @param filename 文件名
         * @return html格式的字符串
         *
         * **/
        parse_result parse_file(const std::string &filename) override;

        ~Parser() {} //todo 虚继承的析构
    };
}

#endif //MARKDOWN_PARSER_MARKDOWN_PARSER_H
