#ifndef STORAGE_FILE_H
#define STORAGE_FILE_H

#include <string>

#include "types.h"

class StorageFile : public BaseElement
{
public:
	StorageFile()
		: id(0)
		, filePath(L"")
		, languageIdentifier(L"")
		, modificationTime("")
		, indexed(true)
		, complete(true)
	{
		m_type = BE_FILE;
	}

	StorageFile(
		Id id,
		std::wstring filePath,
		std::wstring languageIdentifier,
		std::string modificationTime,
		bool indexed,
		bool complete)
		: id(id)
		, filePath(std::move(filePath))
		, languageIdentifier(std::move(languageIdentifier))
		, modificationTime(std::move(modificationTime))
		, indexed(indexed)
		, complete(complete)
	{
		m_type = BE_FILE;
	}

	bool operator<(const StorageFile& other) const
	{
		return filePath < other.filePath;
	}
public:
	Id id;
	std::wstring filePath;
	std::wstring languageIdentifier;
	std::string modificationTime;
	bool indexed;
	bool complete;
};

#endif	  // STORAGE_FILE_H
