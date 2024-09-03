def maxArea(height):
    left = 0
    right = len(height) - 1
    max_area = 0

    while left < right:
        # 현재 영역의 높이와 너비를 계산합니다.
        width = right - left
        current_height = min(height[left], height[right])
        current_area = width * current_height

        # 최대 면적을 갱신합니다.
        max_area = max(max_area, current_area)

        # 더 짧은 쪽의 포인터를 움직입니다.
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area

# 테스트 케이스
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(f"최대 물의 양: {maxArea(height)}")  # 출력: 49
