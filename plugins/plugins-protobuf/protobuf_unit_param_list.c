#include "protobuf.h"
#include "protobuf_token.h"

#include <stdlib.h>

struct protobuf_unit_param_list_t
{
    struct unit_t   super;
    int             state;
};

static mo_action protobuf_unit_param_list_accept(struct unit_t*   n, struct token_t* t)
{
    struct protobuf_unit_param_list_t* u = (struct protobuf_unit_param_list_t*)n;
    switch (u->state)
    {
    case 0: //  等 (
        if ('(' == t->token)
        {
            u->state = 1;
            return MO_ACTION_NEEDMORE;
        }
    break;
    case 1: //  等 NAME
        switch (t->token)
        {
        case MO_TOKEN_NAME:
            mo_push_unit(u->super.mo, protobuf_unit_ref_new());
            u->state = 2;
            return MO_ACTION_RETRY;
        break;
        case ')':
            mo_pop_unit(u->super.mo);
            return MO_ACTION_NEEDMORE;
        }
    break;
    case 2: //  等 ,
        switch (t->token)
        {
        case ',':
            u->state = 1;   //  循环
            return MO_ACTION_NEEDMORE;
        break;
        case ')':
            mo_pop_unit(u->super.mo);
            return MO_ACTION_NEEDMORE;
        break;
        }
    break;
    }

    mo_push_result(u->super.mo, mo_result_new("parser", 111, "%s failed: state=%d, token=%d", __FUNCTION__, u->state, t->token));
    return MO_ACTION_ERROR;
}

MO_EXTERN struct unit_t* protobuf_unit_param_list_new()
{
    struct protobuf_unit_param_list_t* unit = (struct protobuf_unit_param_list_t*)malloc(sizeof(struct protobuf_unit_param_list_t));
    unit->super.size    =   sizeof(struct protobuf_unit_param_list_t);
    unit->super.prev    =   NULL;
    unit->super.mo      =   NULL;
    unit->super.del     =   free;
    unit->super.accept  =   protobuf_unit_param_list_accept;
    unit->state         =   0;
    return (struct unit_t*)(unit);
}




