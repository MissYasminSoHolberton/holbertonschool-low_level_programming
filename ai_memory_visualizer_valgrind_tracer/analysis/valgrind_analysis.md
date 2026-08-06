# Valgrind Analysis: `aliasing_example.c`

---

# Issue 1 – Invalid Read

## Valgrind Classification

**Invalid read of size 4**

## Memory Object Involved

The heap array allocated in `make_numbers()` by:

```c
arr = (int *)malloc((size_t)n * sizeof(int));
```

The invalid access occurs through the pointer `b`.

## Code

```c
printf("  reading b[2]=%d\n", b[2]);
```

## Explanation

The heap array is deallocated by:

```c
free(a);
```

Although `b` still contains the same address, the heap object no longer exists. Accessing `b[2]` attempts to read memory whose lifetime has already ended.

This is classified as a **use-after-free** because the heap object's lifetime ended when `free(a)` was called.

### Verification using the Memory Map

- The heap array's lifetime ends when `free(a)` is executed.
- `b` continues to exist because it is a local variable in `main()`.
- `b` becomes a dangling pointer after `free(a)`.

---

# Issue 2 – Invalid Write

## Valgrind Classification

**Invalid write of size 4**

## Memory Object Involved

The same heap array allocated by `malloc()`.

## Code

```c
b[3] = 1234;
```

## Explanation

The heap memory has already been released by:

```c
free(a);
```

Writing through `b` attempts to modify memory that no longer belongs to the program.

This is another **use-after-free** because the heap object's lifetime has already ended.

### Verification using the Memory Map

- The heap object is destroyed by `free(a)`.
- `b` still stores the address of the freed heap allocation.
- Writing through `b` violates the lifetime of the heap object.

---

# Issue 3 – Invalid Read

## Valgrind Classification

**Invalid read of size 4**

## Memory Object Involved

The same heap array allocated by `malloc()`.

## Code

```c
printf("  wrote b[3]=%d\n", b[3]);
```

## Explanation

After the invalid write, the program immediately evaluates `b[3]` so that `printf()` can print its value.

Before `printf()` can output the integer, the expression:

```c
b[3]
```

must be evaluated. Since the heap memory has already been freed, this produces another **use-after-free**, which Valgrind correctly reports as a second **Invalid Read**.

### Verification using the Memory Map

- The heap object no longer exists.
- `b` is still a dangling pointer.
- Evaluating `b[3]` requires reading from freed memory.

---

# Valgrind Analysis: `heap_example.c`

---

# Issue 1 – Memory Leak

## Valgrind Classification

**Definitely lost**

## Memory Object Involved

The heap allocation for `alice->name`.

Valgrind reports the allocation was created at:

```text
==5740== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==5740==    at 0x484F8A8: malloc (vg_replace_malloc.c:446)
==5740==    by 0x40011CD: person_new (heap_example.c:21)
==5740==    by 0x40012AE: main (heap_example.c:51)
```

The allocation corresponds to:

```c
p->name = (char *)malloc(len + 1);
```

## Explanation

Each `Person` object contains two separate heap allocations:

1. The `Person` structure itself.
2. The dynamically allocated string stored in `name`.

Bob's memory is released correctly:

```c
free(bob->name);
free(bob);
```

However, Alice is cleaned up using:

```c
person_free_partial(alice);
```

which only performs:

```c
free(p);
```

The `Person` structure is deallocated, but the memory allocated for `alice->name` is never freed.

When the structure is destroyed, the only pointer to the string allocation is also destroyed. The string allocation becomes unreachable, so Valgrind classifies it as **definitely lost**.

## Verification using the Memory Analysis

- `alice` points to a heap-allocated `Person` structure.
- `alice->name` points to a second heap allocation containing `"Alice"`.
- `free(alice)` destroys only the `Person` structure.
- The pointer to `alice->name` is destroyed together with the structure.
- The string allocation remains allocated but is no longer reachable.

This matches Valgrind's report of **6 bytes definitely lost**, which corresponds to the string `"Alice"` plus its null terminator.

---

# AI Mistake

Calling `free(alice)` automatically frees `alice->name` because it is a member of the structure.

**Correction**

This is incorrect. `free()` only deallocates the memory block whose address is passed to it. Since `alice->name` was allocated separately using `malloc()`, it occupies a different heap allocation and must be freed separately. Because `person_free_partial()` only calls `free(p)`, the string allocation is left allocated after the structure is destroyed. The pointer to the string is lost, resulting in a **definitely lost** memory leak.
