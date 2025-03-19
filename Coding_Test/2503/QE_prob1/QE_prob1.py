def read_meetings_from_file(filename):
   # 파일을 열어서 각 줄을 읽어온 뒤, 각 줄을 (시작 시간, 종료 시간) 형태의 튜플로 파싱하여 반환
   file = open(filename, "r")
   contents = file.readlines()
   file.close()
   final_result = []
   for content in contents:
      result = []
      for time in content.split(" "):
         # 개행 문자(\n)가 들어 있으면 제거해줌
         if "\n" in time:
               result.append(time.split("\n")[0])
         else:
               result.append(time)
      # 한 줄(예: "09:00 09:30")에서 뽑아낸 start, end 시간을 튜플로 묶어서 리스트에 추가
      final_result.append(tuple(result))
   return final_result

def min_meeting_rooms(meetings):
   # 최종 결과(회의실 배정 목록들)를 저장할 리스트
   result = []

   # 아직 회의실에 배정되지 않은 회의들을 저장
   remain = meetings

   # chain: 현재 '같은 회의실'에 계속 이어 붙일(연결할) 수 있는 상태인지 여부
   chain = False

   # 필요한 회의실의 최소 개수를 셀 변수
   chain_count = 1

   # 모든 회의(remain)가 소진될 때까지 반복
   while len(remain) > 0:
      if chain == False:
         # 새 회의실(새로운 체인)을 시작할 경우
         chain_list = []

         # 가장 빨리 끝나는(끝 시각이 가장 이른) 회의를 찾기 위한 임시 변수
         earliest = "ZZZ"  # 문자열 비교에서 "ZZZ"는 매우 뒤에 위치하므로 초기값으로 사용
         earliest_ending_meeting = (0, 0)

         # 아직 배정되지 않은 회의들 중에서 가장 빨리 끝나는 회의를 찾는다
         for times in sorted(remain):
               if earliest > times[-1]:
                  earliest = times[-1]
                  earliest_ending_meeting = times

         # 찾은 회의를 새로운 체인에 넣고 remain에서 제거
         chain_list.append(earliest_ending_meeting)
         remain.remove(earliest_ending_meeting)

         # 만약 제거 후에 남은 회의가 없다면, 결과에 이 체인을 넣고 종료
         if (len(remain) == 0):
               result.append(chain_list)

         # 이제 'chain'을 True로 전환하여, 같은 회의실에 이어 붙일 수 있는지 시도
         chain = True
      else:
         # 이미 체인을 진행하고 있다면, 체인 목록의 마지막 회의의 종료 시각을 구한다
         last_time_end = chain_list[-1][-1]

         # 다음으로 배정할(이어 붙일) 회의를 찾는다: 시작 시각이 last_time_end 이후인 것 중 가장 빠른 것
         earliest = "ZZZ"
         earliest_meeting = (0, 0)

         for times in remain:
               # 마지막 회의 종료 시각 < 다음 회의 시작 시각인 경우에만 배정 가능
               if last_time_end < times[0]:
                  # 시작 시각이 가장 빠른(earliest) 회의를 찾음
                  if times[0] < earliest:
                     earliest = times[0]
                     earliest_meeting = times

         # 만약 이어붙일 수 있는 회의를 찾지 못했다면, 새로운 회의실 체인을 만들어야 함
         if earliest == "ZZZ":
               chain = False
               chain_count += 1  # 회의실 하나 더 필요
               result.append(chain_list)  # 지금까지 만든 체인을 결과에 저장
         else:
               # 찾았다면, 해당 회의를 지금 체인에 추가하고 remain에서 제거
               chain_list.append(earliest_meeting)
               remain.remove(earliest_meeting)

               # 제거 후 remain이 비었다면 현재 체인을 결과에 넣어줌
               if (len(remain) == 0):
                   result.append(chain_list)

   # (필요 회의실 개수, 각 체인 목록(회의실별 할당 목록)) 형태로 반환
   return (chain_count, sorted(result))
