#ifndef __protobuf_lex_
#define __protobuf_lex_


#include "mo.h"


struct protobuf_lex_t
{
    struct lex_t    super;
};

MO_EXTERN   struct lex_t* protobuf_lex_new(int init_cache_size);



#endif//__protobuf_lex_

