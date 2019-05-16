//
// Created by jeza on 19-5-16.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_CONFIGURABLE_H
#define MARKDOWN_PARSER_MARKDOWN_CONFIGURABLE_H

#include <unordered_map>
#include <string>
#include <sstream>
#include "markdown-common.h"

//todo 函数的const版本

namespace Markdown {
    class Configurable {
    public:

        Configurable(const setting_type &settings);

        Configurable() = default;

        virtual ~Configurable() = default;

        /**
         * @brief 设置函数，设置key对应的值为value
         * @param key 需要配置的key
         * @param val 目标值，类型为const std::string&
         * **/
        virtual void set(const std::string &key, const std::string &val);

        /**
         * @brief 设置函数重载1，设置key对应的值为value
         * @param key 需要配置的key
         * @param val 目标值，类型为const char*
         * **/
        virtual void set(const std::string &key, const char *val);

        /**
         * @brief 设置函数重载2，设置key对应的值为value
         * @details 这里的val为模板，允许接受非字符串的数据，只需要在函数内部使用std::to_string函数转换即可
         * @param key 需要配置的key
         * @param val 目标值，类型可以多样
         * **/
        template<typename T>
        void set(const std::string &key, const T &val) {
            set(key, std::to_string(val));
        }

        /**
         * @brief 重载运算符[]，获取一个值
         * @details 非const版本，可以直接修改
         * @param key 需要获取数据的key
         * **/
        virtual std::string &operator[](const std::string &key);

        /**
         * @brief 重载运算符[]，获取一个值
         * @details const版本，不允许修改
         * @param key 需要获取数据的key
         * **/
        virtual const std::string &operator[](const std::string &key) const;

        /**
         * @brief 获取key对应的值
         * @details 这里使用了模板，允许编译器根据上下文返回特定的类型，而不仅仅是字符串
         * @param key 需要获取数据的key
         * **/
        template<typename T = std::string>
        T get(const std::string &key) const {
            std::istringstream stream(_get(key));
            T value;
            stream >> value;
            return value;
        }

        /**
         * @brief 整个替换settings
         * @param settings 将原配置替换成参数对应的settings
         * **/
        virtual void settings(const setting_type &settings);

        /**
         * @brief 返回整个settings
         * **/
        virtual setting_type settings();

    protected:
        /**
         * @brief 内部函数，获取key对应的属性值
         * @details 非const版本，允许修改
         * **/
        std::string &_get(const std::string &key);

        /**
         * @brief 内部函数，获取key对应的属性值
         * @details const版本，不允许修改
         * **/
        const std::string &_get(const std::string &key) const;

        setting_type _settings;
    };

}

#endif //MARKDOWN_PARSER_MARKDOWN_CONFIGURABLE_H
