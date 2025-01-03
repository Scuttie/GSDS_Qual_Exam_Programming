import heapq
from typing import List

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        """
        이 함수는 주어진 차량의 좌석 수(capacity)와 여러 여행(trips)에 따라 모든 승객을 태우고 내릴 수 있는지 여부를 판단합니다.
        차량은 동쪽으로만 이동할 수 있으며, 서쪽으로 돌아갈 수 없습니다.
        
        trips[i] = [numPassengersi, fromi, toi]는 i번째 여행에 numPassengersi명의 승객이 fromi 지점에서
        탑승하여 toi 지점에서 하차함을 나타냅니다.
        
        모든 여행을 수행하면서 차량의 좌석 수를 초과하지 않으면 True를, 그렇지 않으면 False를 반환합니다.
        """
        
        # 이벤트를 저장할 리스트 초기화
        # 각 이벤트는 (위치, 승객 변화) 형태로 저장됨
        events = []
        
        # 모든 여행에 대해 승객 변화 이벤트를 생성
        for trip in trips:
            num_passengers, start, end = trip
            # 승객 탑승: 시작 지점에서 승객 수 증가
            events.append((start, num_passengers))
            # 승객 하차: 종료 지점에서 승객 수 감소
            events.append((end, -num_passengers))
        
        # 이벤트를 위치 기준으로 정렬
        # 위치가 같은 경우, 하차 이벤트(-num_passengers)가 탑승 이벤트(num_passengers)보다 먼저 처리되도록 함
        events.sort(key=lambda x: (x[0], x[1]))
        
        current_passengers = 0  # 현재 차량에 탑승한 승객 수
        
        # 모든 이벤트를 순회하며 승객 수를 업데이트
        for location, passenger_change in events:
            current_passengers += passenger_change  # 승객 변화 적용
            
            # 현재 승객 수가 차량의 좌석 수를 초과하면 False 반환
            if current_passengers > capacity:
                return False
        
        # 모든 이벤트를 처리한 후에도 좌석 수를 초과하지 않으면 True 반환
        return True
