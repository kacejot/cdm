#pragma once

#include "condition/condition.h"

#include <type_traits>
#include <utility>

template <typename T, typename U>
class AndCondition : public Condition<typename std::remove_reference_t<T>::ItemType>
{
public:
    using FirstType = std::remove_reference_t<T>;
    using SecondType = std::remove_reference_t<U>;
    using ItemType = typename FirstType::ItemType;

    static_assert(std::is_same_v<typename FirstType::ItemType, typename SecondType::ItemType>, "Conditions must have same ItemType");
    static_assert(std::is_base_of_v<Condition<ItemType>, FirstType>, "Conditions must be derived from Condition<T>");
    static_assert(std::is_base_of_v<Condition<ItemType>, SecondType>, "Conditions must be derived from Condition<T>");

public:
    AndCondition(T&& first, U&& second);

public:
    bool match(const ItemType& item) const override;

private:
    FirstType m_first;
    SecondType m_second;
};

template<typename T, typename U>
AndCondition<T, U>::AndCondition(T&& first, U&& second) :
    m_first(std::forward<T>(first)),
    m_second(std::forward<U>(second))
{

}

template<typename T, typename U>
bool AndCondition<T, U>::match(const ItemType& item) const
{
    return m_first.match(item) && m_second.match(item);
}

template <typename T, typename U, typename On = are_same_type_conditions_t<T, U>>
decltype(auto) operator&&(T&& left, U&& right)
{
    return AndCondition
    {
        std::forward<T>(left),
        std::forward<U>(right)
    };
};