#include"abc_html.h"

abc_char_t* __html_pop_char(abc_html_t* html)
{
	assert(html);
	assert(html->fp);

	abc_char_t* c;

	if (html->tmp_list) {
		c              = html->tmp_list;
		html->tmp_list = c->next;
		return c;
	}

	c = malloc(sizeof(abc_char_t));
	if (!c)
		return NULL;

	int ret = fgetc(html->fp);
	if (EOF == ret) {
		c->c = ret;
		return c;
	}

	if (ret < 0x80) {
		c->c   = ret;
		c->len = 1;
		c->utf8[0] = ret;
		return c;
	}

	if (0x6 == (ret >> 5)) {
		c->c   = ret & 0x1f;
		c->len = 2;

	} else if (0xe == (ret >> 4)) {
		c->c   = ret & 0xf;
		c->len = 3;

	} else if (0x1e == (ret >> 3)) {
		c->c   = ret & 0x7;
		c->len = 4;

	} else if (0x3e == (ret >> 2)) {
		c->c   = ret & 0x3;
		c->len = 5;

	} else if (0x7e == (ret >> 1)) {
		c->c   = ret & 0x1;
		c->len = 6;
	} else {
		scf_loge("utf8 first byte wrong %#x, file: %s, line: %d\n", ret, html->file->data, html->n_lines);
		free(c);
		return NULL;
	}

	c->utf8[0] = ret;

	int i;
	for (i = 1; i < c->len; i++) {

		ret = fgetc(html->fp);

		if (0x2  == (ret >> 6)) {
			c->c <<= 6;
			c->c  |= ret & 0x3f;

			c->utf8[i] = ret;
		} else {
			scf_loge("utf8 byte[%d] wrong %#x, file: %s, line: %d\n", i + 1, ret, html->file->data, html->n_lines);
			free(c);
			return NULL;
		}
	}

	return c;
}

void __html_push_char(abc_html_t* html, abc_char_t* c)
{
	assert(html);
	assert(c);

	c->next        = html->tmp_list;
	html->tmp_list = c;
}
