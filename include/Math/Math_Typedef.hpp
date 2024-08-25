/** 
 *  \file Math_Typedef.hpp
 *  
 *  \brief Header file that contians all typedefs related to Project.
 *
 *  This file Typedefs some std datetypes to be worked in SGC enviorment more perfectly.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-26
 */
 
#ifndef MATH_TYPEDEF_HPP_
#define MATH_TYPEDEF_HPP_

#include <iostream>
#include <stdint.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <optional>

/** Thse are global typedef */
using uint = unsigned int;
using ulong = unsigned long;

namespace Game::Math
{

using String = std::string;

template<typename DataType>    
using DynamicArray = std::vector<DataType>;

template<typename Key, typename Value>
using Map = std::map<Key, Value>;

template<typename Key, typename Value>
using UnorderedMap = std::unordered_map<Key, Value>;

template <typename T, typename N>
using Pair = std::pair<T, N>;

template <typename T, typename N>
using Tuple2D = std::tuple<T, N>;

template <typename T, typename N, typename M>
using Tuple3D = std::tuple<T, N, M>;

template <typename T>
using Optional = std::optional<T>; 

} // namespace Game::Math

/** 
 *  This supports stdint so, you can directly use int8_t, etc
 */

#endif // MATH_TYPEDEF_HPP_
