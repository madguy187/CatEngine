#include "precompiled/pch.hpp"
#include "Global.h"
#include "SystemManager.h"

namespace CEngine
{
	void SystemManager::EntitySignatureChange(Entity ent, Signature signature)
	{
		for (unsigned i = 0; i < GetSize(); i++) {
			if (signature == m_SystemSignature[i]) {
				m_System[i]->entArray.insert(ent);
			}
			else {
				m_System[i]->entArray.erase(ent);
			}
		}
	}

	void SystemManager::ClearAllSystem()
	{
		for (auto const& system : m_System) {
			system->entArray.clear();
		}
	}

	void SystemManager::RemoveEntity(Entity ent)
	{
		for (auto const& system : m_System) {
			system->entArray.erase(ent);
		}
	}
}