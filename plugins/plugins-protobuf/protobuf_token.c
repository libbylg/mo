#include "protobuf_token.h"


MO_EXTERN short cm[256] = 
{
0                           ,   //  0x00    ???    0
0                           ,   //  0x01    ???    1
0                           ,   //  0x02    ???    2
0                           ,   //  0x03    ???    3
0                           ,   //  0x04    ???    4
0                           ,   //  0x05    ???    5
0                           ,   //  0x06    ???    6
0                           ,   //  0x07    ???    7
0                           ,   //  0x08    ???    8
0                           ,   //  0x09    ???    9
CM_NEWLINE                  ,   //  0x0A    ???   10
0                           ,   //  0x0B    ???   11
0                           ,   //  0x0C    ???   12
0                           ,   //  0x0D    ???   13
0                           ,   //  0x0E    ???   14
0                           ,   //  0x0F    ???   15
0                           ,   //  0x10    ???   16
0                           ,   //  0x11    ???   17
0                           ,   //  0x12    ???   18
0                           ,   //  0x13    ???   19
0                           ,   //  0x14    ???   20
0                           ,   //  0x15    ???   21
0                           ,   //  0x16    ???   22
0                           ,   //  0x17    ???   23
0                           ,   //  0x18    ???   24
0                           ,   //  0x19    ???   25
0                           ,   //  0x1A    ???   26
0                           ,   //  0x1B    ???   27
0                           ,   //  0x1C    ???   28
0                           ,   //  0x1D    ???   29
0                           ,   //  0x1E    ???   30
0                           ,   //  0x1F    ???   31
0                           ,   //  0x20          32
0                           ,   //  0x21    !     33
0                           ,   //  0x22    "     34
0                           ,   //  0x23    #     35
0                           ,   //  0x24    $     36
0                           ,   //  0x25    %     37
0                           ,   //  0x26    &     38
0                           ,   //  0x27    '     39
0                           ,   //  0x28    (     40
0                           ,   //  0x29    )     41
0                           ,   //  0x2A    *     42
0                           ,   //  0x2B    +     43
0                           ,   //  0x2C    ,     44
0                           ,   //  0x2D    -     45
0                           ,   //  0x2E    .     46
0                           ,   //  0x2F    /     47
CM_DEC                      ,   //  0x30    0     48
CM_DEC                      ,   //  0x31    1     49
CM_DEC                      ,   //  0x32    2     50
CM_DEC                      ,   //  0x33    3     51
CM_DEC                      ,   //  0x34    4     52
CM_DEC                      ,   //  0x35    5     53
CM_DEC                      ,   //  0x36    6     54
CM_DEC                      ,   //  0x37    7     55
CM_DEC                      ,   //  0x38    8     56
CM_DEC                      ,   //  0x39    9     57
0                           ,   //  0x3A    :     58
0                           ,   //  0x3B    ;     59
0                           ,   //  0x3C    <     60
0                           ,   //  0x3D    =     61
0                           ,   //  0x3E    >     62
0                           ,   //  0x3F    ?     63
0                           ,   //  0x40    @     64
CM_ALPHA | CM_HEX           ,   //  0x41    A     65
CM_ALPHA | CM_HEX           ,   //  0x42    B     66
CM_ALPHA | CM_HEX           ,   //  0x43    C     67
CM_ALPHA | CM_HEX           ,   //  0x44    D     68
CM_ALPHA | CM_HEX           ,   //  0x45    E     69
CM_ALPHA | CM_HEX           ,   //  0x46    F     70
CM_ALPHA                    ,   //  0x47    G     71
CM_ALPHA                    ,   //  0x48    H     72
CM_ALPHA                    ,   //  0x49    I     73
CM_ALPHA                    ,   //  0x4A    J     74
CM_ALPHA                    ,   //  0x4B    K     75
CM_ALPHA                    ,   //  0x4C    L     76
CM_ALPHA                    ,   //  0x4D    M     77
CM_ALPHA                    ,   //  0x4E    N     78
CM_ALPHA                    ,   //  0x4F    O     79
CM_ALPHA                    ,   //  0x50    P     80
CM_ALPHA                    ,   //  0x51    Q     81
CM_ALPHA                    ,   //  0x52    R     82
CM_ALPHA                    ,   //  0x53    S     83
CM_ALPHA                    ,   //  0x54    T     84
CM_ALPHA                    ,   //  0x55    U     85
CM_ALPHA                    ,   //  0x56    V     86
CM_ALPHA                    ,   //  0x57    W     87
CM_ALPHA                    ,   //  0x58    X     88
CM_ALPHA                    ,   //  0x59    Y     89
CM_ALPHA                    ,   //  0x5A    Z     90
0                           ,   //  0x5B    [     91
0                           ,   //  0x5C    \     92
0                           ,   //  0x5D    ]     93
0                           ,   //  0x5E    ^     94
CM_ALPHA                    ,   //  0x5F    _     95
0                           ,   //  0x60    `     96
CM_ALPHA | CM_HEX           ,   //  0x61    a     97
CM_ALPHA | CM_HEX           ,   //  0x62    b     98
CM_ALPHA | CM_HEX           ,   //  0x63    c     99
CM_ALPHA | CM_HEX           ,   //  0x64    d    100
CM_ALPHA | CM_HEX           ,   //  0x65    e    101
CM_ALPHA | CM_HEX           ,   //  0x66    f    102
CM_ALPHA                    ,   //  0x67    g    103
CM_ALPHA                    ,   //  0x68    h    104
CM_ALPHA                    ,   //  0x69    i    105
CM_ALPHA                    ,   //  0x6A    j    106
CM_ALPHA                    ,   //  0x6B    k    107
CM_ALPHA                    ,   //  0x6C    l    108
CM_ALPHA                    ,   //  0x6D    m    109
CM_ALPHA                    ,   //  0x6E    n    110
CM_ALPHA                    ,   //  0x6F    o    111
CM_ALPHA                    ,   //  0x70    p    112
CM_ALPHA                    ,   //  0x71    q    113
CM_ALPHA                    ,   //  0x72    r    114
CM_ALPHA                    ,   //  0x73    s    115
CM_ALPHA                    ,   //  0x74    t    116
CM_ALPHA                    ,   //  0x75    u    117
CM_ALPHA                    ,   //  0x76    v    118
CM_ALPHA                    ,   //  0x77    w    119
CM_ALPHA                    ,   //  0x78    x    120
CM_ALPHA                    ,   //  0x79    y    121
CM_ALPHA                    ,   //  0x7A    z    122
0                           ,   //  0x7B    {    123
0                           ,   //  0x7C    |    124
0                           ,   //  0x7D    }    125
0                           ,   //  0x7E    ~    126
0                           ,   //  0x7F         127
0                           ,   //  0x80         128
0                           ,   //  0x81         129
0                           ,   //  0x82         130
0                           ,   //  0x83         131
0                           ,   //  0x84         132
0                           ,   //  0x85         133
0                           ,   //  0x86         134
0                           ,   //  0x87         135
0                           ,   //  0x88         136
0                           ,   //  0x89         137
0                           ,   //  0x8A         138
0                           ,   //  0x8B         139
0                           ,   //  0x8C         140
0                           ,   //  0x8D         141
0                           ,   //  0x8E         142
0                           ,   //  0x8F         143
0                           ,   //  0x90         144
0                           ,   //  0x91         145
0                           ,   //  0x92         146
0                           ,   //  0x93         147
0                           ,   //  0x94         148
0                           ,   //  0x95         149
0                           ,   //  0x96         150
0                           ,   //  0x97         151
0                           ,   //  0x98         152
0                           ,   //  0x99         153
0                           ,   //  0x9A         154
0                           ,   //  0x9B         155
0                           ,   //  0x9C         156
0                           ,   //  0x9D         157
0                           ,   //  0x9E         158
0                           ,   //  0x9F         159
0                           ,   //  0xA0         160
0                           ,   //  0xA1         161
0                           ,   //  0xA2         162
0                           ,   //  0xA3         163
0                           ,   //  0xA4         164
0                           ,   //  0xA5         165
0                           ,   //  0xA6         166
0                           ,   //  0xA7         167
0                           ,   //  0xA8         168
0                           ,   //  0xA9         169
0                           ,   //  0xAA         170
0                           ,   //  0xAB         171
0                           ,   //  0xAC         172
0                           ,   //  0xAD         173
0                           ,   //  0xAE         174
0                           ,   //  0xAF         175
0                           ,   //  0xB0         176
0                           ,   //  0xB1         177
0                           ,   //  0xB2         178
0                           ,   //  0xB3         179
0                           ,   //  0xB4         180
0                           ,   //  0xB5         181
0                           ,   //  0xB6         182
0                           ,   //  0xB7         183
0                           ,   //  0xB8         184
0                           ,   //  0xB9         185
0                           ,   //  0xBA         186
0                           ,   //  0xBB         187
0                           ,   //  0xBC         188
0                           ,   //  0xBD         189
0                           ,   //  0xBE         190
0                           ,   //  0xBF         191
0                           ,   //  0xC0         192
0                           ,   //  0xC1         193
0                           ,   //  0xC2         194
0                           ,   //  0xC3         195
0                           ,   //  0xC4         196
0                           ,   //  0xC5         197
0                           ,   //  0xC6         198
0                           ,   //  0xC7         199
0                           ,   //  0xC8         200
0                           ,   //  0xC9         201
0                           ,   //  0xCA         202
0                           ,   //  0xCB         203
0                           ,   //  0xCC         204
0                           ,   //  0xCD         205
0                           ,   //  0xCE         206
0                           ,   //  0xCF         207
0                           ,   //  0xD0         208
0                           ,   //  0xD1         209
0                           ,   //  0xD2         210
0                           ,   //  0xD3         211
0                           ,   //  0xD4         212
0                           ,   //  0xD5         213
0                           ,   //  0xD6         214
0                           ,   //  0xD7         215
0                           ,   //  0xD8         216
0                           ,   //  0xD9         217
0                           ,   //  0xDA         218
0                           ,   //  0xDB         219
0                           ,   //  0xDC         220
0                           ,   //  0xDD         221
0                           ,   //  0xDE         222
0                           ,   //  0xDF         223
0                           ,   //  0xE0         224
0                           ,   //  0xE1         225
0                           ,   //  0xE2         226
0                           ,   //  0xE3         227
0                           ,   //  0xE4         228
0                           ,   //  0xE5         229
0                           ,   //  0xE6         230
0                           ,   //  0xE7         231
0                           ,   //  0xE8         232
0                           ,   //  0xE9         233
0                           ,   //  0xEA         234
0                           ,   //  0xEB         235
0                           ,   //  0xEC         236
0                           ,   //  0xED         237
0                           ,   //  0xEE         238
0                           ,   //  0xEF         239
0                           ,   //  0xF0         240
0                           ,   //  0xF1         241
0                           ,   //  0xF2         242
0                           ,   //  0xF3         243
0                           ,   //  0xF4         244
0                           ,   //  0xF5         245
0                           ,   //  0xF6         246
0                           ,   //  0xF7         247
0                           ,   //  0xF8         248
0                           ,   //  0xF9         249
0                           ,   //  0xFA         250
0                           ,   //  0xFB         251
0                           ,   //  0xFC         252
0                           ,   //  0xFD         253
0                           ,   //  0xFE         254
0                           ,   //  0xFF         255
};
