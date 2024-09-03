def maxProduct(nums):
    if not nums:
        return 0

    max_so_far = nums[0]
    min_so_far = nums[0]
    result = nums[0]

    for i in range(1, len(nums)):
        num = nums[i]

        # 음수가 포함된 경우, min_so_far와 max_so_far를 교환
        if num < 0:
            max_so_far, min_so_far = min_so_far, max_so_far

        max_so_far = max(num, max_so_far * num)
        min_so_far = min(num, min_so_far * num)

        result = max(result, max_so_far)

    return result

# 테스트 케이스
arr = [2, 3, -2, 4]
print(f"최대 부분 배열 곱: {maxProduct(arr)}")  # 출력: 6

arr = [-2, 0, -1]
print(f"최대 부분 배열 곱: {maxProduct(arr)}")  # 출력: 0
