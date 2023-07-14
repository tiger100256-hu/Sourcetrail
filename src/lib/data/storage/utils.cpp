#include "./type/utils.h"

namespace UTILS
{
bool is_file(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BE_FILE) == BaseElement::BE_FILE))
		return true;
	return false;
}
bool is_file_node(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BS_NF) == BaseElement::BS_NF))
		return true;
	return false;
}

StorageFilePtr get_file_unsafe(BaseElementPtr ptr) {
	return std::static_pointer_cast<StorageFile>(ptr);
}

StorageFilePtr get_file(BaseElementPtr ptr)
{
	if (is_file(ptr))
	{
		return std::static_pointer_cast<StorageFile>(ptr);
	}
	return nullptr;
}
bool is_node(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BE_NODE) == BaseElement::BE_NODE))
		return true;
	return false;
}
StorageNodePtr get_node_unsafe(BaseElementPtr ptr) {
	return std::static_pointer_cast<StorageNode>(ptr->m_exBE);
}
StorageNodePtr get_node(BaseElementPtr ptr)
{
	if (is_node(ptr))
	{
		return std::static_pointer_cast<StorageNode>(ptr->m_exBE);
	}
	return nullptr;
}

static bool is_symbol(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BE_SYMBOL) == BaseElement::BE_SYMBOL))
		return true;
	return false;
}
bool is_edge(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BE_EDGE) == BaseElement::BE_EDGE))
		return true;
	return false;
}
StorageEdgePtr get_edge_unsafe(BaseElementPtr ptr) {
	return std::static_pointer_cast<StorageEdge>(ptr);
}
StorageEdgePtr get_edge(BaseElementPtr ptr)
{
	if (is_edge(ptr))
	{
		return std::static_pointer_cast<StorageEdge>(ptr);
	}
	return nullptr;
}

bool is_symbol_node(BaseElementPtr ptr)
{
	if (ptr != nullptr && ((ptr->m_type & BaseElement::BS_NS) == BaseElement::BS_NS))
		return true;
	return false;
}
StorageSymbolPtr get_symbol_unsafe(BaseElementPtr ptr) {
	return std::static_pointer_cast<StorageSymbol>(ptr);
}
StorageSymbolPtr get_symbol(BaseElementPtr ptr)
{
	if (is_symbol(ptr))
	{
		return std::static_pointer_cast<StorageSymbol>(ptr);
	}
	return nullptr;
}
}	 // namespace UTILS
