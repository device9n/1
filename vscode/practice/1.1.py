def all_unique_charcters(s: str) -> bool:
    #使用集合来储存已经遇到的字符
    seen_charcters = set()

    for char in s:
        if char in seen_charcters:
            return False
        
        seen_charcters.add(char)

    return True

s = "abcdefgg"
print(all_unique_charcters(s))
s = "abcdefg"
print(all_unique_charcters(s))



def all_unique_charcters_sorted(s: str)-> bool:
    sorted_s = sorted(s)

    for i in range (1, len(sorted_s)):
        if sorted_s[i] == sorted_s[i - 1]:
            return False
    
    return True

s = "abcdefgg"
print(all_unique_charcters_sorted(s))
s = "abcdefg"
print(all_unique_charcters_sorted(s))