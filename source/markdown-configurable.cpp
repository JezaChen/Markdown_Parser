//
// Created by jeza on 19-5-16.
//

#include <iostream>
#include "../include/markdown-configurable.h"

namespace Markdown {
    Configurable::Configurable(const std::unordered_map<std::string, std::string> &settings) : _settings(settings) {}

    void Configurable::set(const std::string &key, const std::string &val) {
        _get(key) = val;
    }

    void Configurable::set(const std::string &key, const char *val) {
        set(key, std::string(val));
    }

    std::string &Configurable::operator[](const std::string &key) {
        return _get(key);
    }

    const std::string &Configurable::operator[](const std::string &key) const {
        return _get(key);
    }

    void Configurable::settings(const setting_type &settings) {
        _settings = settings;
    }

    std::unordered_map<std::string, std::string> Configurable::settings() {
        return _settings;
    }

    std::string &Configurable::_get(const std::string &key) {
        auto setting = _settings.find(key);

        if (setting == _settings.end()) {
            std::cerr << "Cannot find the key: " << key << std::endl;
            exit(EXIT_FAILURE);
        }
        return setting->second;
    }

    const std::string &Configurable::_get(const std::string &key) const {
        auto setting = _settings.find(key);

        if (setting == _settings.end()) {
            std::cerr << "Cannot find the key: " << key << std::endl;
            exit(EXIT_FAILURE);
        }
        return setting->second;
    }
}