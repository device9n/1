#include"abc_obj.h"

abc_obj_t*	abc_obj_alloc(scf_string_t* file, int line, int pos, int type)
{
	abc_obj_t* obj = calloc(1, sizeof(abc_obj_t));
	if (!obj)
		return NULL;

	if (file) {
		obj->file = scf_string_clone(file);

		if (!obj->file) {
			free(obj);
			return NULL;
		}
	}

	scf_list_init(&obj->list);
	scf_list_init(&obj->attrs);
	scf_list_init(&obj->childs);

	obj->type = type;

	obj->line = line;
	obj->pos  = pos;

	return obj;
}

void abc_obj_free(abc_obj_t* obj)
{
	if (obj) {
		if (obj->value)
			scf_string_free(obj->value);

		if (obj->text)
			scf_string_free(obj->text);

		if (obj->file)
			scf_string_free(obj->file);

		scf_list_clear(&obj->attrs,  abc_obj_t, list, abc_obj_free);
		scf_list_clear(&obj->childs, abc_obj_t, list, abc_obj_free);

		free(obj);
	}
}

abc_obj_t* abc_obj_find(abc_obj_t* root, int x, int y)
{
	scf_list_t* l;
	abc_obj_t*  child;
	abc_obj_t*  obj;

	if (x < root->x
			|| x > root->x + root->w
			|| y < root->y
			|| y > root->y + root->h)
		return NULL;

	for (l    = scf_list_head(&root->childs); l != scf_list_sentinel(&root->childs); l = scf_list_next(l)) {
		child = scf_list_data(l, abc_obj_t, list);

		obj = abc_obj_find(child, x, y);
		if (obj)
			return obj;
	}

	return root;
}

int abc_obj_set_attr(abc_obj_t* obj, int key, const char* value)
{
	scf_string_t* s;
	scf_list_t*   l;
	abc_obj_t*    attr;

	for (l   = scf_list_head(&obj->attrs); l != scf_list_sentinel(&obj->attrs); l = scf_list_next(l)) {
		attr = scf_list_data(l, abc_obj_t, list);

		if (attr->type == key) {
			s = scf_string_cstr(value);
			if (s) {
				scf_string_free(attr->value);
				attr->value = s;
				return 0;
			}
			return -ENOMEM;
		}
	}

	return -EINVAL;
}

abc_obj_t* abc_obj_get_attr(abc_obj_t* obj, int key)
{
	scf_list_t*   l;
	abc_obj_t*    attr;

	for (l   = scf_list_head(&obj->attrs); l != scf_list_sentinel(&obj->attrs); l = scf_list_next(l)) {
		attr = scf_list_data(l, abc_obj_t, list);

		if (attr->type == key)
			return attr;
	}

	return NULL;
}

abc_obj_t* abc_obj_find_attr(abc_obj_t* obj, int key)
{
	abc_obj_t* attr;

	while (obj) {
		attr = abc_obj_get_attr(obj, key);
		if (attr)
			return attr;

		obj = obj->parent;
	}

	return NULL;
}

void abc_obj_print(abc_obj_t* obj)
{
	scf_list_t*   l;
	abc_obj_t*    attr;
	abc_obj_t*    child;

	if (!obj)
		return;

	if (obj->value)
		printf(" %s=\"%s\"", obj->keys[0], obj->value->data);
	else if (obj->keys)
		printf("<%s", obj->keys[0]);


	for (l = scf_list_head(&obj->attrs); l != scf_list_sentinel(&obj->attrs); l = scf_list_next(l)) {
		attr = scf_list_data(l, abc_obj_t, list);

		if (ABC_HTML_FLAG_SHOW & attr->flags)
			abc_obj_print(attr);
	}

	if (!obj->value) {
		if (obj->flags & ABC_HTML_FLAG_SINGLE)
			printf(" />\n");
		else if (obj->keys)
			printf(">\n");
	}

	if (obj->text)
		printf("%s\n", obj->text->data);

	for (l = scf_list_head(&obj->childs); l != scf_list_sentinel(&obj->childs); l = scf_list_next(l)) {
		child = scf_list_data(l, abc_obj_t, list);

		abc_obj_print(child);
	}

	if (ABC_HTML_FLAG_CLOSE == (obj->flags & (ABC_HTML_FLAG_CLOSE | ABC_HTML_FLAG_SINGLE))) {
		if (obj->keys)
			printf("</%s>\n", obj->keys[0]);
	}
}
