from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        이 함수는 두 개의 정수 배열 nums1과 nums2가 주어졌을 때, nums1의 각 요소에 대해 nums2에서의 다음 큰 요소를 찾아 반환합니다.
        nums1은 nums2의 부분집합이며, 각 숫자는 고유합니다.
        
        다음 큰 요소는 nums2에서 현재 요소의 오른쪽에 있는 첫 번째로 큰 요소를 의미합니다. 
        만약 그런 요소가 없다면 -1을 반환합니다.
        
        이 함수는 O(n) 시간 복잡도로 효율적으로 문제를 해결하기 위해 스택과 해시 맵을 사용합니다.
        
        Parameters:
        - nums1 (List[int]): 결과를 찾을 대상 배열 (nums2의 부분집합)
        - nums2 (List[int]): 참조 배열
        
        Returns:
        - List[int]: nums1의 각 요소에 대한 다음 큰 요소의 배열
        """
        
        # 결과를 저장할 해시 맵: 각 숫자에 대한 다음 큰 숫자를 저장
        next_greater = {}
        stack = []  # 스택을 사용하여 다음 큰 요소를 효율적으로 찾음
        
        # nums2를 순회하면서 각 숫자에 대한 다음 큰 숫자를 찾습니다.
        for num in nums2:
            # 스택이 비어있지 않고, 현재 숫자가 스택의 마지막 숫자보다 클 경우
            while stack and num > stack[-1]:
                prev_num = stack.pop()
                next_greater[prev_num] = num  # 이전 숫자의 다음 큰 숫자를 현재 숫자로 설정
            stack.append(num)  # 현재 숫자를 스택에 추가
        
        # 스택에 남아있는 숫자들은 다음 큰 숫자가 없으므로 -1로 설정
        while stack:
            prev_num = stack.pop()
            next_greater[prev_num] = -1
        
        # nums1의 각 숫자에 대해 해시 맵에서 다음 큰 숫자를 찾아 결과 배열에 추가
        result = [next_greater[num] for num in nums1]
        
        return result

# 테스트를 위한 메인 함수 (선택 사항)
if __name__ == "__main__":
    solution = Solution()
    
    # 예제 1
    nums1_1 = [4,1,2]
    nums2_1 = [1,3,4,2]
    print(f"Input: nums1 = {nums1_1}, nums2 = {nums2_1}")
    print(f"Output: {solution.nextGreaterElement(nums1_1, nums2_1)}")  # 예상 출력: [-1,3,-1]
    
    # 예제 2
    nums1_2 = [2,4]
    nums2_2 = [1,2,3,4]
    print(f"\nInput: nums1 = {nums1_2}, nums2 = {nums2_2}")
    print(f"Output: {solution.nextGreaterElement(nums1_2, nums2_2)}")  # 예상 출력: [3,-1]
    
    # 추가 테스트 케이스 1
    nums1_3 = [1,3,5]
    nums2_3 = [6,5,4,3,2,1]
    print(f"\nInput: nums1 = {nums1_3}, nums2 = {nums2_3}")
    print(f"Output: {solution.nextGreaterElement(nums1_3, nums2_3)}")  # 예상 출력: [-1,-1,-1]
    
    # 추가 테스트 케이스 2
    nums1_4 = [1,2,3]
    nums2_4 = [1,2,3,4]
    print(f"\nInput: nums1 = {nums1_4}, nums2 = {nums2_4}")
    print(f"Output: {solution.nextGreaterElement(nums1_4, nums2_4)}")  # 예상 출력: [2,3,4]
    
    # 추가 테스트 케이스 3
    nums1_5 = [3,1,4,2]
    nums2_5 = [1,3,2,4]
    print(f"\nInput: nums1 = {nums1_5}, nums2 = {nums2_5}")
    print(f"Output: {solution.nextGreaterElement(nums1_5, nums2_5)}")  # 예상 출력: [4,-1, -1,-1]
