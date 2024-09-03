# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def getDirections(self, root, startValue, destValue):
        """
        :type root: TreeNode
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        # BFS를 위한 큐와 부모 노드를 추적할 딕셔너리 초기화
        queue = [root]
        parents = {root: None}

        startNode = None
        destNode = None

        # BFS를 사용하여 트리를 탐색하면서 시작 노드와 목적지 노드를 찾음
        while queue and (startNode is None or destNode is None):
            node = queue.pop(0)
            if node.val == startValue:
                startNode = node
            if node.val == destValue:
                destNode = node
            
            # 왼쪽 자식이 있으면 부모 노드를 기록하고 큐에 추가
            if node.left:
                parents[node.left] = node
                queue.append(node.left)
            
            # 오른쪽 자식이 있으면 부모 노드를 기록하고 큐에 추가
            if node.right:
                parents[node.right] = node
                queue.append(node.right)
        
        # 시작 노드에서 루트까지의 경로 추적
        startPath = []
        while startNode:
            parent = parents[startNode]
            if parent:
                if parent.left == startNode:
                    startPath.append("L")
                elif parent.right == startNode:
                    startPath.append("R")
            startNode = parent
        startPath.reverse()

        # 목적지 노드에서 루트까지의 경로 추적
        destPath = []
        while destNode:
            parent = parents[destNode]
            if parent:
                if parent.left == destNode:
                    destPath.append("L")
                elif parent.right == destNode:
                    destPath.append("R")
            destNode = parent
        destPath.reverse()

        # 공통된 경로를 제거하여 startPath와 destPath를 최적화
        while startPath and destPath and startPath[0] == destPath[0]:
            startPath.pop(0)
            destPath.pop(0)

        # 최종 경로를 구함
        result = "U" * len(startPath) + "".join(destPath)
        return result
