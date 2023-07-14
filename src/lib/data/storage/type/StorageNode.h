#ifndef STORAGE_NODE_H
#define STORAGE_NODE_H

#include <string>

#include "types.h"

class StorageNodeData : public BaseElement
{
public:
	StorageNodeData(): type(0), serializedName(L"") {}

	StorageNodeData(int type, std::wstring serializedName)
		: type(type), serializedName(std::move(serializedName))
	{
		m_type = BE_NODE;
	}

	bool operator<(const StorageNodeData& other) const
	{
		return serializedName < other.serializedName;
	}
public:
	uint32_t type;
	std::wstring serializedName;
};

class StorageNode: public StorageNodeData
{
public:
	StorageNode(): StorageNodeData(), id(0) {}

	StorageNode(Id id, int type, std::wstring serializedName)
		: StorageNodeData(type, std::move(serializedName)), id(id)
	{
	}

	StorageNode(Id id, const StorageNodeData& data): StorageNodeData(data), id(id) {}
public:
	Id id;
};

#endif	  // STORAGE_NODE_H
