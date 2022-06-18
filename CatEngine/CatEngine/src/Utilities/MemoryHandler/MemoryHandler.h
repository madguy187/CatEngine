#pragma once

namespace CEngine
{
	class MemoryHandler
	{
		inline static size_t totalMem;
	public:
		MemoryHandler() {};

		inline const static size_t currentMemory() { return totalMem; }

		template <typename T>
		static T* Allocate(bool create_new = true, size_t count = 1)
		{
#ifdef C_DEBUG
			std::cout << "Allocating: " << typeid(T).name() << ", " << sizeof(T) << std::endl;
#endif
			totalMem += sizeof(T) * count;

			if (!create_new) return nullptr;
			if (count > 1) return new T[count];

			return new T;
		}

		template <typename T>
		static void Deallocate(T* ptr = nullptr)
		{
#ifdef C_DEBUG
			std::cout << "Deallocating: " << typeid(T).name() << ", " << sizeof(T) << std::endl;
#endif
			totalMem -= sizeof(T);

			if (ptr) delete ptr;
			return nullptr;
		}
	};
}