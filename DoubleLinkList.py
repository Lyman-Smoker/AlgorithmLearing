class Node(object):
    """单链表结点"""
    # 构造函数
    def __init__(self, elem):
        # item存放一个数据
        self.elem = elem
        # next是下一个结点的标识
        self.next = None
        self.prev = None


class DoubleLinkList(object):
    """双链表"""
