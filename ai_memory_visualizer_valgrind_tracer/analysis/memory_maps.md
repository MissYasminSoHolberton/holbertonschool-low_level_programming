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
| Variable/Object      | Lifetime                                                          |
| -------------------- | ----------------------------------------------------------------- |
| `main()` stack frame | Created when the program starts. Destroyed when `main()` returns. |
| Heap objects         | None.                                                             |

### Step 2 – Enter walk_stack(0,3)
#### Code executed
```
walk_stack(0, 3);
```
#### Stack
```
Top of Stack

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- A new stack frame is pushed.
- Parameters depth and max_depth are copied into the frame.
- marker is initialized to 0.
#### Lifetime
| Variable    | Lifetime                                                                                  |
| ----------- | ----------------------------------------------------------------------------------------- |
| `depth`     | Created when `walk_stack()` is called. Destroyed when this recursive call returns.        |
| `max_depth` | Created when `walk_stack()` is called. Destroyed when this recursive call returns.        |
| `marker`    | Created when execution enters `walk_stack()`. Destroyed when this recursive call returns. |

### Step 3 – Enter dump_frame("enter",0)
#### Code executed
```
dump_frame("enter", depth);
```
#### Stack
```
Top of Stack

+----------------------------------+
| dump_frame()                     |
|----------------------------------|
| label -----> "enter"             |
| depth = 0                        |
| local_int = 100                  |
| local_buf[16]                    |
| p_local ---------> local_int      |
+----------------------------------+

+----------------------------------+
| walk_stack()                     |
|----------------------------------|
| depth = 0                        |
| max_depth = 3                    |
| marker = 0                       |
+----------------------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- A new stack frame is created for dump_frame().
- local_int is initialized to 100.
- local_buf is allocated on the stack.
- p_local stores the address of local_int.
- label points to the string literal "enter" stored in read-only memory.
#### Lifetime
| Variable                 | Lifetime                                                          |
| ------------------------ | ----------------------------------------------------------------- |
| `label`                  | Created when `dump_frame()` is called. Destroyed when it returns. |
| `"enter"` string literal | Exists for the entire program.                                    |
| `depth`                  | Created when `dump_frame()` is called. Destroyed when it returns. |
| `local_int`              | Created on function entry. Destroyed when the function returns.   |
| `local_buf`              | Created on function entry. Destroyed when the function returns.   |
| `p_local`                | Created on function entry. Destroyed when the function returns.   |

### Step 4 – Return from dump_frame()
#### Stack
```
Top of Stack

+----------------------+
| walk_stack()         |
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- dump_frame()'s stack frame is removed.
- local_int, local_buf, and p_local no longer exist.
#### Lifetime
| Variable                       | Lifetime                                                     |
| ------------------------------ | ------------------------------------------------------------ |
| `local_int`                    | Ends here.                                                   |
| `local_buf`                    | Ends here.                                                   |
| `p_local`                      | Ends here.                                                   |
| `marker`, `depth`, `max_depth` | Continue to exist because `walk_stack()` is still executing. |

### Step 5 – Recursive call walk_stack(1,3)
#### Code executed
```
walk_stack(depth + 1, max_depth);
```
#### Stack
```
Top of Stack

+----------------------+
| walk_stack()         |
| depth = 1            |
| max_depth = 3        |
| marker = 10          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- A second walk_stack() frame is created.
- The original walk_stack() frame remains on the stack.
#### Lifetime
| Variable                                | Lifetime                                                             |
| --------------------------------------- | -------------------------------------------------------------------- |
| `depth` (second call)                   | Created for this recursive call only.                                |
| `max_depth` (second call)               | Created for this recursive call only.                                |
| `marker` (second call)                  | Created with value `10`. Destroyed when this recursive call returns. |
| Variables from the first `walk_stack()` | Remain alive because that call has not returned.                     |

### Step 6 – Deepest recursion (walk_stack(3,3))
#### Stack
```
Top of Stack

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 3            |
| max_depth = 3        |
| marker = 30          |
+----------------------+

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 2            |
| max_depth = 3        |
| marker = 20          |
+----------------------+

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 1            |
| max_depth = 3        |
| marker = 10          |
+----------------------+

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- Four separate walk_stack() stack frames now exist.
- Each recursive call has its own independent variables.
#### Lifetime
| Variable                 | Lifetime                                            |
| ------------------------ | --------------------------------------------------- |
| Each `depth`             | Exists only within its own recursive call.          |
| Each `marker`            | Exists only within its own recursive call.          |
| Earlier recursive frames | Stay alive until the deeper recursive calls return. |

### Step 7 – Returning from recursion
After walk_stack(3,3) returns:
#### Stack
```
Top of Stack

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 2            |
| max_depth = 3        |
| marker = 20          |
+----------------------+

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 1            |
| max_depth = 3        |
| marker = 10          |
+----------------------+

+----------------------+
| walk_stack()         |
|----------------------|
| depth = 0            |
| max_depth = 3        |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```
#### Heap
```
(empty)
```
#### Memory Changes
- The walk_stack(depth = 3) frame has been popped from the stack.
- Execution resumes in the walk_stack(depth = 2) frame.
#### Lifetime
| Variable                   | Lifetime                                                  |
| -------------------------- | --------------------------------------------------------- |
| `depth = 3`, `marker = 30` | End when the deepest recursive call returns.              |
| `depth = 2`, `marker = 20` | Continue to exist until the `depth = 2` call returns.     |
| Remaining recursive frames | Continue to exist until each respective function returns. |


## AI Mistakes:
This is the uncorrected prompt, in the walk_stack there is only one variable, but the other variables (depth and max_depth) should still be there, this was still present in the next prompts, I needed to correct this manually even after telling the LLM the issue.
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
```
(empty)
```
