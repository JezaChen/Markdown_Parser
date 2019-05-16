//
// Created by jeza on 19-5-16.
//

#include <iostream>
#include <sstream>
#include "../include/markdown-css-decorator.h"
#include "../include/util.h"


namespace Markdown {

    std::string CssDecorator::decorate() {
        return read_file_all(_css_filename);
    }
}