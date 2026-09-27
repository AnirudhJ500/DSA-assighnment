# DSA Assignment 2 – Question 2

## Data Structures and Algorithms

### Topic
Binary Search Tree (BST) and Linear Search

---

## Student Details

- **Name:** Anirudh J
- **Roll No:** 10
- **Assignment:** 2
- **Question:** 2
- **Subject:** Data Structures and Algorithms
- **Branch:** ADS
- **Semester:** III

---

## Problem Statement

An online bookstore stores the following ISBN keys:

`45, 20, 60, 10, 30, 50, 70, 25, 55`

A Binary Search Tree is constructed by inserting the ISBN keys in the given
order.

The program performs:

1. Inorder traversal
2. Preorder traversal
3. Postorder traversal
4. BST Search
5. Linear Search

The keys searched are:

`25, 55, 90`

The number of comparisons required by BST Search and Linear Search is
recorded and compared.

---

## BST Structure

```text
             45
           /    \
         20      60
        /  \    /  \
      10   30  50   70
          /      \
         25       55
```

**Height:** 3 edges (4 levels)

---

## Traversals

**Inorder:** `10 20 25 30 45 50 55 60 70`

**Preorder:** `45 20 10 30 25 60 50 55 70`

**Postorder:** `10 25 30 20 55 50 70 60 45`

---

## Search Results

| Key | BST Search | BST Comparisons | Linear Search | Linear Comparisons |
|---:|---|---:|---|---:|
| 25 | Found | 4 | Found | 8 |
| 55 | Found | 4 | Found | 9 |
| 90 | Not Found | 3 | Not Found | 9 |

---

## Complexity Analysis

### BST Search

- Best Case: **O(1)** – key is at the root
- Average Case: **O(log n)** – reasonably balanced tree
- Worst Case: **O(n)** – skewed tree
- Space Complexity: **O(n)** for storing the tree

### Linear Search

- Best Case: **O(1)** – key is at the first position
- Average Case: **O(n)**
- Worst Case: **O(n)** – key is at the last position or absent
- Extra Space: **O(1)**

---

## Comparison

| Criteria | BST Search | Linear Search |
|---|---|---|
| Data structure | Binary Search Tree | Array/List |
| Search method | Move left/right based on key | Check one by one |
| Best case | O(1) | O(1) |
| Average case | O(log n)* | O(n) |
| Worst case | O(n) | O(n) |
| Extra search space | O(1) for iterative search | O(1) |
| Search 25 | 4 comparisons | 8 comparisons |
| Search 55 | 4 comparisons | 9 comparisons |
| Search 90 | 3 comparisons | 9 comparisons |

\* Average-case O(log n) assumes a reasonably balanced BST.

---

## Repository Contents

| File | Description |
|---|---|
| `bst_linear_search.c` | C program implementing BST construction, traversals, BST search and linear search |
| `input.txt` | Input ISBN keys and search keys |
| `output.txt` | Program execution output |
| `complexity_analysis.txt` | Time and space complexity analysis |
| `comparison_table.txt` | BST Search vs Linear Search comparison |
| `conclusion.txt` | Final conclusion |

---

## How to Run

### Using GCC

```bash
gcc bst_linear_search.c -o bst_search
```

### Run

#### Windows
```bash
bst_search.exe
```

#### Linux / macOS
```bash
./bst_search
```

---

## Conclusion

For the given ISBN dataset, the measured number of comparisons was lower for
BST Search than Linear Search for all three tested keys.

However, BST performance depends on the shape and height of the tree. A
reasonably balanced BST can provide O(log n) average search time, while a
skewed BST can degrade to O(n).

The detailed execution results, complexity analysis, comparison and conclusion
are provided in the corresponding files in this repository.
