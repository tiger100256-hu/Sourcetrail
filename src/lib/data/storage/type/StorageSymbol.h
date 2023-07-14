#ifndef STORAGE_SYMBOL_H
#define STORAGE_SYMBOL_H

#include "DefinitionKind.h"
#include "types.h"

class StorageSymbol : public BaseElement
{
public:
	StorageSymbol(): id(0), definitionKind(definitionKindToInt(DEFINITION_NONE)) {m_type = BE_SYMBOL;}
    StorageSymbol(Id id, int definitionKind): id(id), definitionKind(definitionKind) {m_type = BE_SYMBOL;}

public:
	Id id;
	uint8_t definitionKind;
};

#endif	  // STORAGE_SYMBOL_H
