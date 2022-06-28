#pragma once

namespace CEngine
{
	template <typename Type>
	class MemoryHandler
	{
	public:
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;
		typedef Type*					pointer;
		typedef const Type*				const_pointer;
		typedef Type&					reference;
		typedef const Type&				const_reference;
		typedef Type					value_type;

		MemoryHandler() {};
		MemoryHandler(const MemoryHandler&) {}
		~MemoryHandler() {};

		template <class U>
		MemoryHandler(const MemoryHandler<U>&) {}

		pointer           address(reference x) const { return &x; }
		const_pointer     address(const_reference x) const { return &x; }
		MemoryHandler<Type>& operator=(const MemoryHandler&) { return *this; }
		void              construct(pointer p, const Type& val)
		{
			new ((Type*)p) Type(val);
		}
		void              destroy(pointer p) { p->~Type(); }

		size_type         max_size() const { return size_t(-1); }

		template <class U>
		struct rebind { typedef MemoryHandler<U> other; };

		template <class U>
		MemoryHandler& operator=(const MemoryHandler<U>&) { return *this; }

		pointer allocate(size_type count)
		{
			//totalMem += sizeof(value_type) * count;
			pointer t = (pointer) malloc(count * sizeof(value_type));

#ifdef C_DEBUG
			//std::cout << "Allocating: " << typeid(value_type).name() << ", " << count << " * " << sizeof(value_type) << " bytes at " << t << std::endl;
#endif

			return t;
		}

		void deallocate(pointer ptr, size_t)
		{
			if (!ptr)
			{
				CENGINE_ERROR("Deallocating null pointer");
				return;
			}
#ifdef C_DEBUG
			//std::cout << "Deallocating: " << typeid(value_type).name() << " at " << ptr << std::endl;
#endif

			free(ptr);
			//totalMem -= sizeof(value_type);
		}
	};
}