# Program: `stack_example.c`

## Description
This program demonstrates how recursive function calls create independent stack frames. All variables are allocated on the **stack**. No memory is allocated on the **heap**, so the heap remains empty throughout execution. Each recursive call has its own copy of the local variables, parameters, and return address.

---

# Memory Map (AI assisted)

## Step 1 – Enter `main()`

### Code executed
```c
int main(void)
```

### Stack
```text
Top of Stack

+----------------------+
| main()               |
+----------------------+
```

### Heap
```text
(empty)
```

### Memory Changes
- A stack frame for `main()` is created.
- No heap memory is allocated.

### Lifetime

| Variable/Object | Lifetime |
|-----------------|----------|
| `main()` stack frame | Created when the program starts. Destroyed when `main()` returns. |
| Heap objects | None. |

---

## Step 2 – Enter `walk_stack(0,3)`

### Code executed
```c
walk_stack(0, 3);
```

### Stack
```text
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

### Heap
```text
(empty)
```

### Memory Changes
- A new stack frame is pushed onto the stack.
- Parameters `depth` and `max_depth` are copied into the frame.
- `marker` is initialized to `0`.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| `depth` | Created when `walk_stack()` is called. Destroyed when this call returns. |
| `max_depth` | Created when `walk_stack()` is called. Destroyed when this call returns. |
| `marker` | Created on function entry. Destroyed when the function returns. |

---

## Step 3 – Enter `dump_frame("enter", 0)`

### Code executed
```c
dump_frame("enter", depth);
```

### Stack
```text
Top of Stack

+----------------------------------+
| dump_frame()                     |
|----------------------------------|
| label -----> "enter"             |
| depth = 0                        |
| local_int = 100                  |
| local_buf[16]                    |
| p_local ---------> local_int     |
+----------------------------------+

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

### Heap
```text
(empty)
```

### Memory Changes
- A new stack frame is created for `dump_frame()`.
- `local_int` is initialized to `100`.
- `local_buf[16]` is allocated on the stack.
- `p_local` is assigned the address of `local_int`.
- `label` points to the read-only string literal `"enter"`.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| `label` | Created on entry. Destroyed on return. |
| `"enter"` string literal | Exists for the lifetime of the program. |
| `depth` | Created on entry. Destroyed on return. |
| `local_int` | Created on entry. Destroyed on return. |
| `local_buf` | Created on entry. Destroyed on return. |
| `p_local` | Created on entry. Destroyed on return. |

---

## Step 4 – Return from `dump_frame()`

### Code executed
```c
return;
```

### Stack
```text
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

### Heap
```text
(empty)
```

### Memory Changes
- `dump_frame()`'s stack frame is removed.
- `local_int`, `local_buf`, and `p_local` are destroyed.
- Execution resumes inside `walk_stack()`.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| `local_int` | Ends here. |
| `local_buf` | Ends here. |
| `p_local` | Ends here. |
| `marker`, `depth`, `max_depth` | Continue to exist because `walk_stack()` is still active. |

---

## Step 5 – Recursive Call `walk_stack(1,3)`

### Code executed
```c
walk_stack(depth + 1, max_depth);
```

### Stack
```text
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

### Heap
```text
(empty)
```

### Memory Changes
- A second `walk_stack()` frame is pushed.
- The original frame remains active underneath it.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| `depth` (second call) | Exists only during the second recursive call. |
| `max_depth` (second call) | Exists only during the second recursive call. |
| `marker = 10` | Destroyed when this recursive call returns. |
| Variables from the first call | Remain alive until the first call returns. |

---

## Step 6 – Deepest Recursion (`walk_stack(3,3)`)

### Code executed
```c
walk_stack(3, 3);
```

### Stack
```text
Top of Stack

+----------------------+
| walk_stack()         |
| depth = 3            |
| max_depth = 3        |
| marker = 30          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 2            |
| marker = 20          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 1            |
| marker = 10          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 0            |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```

### Heap
```text
(empty)
```

### Memory Changes
- Four independent `walk_stack()` stack frames now exist.
- Each frame contains its own `depth`, `max_depth`, and `marker`.
- No variables are shared between recursive calls.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| Each `depth` | Exists only within its own stack frame. |
| Each `marker` | Exists only within its own stack frame. |
| Earlier recursive frames | Stay alive until deeper calls return. |

---

## Step 7 – Returning From Recursion

### Code executed
```c
return;
```

### Stack
```text
Top of Stack

+----------------------+
| walk_stack()         |
| depth = 2            |
| marker = 20          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 1            |
| marker = 10          |
+----------------------+

+----------------------+
| walk_stack()         |
| depth = 0            |
| marker = 0           |
+----------------------+

+----------------------+
| main()               |
+----------------------+
```

### Heap
```text
(empty)
```

### Memory Changes
- The `walk_stack(depth = 3)` frame is popped.
- Control returns to `walk_stack(depth = 2)`.
- The remaining recursive frames are removed one by one until `main()` finishes.

### Lifetime

| Variable | Lifetime |
|----------|----------|
| `depth = 3`, `marker = 30` | End when the deepest call returns. |
| `depth = 2`, `marker = 20` | Continue until the depth 2 call returns. |
| `depth = 1`, `marker = 10` | Continue until the depth 1 call returns. |
| `depth = 0`, `marker = 0` | Continue until the initial call returns. |
| `main()` stack frame | Destroyed when the program exits. |

---

## AI Mistake

During **Step 3 (`dump_frame("enter", 0)`)**, the AI-generated memory map incorrectly omitted the `depth` and `max_depth` variables from the `walk_stack()` stack frame. Although `dump_frame()` creates a new stack frame, the `walk_stack()` frame remains active and should still contain all of its local variables and parameters (`depth`, `max_depth`, and `marker`).

This mistake was repeated in subsequent memory maps, even after I informed the LLM of the error. As a result, I manually corrected the stack diagrams to accurately represent the active stack frames and variable lifetimes.

### Incorrect AI Output

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
```

Heap

```text
(empty)
```

**Correction:** The `walk_stack()` frame should still contain `depth`, `max_depth`, and `marker` because that function has not yet returned.

## Summary

- Only **stack memory** is used.
- **No heap allocations or deallocations** occur.
- Every recursive call creates a **new stack frame** with independent local variables.
- `p_local` temporarily aliases `local_int` and becomes invalid after `dump_frame()` returns.
- Stack memory grows during recursion and shrinks as the recursive calls return.






# Program: `aliasing_example.c`

## Description
This program demonstrates how dynamic memory allocation works using the heap, as well as pointer aliasing and a use-after-free error. Memory is allocated on the heap using malloc(), while local variables and pointers are stored on the stack. Two pointers (a and b) reference the same heap memory, creating an alias. After the heap memory is deallocated using free(), both pointers still contain the same address, but the memory is no longer valid.

---

# Memory Map (AI assisted)

## Step 1 -- Enter `main()`

### Stack

``` text
Top of Stack

+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
```

### Heap

``` text
(empty)
```

### Memory Changes

-   `main()` stack frame is created.
-   `a` and `b` are initialized to `NULL`.
-   No heap memory has been allocated.

### Lifetime

  -----------------------------------------------------------------------
  Variable/Object                              Lifetime
  -------------------------------------------- --------------------------
  `a`, `b`, `n`                                Created when `main()`
                                               begins. Destroyed when
                                               `main()` returns.

  Heap objects                                 None.
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Step 2 -- Enter `make_numbers(5)`

### Stack

``` text
Top of Stack

+----------------------+
| make_numbers()       |
|----------------------|
| n = 5                |
| i = 0                |
| arr = NULL           |
+----------------------+

+----------------------+
| main()               |
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
```

### Heap

``` text
(empty)
```

### Memory Changes

-   A new `make_numbers()` stack frame is created.
-   `arr` is initialized to `NULL`.

### Lifetime

  -----------------------------------------------------------------------
  Variable/Object                              Lifetime
  -------------------------------------------- --------------------------
  `n`, `i`, `arr`                              Created when
                                               `make_numbers()` is
                                               called. Destroyed when it
                                               returns.

  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Step 3 -- After `malloc()`

``` c
arr = malloc((size_t)n * sizeof(int));
```

### Stack

```text
Top of Stack

+----------------------+
| make_numbers()       |
|----------------------|
| n = 5                |
| i = 0                |
| arr -> 0x1000        |
+----------------------+

+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
```

### Heap

```text
0x1000

+-----+-----+-----+-----+-----+
|  ?  |  ?  |  ?  |  ?  |  ?  |
+-----+-----+-----+-----+-----+
```

### Memory Changes

-   `malloc()` allocates memory for 5 integers.
-   `arr` now points to the first element of the heap array.

### Lifetime

  Variable/Object   Lifetime
  ----------------- ---------------------------------------------------------
  Heap array        Created by `malloc()`. Exists until `free()` is called.

------------------------------------------------------------------------

## Step 4 -- After the `for` loop

### Stack

```text
Top of Stack

+----------------------+
| make_numbers()       |
|----------------------|
| n = 5                |
| i = 5                |
| arr -> 0x1000        |
+----------------------+

+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
```

### Heap

```text
0x1000

+-----+-----+-----+-----+-----+
|  0  | 11  | 22  | 33  | 44  |
+-----+-----+-----+-----+-----+
```

### Memory Changes

-   The heap array is initialized with values.
-   `i` finishes with the value `5`.

### Lifetime

-   Heap array remains allocated.
-   `arr` still points to the heap array.

------------------------------------------------------------------------

## Step 5 -- Return to `main()`

``` c
a = make_numbers(n);
```

### Stack

``` text
Top of Stack

+----------------------+
| main()               |
|----------------------|
| a -> 1x1000          |
| b = NULL             |
| n = 5                |
+----------------------+


```

### Heap

``` text
0x1000

+----+----+----+----+----+
| 0  | 11 | 22 | 33 | 44 |
+----+----+----+----+----+
```

### Memory Changes

-   `make_numbers()` returns.
-   Its stack frame is destroyed.
-   `a` receives the heap address.

### Lifetime

  Variable/Object   Lifetime
  ----------------- -----------------------------------------
  `arr`             Ends when `make_numbers()` returns.
  Heap array        Remains alive because `a` points to it.

------------------------------------------------------------------------

## Step 6 -- Pointer aliasing

``` c
b = a;
```

### Stack

``` text
+----------------------+
| main()               |
|----------------------|
| a -> 0x1000          |
| b -> 0x1000          |
| n = 5                |
+----------------------+


```

### Heap

``` text
0x1000

+----+----+----+----+----+
| 0  | 11 | 22 | 33 | 44 |
+----+----+----+----+----+
```

### Memory Changes

-   `b` is assigned the same address as `a`.
-   No new allocation occurs.

### Lifetime

  Variable/Object   Lifetime
  ----------------- ------------------------------------
  `a`               Exists until `main()` returns.
  `b`               Exists until `main()` returns.
  Heap array        Remains allocated until `free(a)`.

### Pointer Aliasing

-   `a` and `b` both point to the same heap array.

------------------------------------------------------------------------

## Step 7 -- After `free(a)`

``` c
free(a);
```

### Stack

``` text
+----------------------+
| main()               |
|----------------------|
| a -> 0x1000          |
| b -> 0x1000          |
+----------------------+
```

### Heap

``` text
The heap array has been deallocated.
```

### Memory Changes

-   The heap array is freed.
-   Neither `a` nor `b` is modified.

### Lifetime

  Variable/Object   Lifetime
  ----------------- ----------------------------------------------
  Heap array        Ends when `free(a)` is called.
  `a`               Still exists but is a dangling pointer.
  `b`               Still exists but is also a dangling pointer.

------------------------------------------------------------------------

## Step 8 -- Use-after-free

``` c
printf("%d\n", b[2]);
b[3] = 1234;
```

### Stack

``` text
+----------------------+
| main()               |
|----------------------|
| a (dangling)         |
| b (dangling)         |
| n = 5                |
+----------------------+
```

### Heap

``` text
Previously freed.

Accessing this memory is undefined behaviour.
```

### Memory Changes

-   The program performs a use-after-free read and write.
-   No valid heap object exists.

### Lifetime

  Variable/Object   Lifetime
  ----------------- -------------------------------------------------
  `a`               Exists until `main()` returns.
  `b`               Exists until `main()` returns.
  Heap array        Already destroyed.

------------------------------------------------------------------------

# AI Review

**Incorrect AI explanation**

After `free(a)`, `a` becomes `NULL`.

**Correction**

This is incorrect. `free()` deallocates the heap object but does **not** modify pointer variables. Both `a` and `b` still store the same address after `free(a)`, making them dangling pointers. Accessing `b[2]` or writing `b[3]` is undefined behaviour.
