#ifndef ABC_OBJ_H
#define ABC_OBJ_H

#include"scf_string.h"
#include"scf_list.h"

typedef struct abc_obj_s   abc_obj_t;

enum abc_objs
{
	ABC_HTML,
	ABC_HTML_TITLE,
	ABC_HTML_HEAD,
	ABC_HTML_BODY,

	// 4
	ABC_HTML_DIV,

	// 5
	ABC_HTML_H1,
	ABC_HTML_H2,
	ABC_HTML_H3,
	ABC_HTML_H4,
	ABC_HTML_H5,
	ABC_HTML_H6,

	// 11
	ABC_HTML_P,
	ABC_HTML_BR,

	ABC_HTML_A,
	ABC_HTML_A_HREF,

	// 15
	ABC_HTML_IMG,

	ABC_HTML_FORM,
	ABC_HTML_LABEL,
	ABC_HTML_INPUT,

	ABC_HTML_NB, // total HTML objects

	ABC_HTML_ATTR_ID,
	ABC_HTML_ATTR_TYPE,
	ABC_HTML_ATTR_NAME,
	ABC_HTML_ATTR_VALUE,

	ABC_HTML_ATTR_HREF,
	ABC_HTML_ATTR_SRC,

	ABC_HTML_ATTR_FOR,

	ABC_HTML_ATTR_ACTION,
	ABC_HTML_ATTR_METHOD,

	ABC_HTML_ATTR_FONT,
	ABC_HTML_ATTR_FONT_SIZE,
	ABC_HTML_ATTR_FONT_COLOR,

	ABC_HTML_ATTR_WIDTH,
	ABC_HTML_ATTR_HEIGHT,
};

struct abc_obj_s
{
	scf_list_t      list;

	scf_list_t      attrs;
	scf_list_t      childs;

	abc_obj_t*      parent;

	void*           gtk_builder;

	int             type;

#define ABC_HTML_FLAG_OPEN   0
#define ABC_HTML_FLAG_CLOSE  1
#define ABC_HTML_FLAG_SINGLE 2
#define ABC_HTML_FLAG_SHOW   4
	uint32_t        flags;

	int             x;
	int             y;
	int             w;
	int             h;

	int             progress;
	uint32_t        jiffies; // timeout numbers of sys timer

	char**          keys;
	scf_string_t*   value;
	scf_string_t*   text;

	scf_string_t*   file; // file name
	int             line; // line
	int             pos;  // position

	uint32_t        clicked:1;
};

abc_obj_t*  abc_obj_alloc(scf_string_t* file, int line, int pos, int type);
void        abc_obj_free (abc_obj_t*    obj);
abc_obj_t*  abc_obj_find (abc_obj_t*    root, int x, int y);
void        abc_obj_print(abc_obj_t*    obj);

int         abc_obj_set_attr (abc_obj_t* obj, int key, const char* value);
abc_obj_t*  abc_obj_get_attr (abc_obj_t* obj, int key);
abc_obj_t*  abc_obj_find_attr(abc_obj_t* obj, int key);

#endif
