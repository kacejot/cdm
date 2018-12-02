#pragma once

template <typename T>
class Condition
{
public:
	using ItemType = T;

public:
	virtual bool match(const T& item) const = 0;
	virtual ~Condition() = default;
};

template<typename T, typename U,
		typename First = std::remove_reference_t<T>,
		typename Second = std::remove_reference_t<U>>
using are_same_type_conditions_t = std::enable_if_t<
		std::is_same_v<typename First::ItemType, typename Second::ItemType> &&
		std::is_base_of_v<Condition<typename First::ItemType>, First> &&
		std::is_base_of_v<Condition<typename Second::ItemType>, Second>>;