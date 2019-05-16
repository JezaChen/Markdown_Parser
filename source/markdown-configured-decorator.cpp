//
// Created by jeza on 19-5-16.
//

#include <iostream>
#include <sstream>
#include "../include/markdown-configured-decorator.h"


namespace Markdown {
    std::string ConfiguredDecorator::decorate() {
        std::stringstream ss;
        for (auto &item : _settings) {
            ss << "." << item.first << "{ " << item.second << " }\n";
        }
        return ss.str();
    }
}