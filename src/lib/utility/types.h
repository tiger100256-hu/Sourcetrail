#ifndef TYPES_H
#define TYPES_H

#include <cstddef>
#include <memory>
typedef uint32_t Id;
class BaseElement;
using BaseElementPtr = std::shared_ptr<BaseElement>;

class BaseElement
: public std::enable_shared_from_this<BaseElement> {
public:

	enum BE_TYPE {
		BE_NONE = 0,
		BE_FILE = 1 << 0,
		BE_SYMBOL = 1 << 1,
		BE_NODE = 1 << 2,
		BE_EDGE = 1 << 3,
		BS_NS  = BE_NODE | BE_SYMBOL,
		BS_NF  = BE_NODE | BE_FILE,
		BE_LOCALSYMBOL  = 1 << 4,
	} ;
	virtual ~BaseElement() = default;
	uint8_t m_type = BE_NONE;
	BaseElementPtr m_exBE;
};


#endif	  // TYPES_H
