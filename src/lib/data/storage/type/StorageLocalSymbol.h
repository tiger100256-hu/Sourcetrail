#ifndef STORAGE_LOCAL_SYMBOL_H
#define STORAGE_LOCAL_SYMBOL_H

#include <string>

#include "types.h"

class StorageLocalSymbolData : BaseElement
{
public:
	StorageLocalSymbolData() : name(L"") { m_type = BE_LOCALSYMBOL; }

	StorageLocalSymbolData(std::wstring name): name(std::move(name)) {}

	bool operator<(const StorageLocalSymbolData& other) const
	{
		return name < other.name;
	}
public:
	std::wstring name;
};

class StorageLocalSymbol: public StorageLocalSymbolData
{
public:
	StorageLocalSymbol(): StorageLocalSymbolData(), id(0) {}

	StorageLocalSymbol(Id id, const StorageLocalSymbolData& data)
		: StorageLocalSymbolData(data), id(id)
	{
	}

	StorageLocalSymbol(Id id, std::wstring name): StorageLocalSymbolData(std::move(name)), id(id) {}
public:
	Id id;
};

#endif	  // STORAGE_LOCAL_SYMBOL_H
