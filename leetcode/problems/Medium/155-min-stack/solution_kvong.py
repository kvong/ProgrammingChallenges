class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []
        

    def push(self, val: int) -> None:
        self.stack.append( val )
        if len( self.min_stack ) > 0:
            self.min_stack.append( min( self.min_stack[-1], val) )
        else:
            self.min_stack.append( val )
        print( self.min_stack )

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()
        

    def top(self) -> int:
        if len(self.stack) > 0:
            return self.stack[-1]
        return None

    def getMin(self) -> int:
        return self.min_stack[-1]
