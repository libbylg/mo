#ifndef __mo_
#define __mo_




#if defined(__cplusplus)
#define MO_EXTERN  extern  "C"
#else
#define MO_EXTERN  extern
#endif//




#ifndef NULL
#if defined(__cplusplus)
#define NULL    (void*)(0)
#else
#define NULL    (0)
#endif
#endif


#define MO_ASSERT(expr,msg) assert()


typedef int             mo_bool;
typedef int             mo_errno;
typedef unsigned char   mo_byte;
typedef unsigned int    mo_cm;


#define MO_FALSE        (!!0)
#define MO_TRUE         (!0)


struct token_t;
struct lex_t;
struct stream_t;


//  用于result
#define MO_OK               (0)



//  释放对象的接口
typedef     void        (*MO_DEL_CALLBACK   )(void* obj);


//  读取数据的返回值定义
#define MO_READ_OK      (0)
#define MO_READ_EOF     (1)
#define MO_READ_ERROR   (2)
typedef     int         (*MO_READ_CALLBACK  )(void* ctx, char** pos, char* end);
typedef     void        (*MO_CLOSE_CALLBACK )(void* ctx);


//  几个内定的词法编号
#define     MO_TOKEN_UNKNOWN    (-1)
#define     MO_TOKEN_EOF        (-2)
#define     MO_TOKEN_ERROR      (-3)
typedef     struct token_t*     (*MO_NEXT_CALLBACK  )(struct lex_t* x, struct token_t* t);


//  对象
struct object_t
{
    void*               prev;
    int                 typeid;
};


//  类（注意，类也是一个对象）
struct class_t
{
    void*               prev;
    int                 typeid;
    char                name[64];
    MO_DEL_CALLBACK     del;
};


//  类型定义宏
#define MO_DEFINE(cls_name, body)  \
    cls_name{                   \
        void*   prev;           \
        int     typeid;         \
        struct  body;           \
    }


//  词法识别出来的符号
MO_DEFINE(struct token_t,
{
    int                 size;       //  整个token所占的存储空间
    int                 id;         //  符号的类型编号
    int                 opts;       //  选项
    union 
    {
        struct 
        {
            char        text[64];    //  符号的文本范围
        };
        struct 
        {
            char*       ref[2];     //  符号的文本范围
        };
        struct
        {
            int         error;      //  错误码
            char        desc[500];  //  错误描述
        };
    };
});


//  词法定位信息
struct anchor_t
{
    char*               name;   //  名称
    int                 lino;   //  行号
    char*               line;   //  行起始位置（用于计算当前处于当前行的那一列）
};


//  输入流对象
MO_DEFINE(struct stream_t,
{
    void*               prev;   //  前一个流对象
    int                 typeid;
    struct anchor_t     anchor; //  词法识别的锚点信息
    void*               ctx;    //  流对象的上下文
    MO_CLOSE_CALLBACK   close;  //  流关闭函数
    MO_READ_CALLBACK    read;   //  流读取函数
});



//  词法分析对象
MO_DEFINE(struct lex_t,
{
    void*               prev;       //  前一个词法对象
    int                 typeid;     //  对象类型编号
    //
    void*               ctx;        //  词法识别的上下文
    MO_NEXT_CALLBACK    next;       //  词法识别的函数
    //
    struct token_t*     token;      //  最近识别出来的一个符号
    struct stream_t*    stream;     //  输入流
    struct anchor_t*    anchor;     //  词法定位信息(直接引用自 stream 对象)
    //
    int                 rsrv;       //  预留大小
    int                 cap;        //  数据缓冲区的总容量（总是等于：limit - buf）
    char*               pos;        //  当前识别位置指针
    char*               end;        //  有效数据结束位置，*end永远是\n
    char*               limit;      //  缓冲区结尾
    mo_byte*            buf;        //  数据缓冲区
});


//  默认的字符映射对象
#define MO_CM_DEC                  (0x01000000)
#define MO_CM_HEX                  (0x02000000)
#define MO_CM_OCT                  (0x04000000)
#define MO_CM_NEWLINE              (0x08000000)
#define MO_CM_SPACE                (0x10000000)
#define MO_CM_ALPHA                (0x20000000)
#define MO_CM_STRING_FLAG          (0x40000000)
#define MO_CM_COMMENT_FLAG         (0x80000000)
MO_EXTERN   mo_cm*              mo_cms_default();


//  注册类
MO_EXTERN   int                 mo_define_class         (char* name, MO_DEL_CALLBACK del);
MO_EXTERN   struct class_t*     mo_class_of             (int typeid);
MO_EXTERN   int                 mo_typeid_of            (char* name);
MO_EXTERN   void                mo_object_del           (void* obj);


MO_EXTERN   struct token_t*     mo_token_new            ();
MO_EXTERN   struct token_t*     mo_token_clear          (struct token_t* k);
MO_EXTERN   struct token_t*     mo_token_errorf         (struct token_t* k, int error, char* format, ...);

//  词法识别的接口
MO_EXTERN   struct stream_t*    mo_stream_new           (void* ctx, MO_READ_CALLBACK   read, MO_CLOSE_CALLBACK close);
MO_EXTERN   struct lex_t*       mo_lex_new              (void* ctx, MO_NEXT_CALLBACK   next, int cap, int rsrv);
MO_EXTERN   void                mo_lex_push_stream      (struct lex_t* x, struct stream_t* m);
MO_EXTERN   struct stream_t*    mo_lex_pop_stream       (struct lex_t* x);
MO_EXTERN   struct token_t*     mo_lex_next_token       (struct lex_t* x, struct token_t* k);
MO_EXTERN   void                mo_lex_push_back        (struct lex_t* x, struct token_t* k);




#endif//__mo_


