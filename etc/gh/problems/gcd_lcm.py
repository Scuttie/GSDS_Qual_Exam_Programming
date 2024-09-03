def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

# 사용자 입력
num1 = int(input("첫 번째 숫자를 입력하세요: "))
num2 = int(input("두 번째 숫자를 입력하세요: "))

result_gcd = gcd(num1, num2)
result_lcm = lcm(num1, num2)

print(f"최대공약수(GCD): {result_gcd}")
print(f"최소공배수(LCM): {result_lcm}")
