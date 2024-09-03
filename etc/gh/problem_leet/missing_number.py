def missingNumber(nums):
    n = len(nums)
    total_sum = n * (n + 1) // 2
    array_sum = sum(nums)
    return total_sum - array_sum

# 테스트 케이스
nums = [3, 0, 1]
print(f"Missing Number: {missingNumber(nums)}")  # 출력: 2

nums = [0, 1]
print(f"Missing Number: {missingNumber(nums)}")  # 출력: 2

nums = [9,6,4,2,3,5,7,0,1]
print(f"Missing Number: {missingNumber(nums)}")  # 출력: 8
