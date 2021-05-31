#pragma once
#include <memory>

template <typename T, typename U>
inline bool equals(const std::weak_ptr<T>& t, const std::shared_ptr<U>& u)
{
	return !t.owner_before(u) && !u.owner_before(t);
}

template <typename T, typename U>
inline bool equals(const std::weak_ptr<T>& t, const std::weak_ptr<U>& u)
{
	return !t.owner_before(u) && !u.owner_before(t);
}