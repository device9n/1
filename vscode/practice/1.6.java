public class StringCompression {

    public static String compress(String str) {
        // 如果字符串为空或长度为0，直接返回原字符串
        if (str == null || str.length() == 0) {
            return str;
        }

        StringBuilder compressed = new StringBuilder();
        int countConsecutive = 0;

        // 遍历字符串
        for (int i = 0; i < str.length(); i++) {
            countConsecutive++;

            // 如果下一个字符与当前字符不同，或者已经是最后一个字符
            if (i + 1 >= str.length() || str.charAt(i) != str.charAt(i + 1)) {
                compressed.append(str.charAt(i));  // 添加当前字符
                compressed.append(countConsecutive);  // 添加当前字符的计数
                countConsecutive = 0;  // 重置计数器
            }
        }

        // 如果压缩后的字符串没有变短，则返回原字符串
        return compressed.length() < str.length() ? compressed.toString() : str;
    }

    public static void main(String[] args) {
        String input = "aabcccccaaa";
        String result = compress(input);
        System.out.println("压缩后的字符串: " + result);
    }
}
