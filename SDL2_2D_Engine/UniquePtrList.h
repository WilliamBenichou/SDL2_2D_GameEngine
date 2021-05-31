#ifndef UNIQUE_PTR_LIST_H
#define UNIQUE_PTR_LIST_H

#include <list>
#include <memory>

template <class T>
class UniquePtrList :
	public std::list<std::unique_ptr<T>>
{
	using iterator = std::list<std::unique_ptr<T>>;

public:
	inline void addWithMovePtr(std::unique_ptr<T>& srcPtr)
	{
		push_back(std::move(srcPtr));
	}

	inline iterator findRawPtr(T* rawPtrToFind)
	{
		iterator resultIterator = std::find_if(
			begin(),
			end(),
			[&](std::unique_ptr<T>& p) {
				return p.get() == rawPtrToFind;
			});
	}

	inline bool eraseRawPtr(T* srcPtr)
	{
		iterator it = findRawPtr(srcPtr);
		if (it != end()) {
			erase(it);
			return true;
		}
		return false;
	}
};
#endif // !UNIQUE_PTR_LIST_H
