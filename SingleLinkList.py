# coding:utf-8
# 单链表
class Node(object):
    """单链表结点"""
    # 构造函数
    def __init__(self, elem):
        # item存放一个数据
        self.elem = elem
        # next是下一个结点的标识
        self.next = None


class SingleLinkList(object):
    """单链表"""

    def __init__(self, node=None):
        # 加下划线表示私有变量
        self._head = node

    def is_empty(self):
        """链表是否为空"""
        return self._head is None

    def length(self):
        """链表长度"""
        cur = self._head
        count = 0
        while cur is not None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        """遍历整个链表"""
        cur = self._head
        while cur is not None:
            print(cur.elem, end=" ")
            cur = cur.next
        print()

    def add(self, item):
        """链表头部增加元素"""
        node = Node(item)
        node.next = self._head
        self._head = node

    def append(self, item):
        """链表尾部增加元素"""
        node = Node(item)
        if self.is_empty():
            self._head = node
        else:
            cur = self._head
            while cur.next is not None:
                cur = cur.next
            cur.next = node

    def insert(self, pos, item):
        """
            指定位置增加元素
            pos 是插入位置，从0开始
        """
        if pos <= 0:
            self.add(item)
            return
        elif pos > (self.length()-1):
            self.append(item)
            return
        node = Node(item)
        pre = self._head
        count = 0
        while count < (pos-1):
            pre = pre.next
            count += 1
        node.next = pre.next
        pre.next = node

    def remove(self, item):
        """删除节点"""
        cur = self._head
        pre = None
        while cur is not None:
            if cur.next.elem == item:
                pre = cur
                cur = cur.next
                pre.next = cur.next

    def search(self, item):
        """查找节点是否存在"""
        cur = self._head
        while cur is not None:
            if cur.elem == item:
                return True
            cur = cur.next
        return False


if __name__ == "__main__":
    li = SingleLinkList()
    print(li.is_empty())
    print(li.length())

    li.append(1)
    print(li.is_empty())
    print(li.length())

    li.append(2)
    li.append(3)
    li.append(4)
    li.append(5)

    li.travel()


    print(li.search(3))

    li.insert(3,123)
    li.travel()