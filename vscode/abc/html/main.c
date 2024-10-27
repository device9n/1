#include"abc_html.h"

int main(int argc, char* argv[])
{
	abc_html_t* html = NULL;

	if (argc < 2) {
		scf_loge("\n");
		return -1;
	}

	if (abc_html_open(&html, argv[1]) < 0) {
		scf_loge("\n");
		return -1;
	}

	if (abc_html_parse(html) < 0) {
		scf_loge("\n");
		return -1;
	}

	printf("\n");

	if (html->root)
		abc_obj_print(html->root);

	printf("\n");

	scf_logi("main ok\n");
	return 0;
}
