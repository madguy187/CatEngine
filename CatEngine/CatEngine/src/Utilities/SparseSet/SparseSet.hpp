#pragma once
#include "precompiled/pch.hpp"
#include "Global.h"

namespace CEngine
{
	class SparseSet
	{
#define NOT_USED MAX_SIZE + 1
		size_t* dense = nullptr;
		size_t* sparse = nullptr;
		size_t n = 0;

	public:
		SparseSet()
		{
			dense = new size_t[MAX_SIZE];
			sparse = new size_t[MAX_SIZE];
			std::fill(sparse, sparse + MAX_SIZE, NOT_USED);
		}

		~SparseSet()
		{
			delete[] dense;
			delete[] sparse;
		}

		void Insert(size_t newValue)
		{
			if (n > MAX_SIZE) return;
			if (Search(newValue) != NOT_USED) return;
			dense[n] = newValue;
			sparse[newValue] = n;
			n++;
		}

		size_t Search(size_t index)
		{
			if (index >= MAX_SIZE) return NOT_USED;
			if (sparse[index] < n && dense[sparse[index]] == index) return sparse[index];
			return NOT_USED;
		}

		void Delete(size_t index)
		{
			if (Search(index) == NOT_USED) return;
			std::swap(dense[sparse[index]], dense[n - 1]);
			sparse[n - 1] = index;
			sparse[index] == NOT_USED;
			n--;
		}
		void Clear()
		{
			std::fill(sparse, sparse + MAX_SIZE, NOT_USED);
			n = 0;
		}
	};
}