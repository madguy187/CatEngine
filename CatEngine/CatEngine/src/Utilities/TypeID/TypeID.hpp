#pragma once

namespace CEngine
{
	template <typename T>
	class TypeID
	{
		static unsigned _counter;
	public:
		template <typename U>
		static unsigned RegisterID() {
			return RemoveConst< std::decay_t<U> >();
		}

		template <typename U>
		static unsigned GetID() {
			return RemoveConst< std::decay_t<U> >();
		}

		template <typename U>
		static unsigned RemoveConst() {
			static unsigned const id = _counter++;
			return id;
		}
	};
}