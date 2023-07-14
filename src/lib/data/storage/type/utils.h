#include<StorageFile.h>
#include<StorageNode.h>
#include<StorageSymbol.h>
#include<StorageEdge.h>

#ifndef STORAGE_UTILS_H
#define STORAGE_UTILS_H
namespace UTILS
{
	bool is_file(BaseElementPtr ptr);
	bool is_file_node(BaseElementPtr ptr);
	StorageFilePtr get_file(BaseElementPtr ptr);
	StorageFilePtr get_file_unsafe(BaseElementPtr ptr);

	bool is_node(BaseElementPtr ptr);
	StorageNodePtr get_node(BaseElementPtr ptr);
	StorageNodePtr get_node_unsafe(BaseElementPtr ptr);

	bool is_symbol(BaseElementPtr ptr);
	bool is_symbol_node(BaseElementPtr ptr);
	StorageSymbolPtr get_symbol(BaseElementPtr ptr);
	StorageSymbolPtr get_symbol_unsafe(BaseElementPtr ptr);

	bool is_edge(BaseElementPtr ptr);
	StorageEdgePtr get_edge(BaseElementPtr ptr);
	StorageEdgePtr get_edge_unsafe(BaseElementPtr ptr);
}
#endif	  // STORAGE_UTILS_H