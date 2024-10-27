#ifndef ABC_HTML_H
#define ABC_HTML_H

#include "abc_obj.h"

typedef struct abc_char_s  abc_char_t;
typedef struct abc_html_s  abc_html_t;

#define ABC_UTF_MAX 6
struct abc_char_s
{
    abc_char_t*     next;
    int             c;

    int             len;
    uint8_t         utf8[ABC_UTF_MAX];
};

struct abc_html_s
{
    scf_list_t      list;

    abc_char_t*     tmp_list;

    abc_obj_t*      root;
    abc_obj_t*      current;

    FILE*           fp;

    scf_string_t*   file;
    int             n_lines;
    int             pos;     
};

int abc_html_open   (abc_html_t** pp, const char* path);
void abc_html_close (abc_html_t* html);

int abc_html_parse  (abc_html_t* html);

abc_char_t*     __html_pop_char (abc_html_t* html);
void            __html_push_char(abc_html_t* html, abc_char_t* c);



#endif