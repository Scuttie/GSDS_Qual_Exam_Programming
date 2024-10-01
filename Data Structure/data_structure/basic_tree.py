class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root_data):
        self.root = TreeNode(root_data)

    def insert_left(self, current_node, data):
        if current_node.left is None:
            current_node.left = TreeNode(data)
        else:
            new_node = TreeNode(data)
            new_node.left = current_node.left
            current_node.left = new_node

    def insert_right(self, current_node, data):
        if current_node.right is None:
            current_node.right = TreeNode(data)
        else:
            new_node = TreeNode(data)
            new_node.right = current_node.right
            current_node.right = new_node

    def inorder_traversal(self, node):
        if node is not None:
            self.inorder_traversal(node.left)
            print(node.data, end=' ')
            self.inorder_traversal(node.right)

    def preorder_traversal(self, node):
        if node is not None:
            print(node.data, end=' ')
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)

    def postorder_traversal(self, node):
        if node is not None:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.data, end=' ')

# 사용 예시
if __name__ == "__main__":
    bt = BinaryTree(1)
    bt.insert_left(bt.root, 2)
    bt.insert_right(bt.root, 3)
    bt.insert_left(bt.root.left, 4)
    bt.insert_right(bt.root.left, 5)

    print("Inorder traversal:")
    bt.inorder_traversal(bt.root)  # 출력: 4 2 5 1 3

    print("\nPreorder traversal:")
    bt.preorder_traversal(bt.root)  # 출력: 1 2 4 5 3

    print("\nPostorder traversal:")
    bt.postorder_traversal(bt.root)  # 출력: 4 5 2 3 1
