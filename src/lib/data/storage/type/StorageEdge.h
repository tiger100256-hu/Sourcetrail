#ifndef STORAGE_EDGE_H
#define STORAGE_EDGE_H

#include "types.h"

class StorageEdgeData: public BaseElement
{
public:
	StorageEdgeData(): type(0), sourceNodeId(0), targetNodeId(0) {m_type = BE_EDGE;}

	StorageEdgeData(int type, Id sourceNodeId, Id targetNodeId)
		: type(type), sourceNodeId(sourceNodeId), targetNodeId(targetNodeId)
	{
		m_type = BE_EDGE;
	}

	bool operator<(const StorageEdgeData& other) const
	{
		if (type != other.type)
		{
			return type < other.type;
		}
		else if (sourceNodeId != other.sourceNodeId)
		{
			return sourceNodeId < other.sourceNodeId;
		}
		else
		{
			return targetNodeId < other.targetNodeId;
		}
	}
public:
	uint16_t type;
	Id sourceNodeId;
	Id targetNodeId;
};

class StorageEdge: public StorageEdgeData
{
public:
	StorageEdge(): StorageEdgeData(), id(0) {}

	StorageEdge(Id id, const StorageEdgeData& data): StorageEdgeData(data), id(id) {}

	StorageEdge(Id id, int type, Id sourceNodeId, Id targetNodeId)
		: StorageEdgeData(type, sourceNodeId, targetNodeId), id(id)
	{
	}
public:
	Id id;
};

#endif	  // STORAGE_EDGE_H
