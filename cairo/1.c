#include <cairo.h>

int main() {
    // 创建一个 PNG 图像作为绘制目标
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 200, 200);
    cairo_t *cr = cairo_create(surface);

    // 设置绘制颜色（红色）
    cairo_set_source_rgb(cr, 1, 0, 0);
    
    // 绘制一个圆形
    cairo_arc(cr, 100, 100, 50, 0, 2 * 3.14159);
    cairo_fill(cr);

    // 保存图像
    cairo_surface_write_to_png(surface, "circle.png");

    // 清理资源
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}

