def is_palindrome(s, start, end):
    if start >= end:
        return True
    if s[start] != s[end]:
        return False
    return is_palindrome(s, start + 1, end - 1)

# Example usage
string = "madam"
print(is_palindrome(string, 0, len(string) - 1))  # Output: True
