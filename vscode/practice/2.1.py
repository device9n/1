class listNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def remove_duplicates(head):
    if not head:
        return head;
    
    seen = set()
    current = head
    seen.add(current.val)

    while current and current.next:
        if current.next.val in seen:
            current.next = current.next.next
        else:
            seen.add(current.next.val)
            current = current.next
    return head

def remove_duplicates_no_buffer(head):
    current = head

    while current:
        runner = current
        while runner.next:
            if runner.next.val == current.val:
                runner.next = runner.next.next
            else:
                runner = runner.next
        current = current.next
    return head

