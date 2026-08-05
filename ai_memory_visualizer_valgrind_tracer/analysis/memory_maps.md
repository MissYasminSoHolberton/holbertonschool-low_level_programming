# Program: stack_example.c

## Desciption
This function only uses the stack, no memory was allocated in the heap, as illustrated in the memoery map below.

## Memory Map
### Step 1 – Enter main()
#### Code executed
```
int main(void)
```
#### Stack
```
Top of Stack

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- A stack frame for main() is created.
- No heap memory is allocated.

#### Lifetime
| Variable | Lifetime |
| ----- | ----- |
| main() stack frame | Created when the program starts. Destroyed when main() returns. |

## AI Mistakes:
This was from the first prompt 
### Step 3: dump_frame("enter",0)

Another function call means another stack frame.

```
Stack

+----------------------+
| dump_frame           |
| label -> "enter"     |
| depth = 0            |
| local_int = 100      |
| local_buf[16]        |
| p_local -----------+ |
+--------------------|-+
                     |
                     v
                local_int

+----------------------+
| walk_stack           |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+

Heap
----
(empty)
```

#### Pointer analysis
This line
```
int *p_local = &local_int;
```
means
```
p_local
    |
    +-------> local_int
```

This is not heap memory.
Both variables live inside the same stack frame.
There is no aliasing because only p_local references local_int.

### Step 4: dump_frame() returns

That frame disappears.

```
Stack

+----------------------+
| walk_stack           |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```

