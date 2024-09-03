# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        # 결과로 반환할 새로운 루트들의 리스트
        root_list = []

        # 루트가 삭제 리스트에 포함되는지 확인
        if root and root.val in to_delete:
            # 루트가 삭제 리스트에 있으면, 리스트에서 해당 값을 제거
            to_delete.remove(root.val)

            # 루트의 왼쪽 자식이 있고, 그 자식이 삭제 리스트에 없으면 새로운 루트로 추가
            if root.left and root.left.val not in to_delete:
                root_list.append(root.left)

            # 루트의 오른쪽 자식이 있고, 그 자식이 삭제 리스트에 없으면 새로운 루트로 추가
            if root.right and root.right.val not in to_delete:
                root_list.append(root.right)
        elif root:
            # 루트가 삭제되지 않으면, 결과 리스트에 루트를 추가
            root_list = [root]

        # 노드를 탐색할 큐 초기화
        queue = []
        if root.left != None:
            queue.append([root.left, root, 'L'])
            
        if root.right != None:
            queue.append([root.right, root, 'R'])

        # 삭제 리스트가 비어있지 않을 때까지 반복
        while len(to_delete) != 0:
            node, parent, loc = queue.pop(0)  # 큐에서 노드, 부모, 위치(왼쪽/오른쪽)를 가져옴
            
            if node.val in to_delete:
                # 현재 노드가 삭제 리스트에 있으면
                if loc == "L":
                    parent.left = None  # 부모의 왼쪽 자식을 None으로 설정
                else:
                    parent.right = None  # 부모의 오른쪽 자식을 None으로 설정
                
                # 삭제할 노드의 자식들을 새로운 루트로 포함
                if node.left:
                    if node.left.val not in to_delete:
                        root_list.append(node.left)
                    queue.append((node.left, node, 'L'))  # 자식 노드를 큐에 추가
                
                if node.right:
                    if node.right.val not in to_delete:
                        root_list.append(node.right)
                    queue.append((node.right, node, 'R'))  # 자식 노드를 큐에 추가
                
                # 삭제 리스트에서 현재 노드 값을 제거
                to_delete.remove(node.val)
            else:
                # 현재 노드가 삭제 리스트에 없으면, 그 자식들을 큐에 추가
                if node.left != None:
                    queue.append([node.left, node, "L"])
                if node.right != None:
                    queue.append([node.right, node, "R"])

        # 결과 리스트 반환 (남은 트리의 루트들)
        return root_list
