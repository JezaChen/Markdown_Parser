//
// Created by jeza on 19-5-16.
//

#include <sstream>
#include "../include/markdown-parser.h"
#include "../include/markdown-common.h"
#include "../include/util.h"

namespace Markdown {
    parse_result Parser::parse_string(const std::string &content) {
        parse_result ret = _md->parse(content);
        std::string style;

        if (_decorator)
            style = _decorator->decorate();
        else  // 如果装饰器指针为空，style块可以用空字符串；来表示
            style = "";

        ret = add_html_tag(ret, style);
        return ret;
    }

    parse_result Parser::parse_file(const std::string &filename) {
        auto ret = read_file_all("test.md");
        ret = _md->parse(ret);
        std::string style;

        if (_decorator)
            style = _decorator->decorate();
        else  // 如果装饰器指针为空，style块可以用空字符串；来表示
            style = "";

        ret = add_html_tag(ret, style);
        return ret;
    }

    std::string Parser::add_html_tag(const std::string &content, const std::string &style) {
        std::stringstream ss;
        ss << "<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "<meta charset=\""
           << _get("charset")
           << "\">\n"
              "<title></title>\n"
              "</head>\n"
              "<body class=\"markdown-body\">\n"
           << content
           << "</body>\n"
              "<style>"
           << style
           << "</style>"
              "</html>";
        return ss.str();
    }
}
