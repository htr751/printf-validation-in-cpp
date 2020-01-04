#pragma once
#include<type_traits>
#include<string_view>
#include<stdexcept>
#include<cassert>

template<typename... Args>
constexpr int CheckPrintf(const std::string_view format) {
	auto index = format.find_first_of("%");
	if (index != std::string_view::npos)
		throw "too few arguments";
	return 1;
}

template<typename T, typename... Args>
constexpr int CheckPrintf(std::string_view format, T firstArgument, Args&&... otherArguments) {
	auto index = format.find_first_of("%");
	if (index == std::string_view::npos)
		throw "too many arguments";

	if (format.at(index + 1) == 'd') {
		if constexpr(!std::is_same_v<int, decltype(firstArgument)>)
			throw  "Error: invalid argument type";
	}
	else if (format.at(index + 1) == 's') {
		if constexpr(!std::is_same_v<std::string_view, decltype(firstArgument)>)
			throw "Error: invalid argument type";
	}

	return CheckPrintf(format.substr(index + 2), std::forward<Args>(otherArguments)...);
}
