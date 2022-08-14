#include "precompiled/pch.hpp"
#include "Global.h"
#include "EntityManager.h"

namespace CEngine
{
	void EntityManager::Init() {
		Clear();

		Entity i = MAX_SIZE;
		while (i != 0) {
			m_stack.push(i);
			i--;
		}

		m_count = 0;
	}

	Entity EntityManager::CreateEntity()
	{
		Entity ent = m_stack.top();
		m_stack.pop();
		m_count++;
		return ent;
	}

	void EntityManager::DeleteEntity(Entity ent)
	{
		m_stack.push(ent);
		m_entitySignatures[ent].reset();
		m_count--;
	}

	void EntityManager::Clear()
	{
		while (!m_stack.empty())
			m_stack.pop();

		m_count = 0;
	}

	void EntityManager::ChangeSignature(Entity ent, unsigned index, bool value)
	{
		m_entitySignatures[ent].set(index, value);
	}
}