#include"abc_html.h"

typedef struct {
	char** names;
	char*  value;
	int    type;
	int    flags;
} html_attr_t;

typedef struct {
	char**        names;
	int           type;

	int           n_attrs;
	html_attr_t*  attrs;

	uint32_t      flags;
} html_label_t;

#define abc_number_of(__array)  (sizeof(__array) / sizeof(__array[0]))

static char* src_keys[]        = {"src",        "源",       NULL};
static char* href_keys[]       = {"href",       "地址",     NULL};

static char* width_keys[]      = {"width",      "宽度",     NULL};
static char* height_keys[]     = {"height",     "高度",     NULL};

static char* font_keys[]       = {"font",       "字体",     NULL};
static char* font_size_keys[]  = {"font-size",  "字号",     NULL};
static char* font_color_keys[] = {"font-color", "字体颜色", NULL};

static char* type_keys[]       = {"type",       "类型",     NULL};
static char* name_keys[]       = {"name",       "名字",     NULL};
static char* for_keys[]        = {"for",        "关于",     NULL};
static char* id_keys[]         = {"id",         "编号",     NULL};

static char* value_keys[]      = {"value",      "值",       NULL};
static char* action_keys[]     = {"action",     "动作",     NULL};
static char* method_keys[]     = {"method",     "方法",     NULL};

static char* html_keys[]       = {"html",       "网页",     NULL};
static char* head_keys[]       = {"head",       "头部",     NULL};
static char* body_keys[]       = {"body",       "主体",     NULL};
static char* form_keys[]       = {"form",       "表单",     NULL};
static char* div_keys[]        = {"div",        "分区",     NULL};
static char* img_keys[]        = {"img",        "图片",     NULL};

static char* title_keys[]      = {"title",      "标题",     NULL};
static char* input_keys[]      = {"input",      "输入",     NULL};
static char* label_keys[]      = {"label",      "标签",     NULL};

static char* br_keys[]         = {"br",         "换行",     NULL};
static char* h1_keys[]         = {"h1",         "标题1",    NULL};
static char* h2_keys[]         = {"h2",         "标题2",    NULL};
static char* h3_keys[]         = {"h3",         "标题3",    NULL};
static char* h4_keys[]         = {"h4",         "标题4",    NULL};
static char* h5_keys[]         = {"h5",         "标题5",    NULL};
static char* h6_keys[]         = {"h6",         "标题6",    NULL};
static char* p_keys[]          = {"p",          "段落",     NULL};
static char* a_keys[]          = {"a",          "超链接",   NULL};


static html_attr_t  h1_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "40",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  h2_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "32",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  h3_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "28",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  h4_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "24",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  h5_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "20",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  h6_attrs[] =
{
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "16",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  p_attrs[] =
{
	{font_keys,        "SimSong",    ABC_HTML_ATTR_FONT,      0},
	{font_size_keys,   "16",         ABC_HTML_ATTR_FONT_SIZE, 0},
};

static html_attr_t  a_attrs[] =
{
	{href_keys,        "",           ABC_HTML_ATTR_HREF,       ABC_HTML_FLAG_SHOW},
	{font_keys,        "SimHei",     ABC_HTML_ATTR_FONT,       0},
	{font_size_keys,   "24",         ABC_HTML_ATTR_FONT_SIZE,  0},
	{font_color_keys,  "blue",       ABC_HTML_ATTR_FONT_COLOR, 0},
};

static html_attr_t  img_attrs[] =
{
	{src_keys,         "",           ABC_HTML_ATTR_SRC,        ABC_HTML_FLAG_SHOW},
	{width_keys,       "100",        ABC_HTML_ATTR_WIDTH,      ABC_HTML_FLAG_SHOW},
	{height_keys,      "100",        ABC_HTML_ATTR_HEIGHT,     ABC_HTML_FLAG_SHOW},
};

static html_attr_t  input_attrs[] =
{
	{type_keys,        "text",       ABC_HTML_ATTR_TYPE,       ABC_HTML_FLAG_SHOW},
	{id_keys,          "",           ABC_HTML_ATTR_ID,         ABC_HTML_FLAG_SHOW},
	{name_keys,        "",           ABC_HTML_ATTR_NAME,       ABC_HTML_FLAG_SHOW},
	{value_keys,       "",           ABC_HTML_ATTR_VALUE,      ABC_HTML_FLAG_SHOW},

	{font_keys,        "SimSong",    ABC_HTML_ATTR_FONT,       0},
	{font_size_keys,   "16",         ABC_HTML_ATTR_FONT_SIZE,  0},
};

static html_attr_t  label_attrs[] =
{
	{for_keys,         "",           ABC_HTML_ATTR_FOR,        ABC_HTML_FLAG_SHOW},

	{font_keys,        "SimSong",    ABC_HTML_ATTR_FONT,       0},
	{font_size_keys,   "16",         ABC_HTML_ATTR_FONT_SIZE,  0},
};

static html_attr_t  form_attrs[] =
{
	{action_keys,      "/",          ABC_HTML_ATTR_ACTION,     ABC_HTML_FLAG_SHOW},
	{method_keys,      "post",       ABC_HTML_ATTR_METHOD,     ABC_HTML_FLAG_SHOW},

	{font_keys,        "SimSong",    ABC_HTML_ATTR_FONT,       0},
	{font_size_keys,   "16",         ABC_HTML_ATTR_FONT_SIZE,  0},
};

static html_label_t  html_labels[] =
{
	{html_keys,   ABC_HTML,       0, NULL, ABC_HTML_FLAG_CLOSE},
	{title_keys,  ABC_HTML_TITLE, 0, NULL, ABC_HTML_FLAG_CLOSE},
	{head_keys,   ABC_HTML_HEAD,  0, NULL, ABC_HTML_FLAG_CLOSE},
	{body_keys,   ABC_HTML_BODY,  0, NULL, ABC_HTML_FLAG_CLOSE},

	{div_keys,    ABC_HTML_DIV,   0, NULL, ABC_HTML_FLAG_CLOSE},

	{h1_keys,     ABC_HTML_H1,    abc_number_of(h1_attrs),    h1_attrs,    ABC_HTML_FLAG_CLOSE},
	{h2_keys,     ABC_HTML_H2,    abc_number_of(h2_attrs),    h2_attrs,    ABC_HTML_FLAG_CLOSE},
	{h3_keys,     ABC_HTML_H3,    abc_number_of(h3_attrs),    h3_attrs,    ABC_HTML_FLAG_CLOSE},
	{h4_keys,     ABC_HTML_H4,    abc_number_of(h4_attrs),    h4_attrs,    ABC_HTML_FLAG_CLOSE},
	{h5_keys,     ABC_HTML_H5,    abc_number_of(h5_attrs),    h5_attrs,    ABC_HTML_FLAG_CLOSE},
	{h6_keys,     ABC_HTML_H6,    abc_number_of(h6_attrs),    h6_attrs,    ABC_HTML_FLAG_CLOSE},

	{p_keys,      ABC_HTML_P,     abc_number_of(p_attrs),     p_attrs,     ABC_HTML_FLAG_CLOSE},
	{br_keys,     ABC_HTML_BR,    0,                          NULL,        ABC_HTML_FLAG_OPEN},

	{a_keys,      ABC_HTML_A,     abc_number_of(a_attrs),     a_attrs,     ABC_HTML_FLAG_CLOSE},
	{img_keys,    ABC_HTML_IMG,   abc_number_of(img_attrs),   img_attrs,   ABC_HTML_FLAG_CLOSE | ABC_HTML_FLAG_SINGLE},

	{form_keys,   ABC_HTML_FORM,  abc_number_of(form_attrs),  form_attrs,  ABC_HTML_FLAG_CLOSE},
	{input_keys,  ABC_HTML_INPUT, abc_number_of(input_attrs), input_attrs, ABC_HTML_FLAG_OPEN},
	{label_keys,  ABC_HTML_LABEL, abc_number_of(label_attrs), label_attrs, ABC_HTML_FLAG_CLOSE},
};

static int __html_parse_obj(abc_html_t* html, abc_char_t* c);


static html_label_t* __html_find_label(const char* name)
{
	html_label_t* label;

	int i;
	int j;

	for (i = 0; i < sizeof(html_labels) / sizeof(html_labels[0]); i++) {
		label     =       &html_labels[i];

		for (j = 0; label->names[j]; j++) {

			if (!strcmp(label->names[j], name))
				return  label;
		}
	}

	return NULL;
}

static int __html_add_attr(abc_obj_t* obj, int type, char** names, const char* value, int flags)
{
	abc_obj_t* attr = abc_obj_alloc(NULL, 0, 0, type);
	if (!attr)
		return -ENOMEM;

	attr->keys = names;

	attr->value = scf_string_cstr(value);
	if (!attr->value) {
		abc_obj_free(attr);
		return -ENOMEM;
	}

	attr->flags = flags;

	scf_list_add_tail(&obj->attrs, &attr->list);
	return 0;
}

static int __html_load_attrs(abc_obj_t* obj, html_attr_t* attrs, int n_attrs)
{
	scf_list_t* l;
	abc_obj_t*  attr;

	int ret;
	int i;

	if (attrs && n_attrs > 0) {

		for (i = 0; i < n_attrs; i++) {
			ret = __html_add_attr(obj, attrs[i].type, attrs[i].names, attrs[i].value, attrs[i].flags);
			if (ret < 0)
				return ret;
		}

	} else if (obj->parent) {

		for (l   = scf_list_head(&obj->parent->attrs); l != scf_list_sentinel(&obj->parent->attrs); l = scf_list_next(l)) {
			attr = scf_list_data(l, abc_obj_t, list);

			ret = __html_add_attr(obj, attr->type, attr->keys, attr->value->data, 0);
			if (ret < 0)
				return ret;
		}
	}

	return 0;
}

int	abc_html_open(abc_html_t** pp, const char* path)
{
	if (!pp || !path)
		return -EINVAL;

	abc_html_t* html = calloc(1, sizeof(abc_html_t));
	if (!html)
		return -ENOMEM;

	html->fp = fopen(path, "r");
	if (!html->fp) {
		char cwd[4096];
		getcwd(cwd, 4095);
		scf_loge("path: %s, errno: %d, pwd: %s\n", path, errno, cwd);

		free(html);
		return -1;
	}

	html->file = scf_string_cstr(path);
	if (!html->file) {
		fclose(html->fp);
		free(html);
		return -ENOMEM;
	}

	html->n_lines = 1;

	*pp = html;
	return 0;
}

void abc_html_close(abc_html_t* html)
{
	abc_char_t* c;

	if (html) {
		while ( html->tmp_list) {
			c = html->tmp_list;

			html->tmp_list = c->next;
			free(c);
		}

		if (html->root)
			abc_obj_free(html->root);

		if (html->fp)
			fclose(html->fp);

		if (html->file)
			scf_string_free(html->file);

		free(html);
	}
}

static int __html_parse_end(abc_html_t* html, abc_obj_t* obj)
{
	scf_string_t* end = scf_string_alloc();
	if (!end)
		return -ENOMEM;

	abc_char_t* c = NULL;

	while (1) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			scf_string_free(end);
			return -1;
		}

		html->pos += c->len;

		if ('>' == c->c)
			break;

		scf_string_cat_cstr_len(end, c->utf8, c->len);
		free(c);
		c = NULL;
	}

	free(c);
	c = NULL;

	int j;
	for (j = 0; obj->keys[j]; j++) {

		if (!strcmp(obj->keys[j], end->data)) {
			scf_string_free(end);
			return 0;
		}
	}

	scf_loge("end label '%s' file: %s, line: %d, NOT for label '%s' line: %d\n",
			end->data, html->file->data, html->n_lines, obj->keys[0], obj->line);

	scf_string_free(end);
	return -1;
}

static int __html_parse_text(abc_html_t* html, abc_obj_t* obj)
{
	scf_string_t* text = scf_string_alloc();
	if (!text)
		return -ENOMEM;

	abc_char_t* c = NULL;

	while (1) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			scf_string_free(text);
			return -1;
		}

		if ('<' == c->c)
			break;

		if ('\n' == c->c) {
			html->n_lines++;
			html->pos = 0;
		} else {
			html->pos += c->len;
			scf_string_cat_cstr_len(text, c->utf8, c->len);
		}

		free(c);
		c = NULL;
	}

	if (text->len > 0)
		obj->text = text;
	else
		scf_string_free(text);
	text = NULL;


	if (ABC_HTML_FLAG_OPEN == (obj->flags & 0x1)) { // single labels

		__html_push_char(html, c);
		c = NULL;
		return 0;
	};

	html->pos++;
	free(c);
	c = NULL;

	c = __html_pop_char(html);
	if (!c) {
		scf_loge("\n");
		free(c);
		return -1;
	}

	if ('/' != c->c) {
		abc_obj_t* mov = NULL;

		if (ABC_HTML_H1 == obj->type
				|| ABC_HTML_H2 == obj->type
				|| ABC_HTML_H3 == obj->type
				|| ABC_HTML_H4 == obj->type
				|| ABC_HTML_H5 == obj->type
				|| ABC_HTML_H6 == obj->type
				|| ABC_HTML_P  == obj->type) {

			if (obj->text) {
#define HTML_MOV_TEXT() \
				do { \
					mov = abc_obj_alloc(NULL, obj->line, obj->pos, obj->type); \
					if (!mov) \
						return -ENOMEM; \
					mov->text   = obj->text; \
					obj->text   = NULL; \
					mov->parent = obj; \
					scf_list_add_tail(&obj->childs, &mov->list); \
					scf_logd("--- %s, %s\n", obj->key->data, mov->text->data); \
				} while (0)

				HTML_MOV_TEXT();
			}
		}

		int ret = __html_parse_obj(html, c);
		if (ret < 0)
			return ret;

		ret = __html_parse_text(html, obj);
		if (ret < 0)
			return ret;

		if (mov && obj->text)
			HTML_MOV_TEXT();

		return ret;
	}

	html->pos++;
	free(c);
	c = NULL;

	return __html_parse_end(html, obj);
}

static int __html_parse_value(abc_html_t* html, abc_obj_t* attr)
{
	scf_string_t* value = scf_string_alloc();
	if (!value)
		return -ENOMEM;

	abc_char_t* c  = NULL;
	abc_char_t* c2 = NULL;

	int flag = 0;

	while (1) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			scf_string_free(value);
			return -1;
		}

		html->pos += c->len;

		if (!flag) {
			if (' ' == c->c || '>' == c->c)
				break;

			if ('/' == c->c) {
				c2 = __html_pop_char(html);

				__html_push_char(html, c2);
				if ('>' == c2->c)
					break;
			}

			if ('\"' == c->c || '\'' == c->c)
				flag =  c->c;
			else
				scf_string_cat_cstr_len(value, c->utf8, c->len);

		} else if (flag == c->c)
			flag = 0;
		else
			scf_string_cat_cstr_len(value, c->utf8, c->len);

		free(c);
		c = NULL;
	}

	int tmp = c->c;

	free(c);
	c = NULL;

	if (attr->value)
		scf_string_free(attr->value);

	attr->value = value;
	return tmp;
}

static int __html_parse_attr2(abc_html_t* html, abc_obj_t* obj, const html_attr_t* attrs, int n_attrs)
{
	scf_string_t* key = scf_string_alloc();
	if (!key)
		return -ENOMEM;

	abc_char_t* c = NULL;

	while (1) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			scf_string_free(key);
			return -1;
		}

		html->pos += c->len;

		if ('=' == c->c)
			break;

		if ('/' == c->c) {
			free(c);
			scf_string_free(key);
			return '/';
		}

		if ('_' == c->c
				|| '-' == c->c
				|| ('a' <= c->c && 'z' >= c->c))
			scf_string_cat_cstr_len(key, c->utf8, c->len);
		else {
			scf_loge("invalid char '%c' in HTML attribute, file: %s, line: %d\n",
					c->c, html->file->data, html->n_lines);
			free(c);
			scf_string_free(key);
			return -1;
		}

		free(c);
		c = NULL;
	}

	int tmp = c->c;

	free(c);
	c = NULL;

	scf_list_t* l;
	abc_obj_t*  attr;

	for (l   = scf_list_head(&obj->attrs); l != scf_list_sentinel(&obj->attrs); l = scf_list_next(l)) {
		attr = scf_list_data(l, abc_obj_t, list);

		int j;
		for (j = 0; attr->keys[j]; j++) {

			if (!strcmp(attr->keys[j], key->data))
				goto found;
		}
	}

	if (l == scf_list_sentinel(&obj->attrs)) {

		scf_loge("invalid HTML attribute '%s' in file: %s, line: %d\n", key->data, html->file->data, html->n_lines);
		scf_string_free(key);
		return -1;
	}

found:
	scf_string_free(key);
	key = NULL;

	assert(!attr->file);

	attr->file = scf_string_clone(html->file);
	if (!attr->file)
		return -ENOMEM;

	attr->line = html->n_lines;
	attr->pos  = html->pos;

	return __html_parse_value(html, attr);
}

static int __html_parse_attr(abc_html_t* html, abc_obj_t* obj, const html_attr_t* attrs, int n_attrs)
{
	int ret = 0;

	while (1) {
		ret = __html_parse_attr2(html, obj, attrs, n_attrs);
		if (ret < 0)
			return ret;

		if ('>' == ret || '/' == ret)
			break;
	}

	return ret;
}

static int __html_parse_obj(abc_html_t* html, abc_char_t* c)
{
	html_label_t* label;
	abc_obj_t*    obj;

	scf_string_t* key = scf_string_cstr_len(c->utf8, c->len);

	html->pos += c->len;
	free(c);
	c = NULL;

	if (!key)
		return -ENOMEM;

	while (1) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			scf_string_free(key);
			return -1;
		}

		html->pos += c->len;

		if (' ' == c->c || '>' == c->c || '/' == c->c)
			break;

		if ('\n' == c->c) {
			scf_loge("%c:%#x, html->n_lines: %d, pos: %d\n", c->c, c->c, html->n_lines, html->pos);
			free(c);
			return -1;
		}

		scf_string_cat_cstr_len(key, c->utf8, c->len);
		free(c);
		c = NULL;
	}

	int tmp = c->c;

	free(c);
	c = NULL;

	label = __html_find_label(key->data);
	if (!label) {
		scf_loge("invalid HTML label '%s' in file: %s, line: %d\n",
				key->data, html->file->data, html->n_lines);
		scf_string_free(key);
		return -1;
	}

	scf_string_free(key);
	key = NULL;

	obj = abc_obj_alloc(html->file, html->n_lines, html->pos, label->type);
	if (!obj)
		return -ENOMEM;

	obj->flags = label->flags;
	obj->keys  = label->names;

	obj->parent = html->current;

	int ret = __html_load_attrs(obj, label->attrs, label->n_attrs);
	if (ret < 0) {
		abc_obj_free(obj);
		return ret;
	}

	scf_logi("key: %s\n", obj->keys[0]);

	switch (tmp) {
		case ' ':
			ret = __html_parse_attr(html, obj, label->attrs, label->n_attrs);
			if (ret < 0) {
				abc_obj_free(obj);
				return ret;
			}
			break;
		case '/':
			ret = tmp;
			break;
		default:
			ret = 0;
			break;
	};

	if (!html->root) {
		html->root    = obj;
		html->current = obj;
	} else {
		assert(html->current);

		scf_list_add_tail(&html->current->childs, &obj->list);

		html->current = obj;
	}

	if ('/' == ret) {
		c = __html_pop_char(html);
		if (!c) {
			scf_loge("\n");
			return -1;
		}

		int tmp = c->c;

		free(c);
		c = NULL;

		if ('>' != tmp) {
			scf_loge("HTML label '%s' (%d) not closed, in file: %s, line: %d\n",
					obj->keys[0], tmp, html->file->data, html->n_lines);
			return -1;
		}
	} else
		ret = __html_parse_text(html, obj);

	html->current = obj->parent;
	return ret;
}

int abc_html_parse(abc_html_t* html)
{
	abc_char_t* c;

	while (1) {
		c = __html_pop_char(html);
		if (!c)
			return -1;

		if (EOF == c->c) {
			free(c);
			html->current = NULL;
			return 0;
		}

		if ('\n' == c->c) {
			html->n_lines++;
			html->pos = 0;
			continue;
		}

		if ('<' != c->c) {
			scf_loge("%c:%#x, html->n_lines: %d, pos: %d\n", c->c, c->c, html->n_lines, html->pos);
			free(c);
			return -1;
		}

		free(c);

		c = __html_pop_char(html);
		if ('!' == c->c) { // <! note >
			free(c);

			while (1) {
				c = __html_pop_char(html);

				int tmp = c->c;
				free(c);

				if ('>' == tmp)
					break;

				if ('\n' == tmp) {
					scf_loge("%c:%#x, html->n_lines: %d, pos: %d\n", tmp, tmp, html->n_lines, html->pos);
					return -1;
				}
			}

			c = NULL;
			continue;
		}

		if (('a' <= c->c && 'z' >= c->c)
				|| (0x4e00 <= c->c && 0x9fa5 >= c->c)) {

			int ret = __html_parse_obj(html, c);
			if (ret < 0) {
				scf_loge("html->n_lines: %d, pos: %d\n", html->n_lines, html->pos);
				return ret;
			}

		} else {
			scf_loge("%c:%#x, html->n_lines: %d, pos: %d\n", c->c, c->c, html->n_lines, html->pos);
			free(c);
			return -1;
		}
	}

	return -1;
}
