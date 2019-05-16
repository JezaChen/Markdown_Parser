cmake_minimum_required(VERSION 3.13)
project(Markdown_Parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(Markdown_Parser main.cpp include/markdown-parser.h include/markdown-common.h include/markdown-abstract-markdown.h source/markdown-abstract-markdown.cpp include/markdown-markdown.h source/markdown-markdown.cpp include/util.h source/util.cpp source/markdown-parser.cpp include/markdown-absract-parser.h include/markdown-configurable.h source/markdown-configurable.cpp include/markdown-abstract-decorator.h include/markdown-configured-decorator.h source/markdown-configured-decorator.cpp include/markdown-css-decorator.h source/markdown-css-decorator.cpp)