# Program: stack_example.c

## Step 1 - Enter main()

Only one stack frame exists.

```
Stack (top)

+----------------------+
| main()               |
|                      |
+----------------------+

Heap
----
(empty)
```

Lifetime:
- main() frame is created when the program starts.
- It remains until the program exits.

## Step 2: walk_stack(0,3) is called

A new stack frame is pushed.

```
Stack

+----------------------+
| walk_stack           |
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+

Heap
----
(empty)
```

```
int marker = depth * 10;
```
This creates a new local variable inside this frame.


