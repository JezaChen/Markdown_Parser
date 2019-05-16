//
// Created by jeza on 19-5-16.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_ABSTRACT_DECORATOR_H
#define MARKDOWN_PARSER_MARKDOWN_ABSTRACT_DECORATOR_H

#include <string>

namespace Markdown {
    /**
     * @brief 装饰器的抽象类
     * @details 装饰器用于style样式
     * **/
    class AbstractDecorator {
    public:
        AbstractDecorator() {};

        /**
         * @brief 抽象函数，产生style样式语句
         * @details 具体实现交由给子类完成
         * @details 注意返回的字符串并不包含<style>标签，需要上层调用对象加上
         * **/
        virtual std::string decorate() = 0;

        virtual ~AbstractDecorator() {}
    };
}

#endif //MARKDOWN_PARSER_MARKDOWN_ABSTRACT_DECORATOR_H
