# CallQueue
# A queue system for calls. 

You add calls to the queue with their arguments (lvalues are treated as ptrs so they change). Then you can call groups of calls from the queue. 
There are many types of call groups, such as a stack where functions are pushed off when their group is called, and all levels above are also called. 
There are also groups, which only call the level and don't clear it, and queues, which are like stacks, execpt functions are not pushed off. 

