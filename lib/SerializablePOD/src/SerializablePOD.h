/**
 * @file SerializablePOD.h
 * @author Locha Mesh project developers (locha.io)
 * @brief 
 * @version 0.1.1
 * @date 2019-11-02
 * @copyright Copyright (c) 2019 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 */

#ifndef SERIALIZABLEPOD_H
#define SERIALIZABLEPOD_H

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <type_traits>

namespace pod {

template<typename T>
std::size_t serialize_size(const T str) {
    static_assert(std::is_standard_layout<T>::value, "T needs to be POD");

    return sizeof(str);
}

template<typename T>
char* serialize(char* target, const T value) {
    static_assert(std::is_standard_layout<T>::value, "T needs to be POD");

    const auto length = serialize_size(value);
    std::memcpy(target, &value, length);
    return target + length;
}

template<typename T>
const char* deserialize(const char* source, T& target) {
    static_assert(std::is_standard_layout<T>::value, "T needs to be POD");

    const auto length = serialize_size(target);
    std::memcpy(&target, source, length);
    return source + length;
}

}

#endif // SERIALIZABLEPOD_H
