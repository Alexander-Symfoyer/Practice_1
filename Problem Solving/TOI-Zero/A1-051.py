text = input()
k = int(input())
result = ""
for char in text:
    new_char = chr((ord(char) - 97 + k) % 26 + 97)
    result += new_char
print(result)