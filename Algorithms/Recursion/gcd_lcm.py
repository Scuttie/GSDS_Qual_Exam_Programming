def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return abs(a * b) // gcd(a, b)

# Example usage
print(gcd(48, 18))  # Output: 6
print(lcm(12, 18))  # Output: 36
