#pragma once
#include "precompiled/pch.hpp"
#include "Global.h"

namespace CEngine
{
	class SparseSet
	{
		size_t* dense = nullptr;
		size_t* sparse = nullptr;
		size_t n = 0;

	public:
		SparseSet()
		{
			dense = new size_t[MAX_SIZE];
			sparse = new size_t[MAX_SIZE];
			std::fill(sparse, sparse + MAX_SIZE, MAX_SIZE);
		}

		~SparseSet()
		{
			delete[] dense;
			delete[] sparse;
		}

		size_t Insert(Entity newValue)
		{
			if (n >= MAX_SIZE) return MAX_SIZE;
			if (Search(newValue) != MAX_SIZE) return MAX_SIZE;
			dense[n] = newValue;
			sparse[newValue] = n;
			return n++;
		}

		size_t Search(Entity index)
		{
			if (index >= MAX_SIZE) return MAX_SIZE;
			if (sparse[index] < n && dense[sparse[index]] == index) return sparse[index];
			return MAX_SIZE;
		}

		size_t Delete(Entity index)
		{
			if (Search(index) == MAX_SIZE) return MAX_SIZE;
			std::swap(dense[sparse[index]], dense[n - 1]);
			sparse[n - 1] = index;
			sparse[index] = MAX_SIZE;
			return --n;
		}

		void Clear()
		{
			n = 0;
		}

		void Dump()
		{
			for (int i = 0; i < n; i++)
			{
				std::cout << sparse[i] << " ";
			}
			std::cout << std::endl;

			for (int i = 0; i < n; i++)
			{
				std::cout << dense[i] << " ";
			}
			std::cout << std::endl;
		}
	};
}