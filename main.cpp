#include <iostream>
#include <unordered_map>
#include "include/util.h"
#include "include/markdown-css-decorator.h"
#include "include/markdown-markdown.h"
#include "include/markdown-parser.h"


int main() {
    using namespace Markdown;
    MarkdownP md;

    setting_type settings;
    settings["charset"] = "utf-8";

    CssDecorator decorator("css/typora-dropbox.css"); //新建一个css装饰器，后续再转成父类指针即可。

    Parser parser(&md, &decorator,settings);
    write_to_file("test.html", parser.parse_file("test.md"));


//    setting_type settings;
//    settings["h1"] = "font-size=24;";
//    settings["blockquote"] = "font-size=26;";
//    Decorator decorator(settings);
//    std::cout << decorator.decorate();
    return 0;
}