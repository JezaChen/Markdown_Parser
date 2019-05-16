//
// Created by jeza on 19-5-16.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_CSS_DECORATOR_H
#define MARKDOWN_PARSER_MARKDOWN_CSS_DECORATOR_H

#include "markdown-abstract-decorator.h"

namespace Markdown {
    /**
     * @brief CssDecorator 类，接受一个CSS文件路径，并根据CSS文件渲染出特定的style样式
     * @details 需要继承两个类：抽象类AbstractDecorator以及配置类Configurable
     * **/
    class CssDecorator : public AbstractDecorator {
    protected:
        std::string _css_filename;

    public:
        CssDecorator() = default;

        CssDecorator(const std::string &css_filename) : _css_filename(css_filename) {}

        std::string decorate() override;
    };
}
#endif //MARKDOWN_PARSER_MARKDOWN_CSS_DECORATOR_H
