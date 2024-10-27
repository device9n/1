// 从 Deno 标准库中导入 serve 函数
import { serve } from "https://deno.land/std@latest/http/server.ts";

// 定义要监听的端口
const port = 8000;

// 创建服务器
const server = serve({ port });

console.log(`服务器正在运行在 http://localhost:${port}/`);

// 处理传入的请求
for await (const request of server) {
    request.respond({ body: "Hello, Deno!\n" });
}
