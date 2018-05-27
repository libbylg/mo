#include "mo.h"


#include <stdlib.h>




struct sytx_t;




struct mo_t
{
    struct lex_t*       lex;
    struct sytx_t*      sytx;
    struct result_t*    result;
};




struct sytx_t
{
    struct unit_t*      unit_top;
};



MO_EXTERN   struct mo_t*        mo_new          ()
{
    struct mo_t* mo = (struct mo_t*)malloc(sizeof(struct mo_t));
    mo->lex     =   NULL;
    mo->sytx    =   (struct sytx_t*)malloc(sizeof(struct sytx_t));
    mo->result  =   NULL;
    return mo;
}




MO_EXTERN   void                mo_del          (struct mo_t* mo)
{
    free(mo);
}




MO_EXTERN   void                mo_reg_lex      (struct mo_t* mo, struct lex_t*    x)
{
    mo->lex = x;
}




MO_EXTERN   void                mo_reg_result   (struct mo_t* mo, struct result_t* r)
{
    mo->result = r;
}




MO_EXTERN   void                mo_push_stream  (struct mo_t* mo, struct stream_t* m)
{
    m->parent          = mo->sytx->unit_top;
    mo->sytx->unit_top = m;
}




MO_EXTERN   void                mo_push_unit    (struct mo_t* mo, struct unit_t*   u)
{
    u->parent = mo->sytx->unit_top;
    mo->sytx->unit_top = u;
}




MO_EXTERN   mo_errno            mo_walk(struct mo_t* mo)
{
    mo_action action = MO_ACTION_TRYAGAIN;
    mo_token  token  = MO_TOKEN_ERROR;
    
READ_MORE:
    token = (*(mo->lex->next))(mo->lex, x->token);
    if (MO_TOKEN_ERROR == token)
    {
        return 111;
    }

TRYAGAIN:
    action = (*(y->unit_top->accept))(y->unit_top->ctx, y, x->token);
    if (MO_ACTION_NEEDMORE == action)
    {
        ///!    都没没数据了，还在请求更多token，一定是bug了
        if (MO_TOKEN_EOF == token)
        {
            return 111;
        }
        
        goto READ_MORE;
    }

    if (MO_ACTION_TRYAGAIN == action)
    {
        ///!    所有的数据接收完毕，且刚好识别完毕
        if (MO_TOKEN_EOF == token)
        {
            return 0;
        }
        
        goto TRYAGAIN;
    }
    
    //if (MO_ACTION_ERROR == action)
    {
        //  TODO 遇到accept识别错误
        return 111;
    }
    
    
}



