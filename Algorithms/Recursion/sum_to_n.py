def sum_to_n(n):
    if n <= 1:
        return n
    return n + sum_to_n(n - 1)

# Example usage
print(sum_to_n(5))  # Output: 15
