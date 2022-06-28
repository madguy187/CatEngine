#pragma once
#include "Global.h"

namespace CEngine
{
	template <typename T>
	class SparseSet
	{
		std::array<T, MAX_SIZE> dense;
		std::array<size_t, MAX_SIZE> sparse;

	public:
		template <typename T>
		void Insert(T newValue);

		void Search(size_t index);
		void Delete(size_t index);
		void Clear();
	};
}