# Binary Trees in C

This repository contains an implementation of various binary tree operations in the C programming language. Binary trees are hierarchical data structures that consist of nodes, each having at most two children: left and right. This project covers a range of functionalities for binary trees, including node creation, insertion, deletion, traversal methods, and various other operations.

## Table of Contents
- [Binary Trees in C](#binary-trees-in-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Functionality](#functionality)
  - [Project Structure](#project-structure)
  - [How to Use](#how-to-use)
  - [Example](#example)
  - [Contributing](#contributing)
  - [License](#license)

## Introduction

Binary trees are fundamental data structures used in computer science for efficient data storage and retrieval. This repository provides a set of C functions to perform various operations on binary trees, allowing users to manipulate and analyze tree structures.

## Functionality

The implemented functions cover a broad range of binary tree operations, including:

- Node creation (`binary_tree_node`)
- Insertion of nodes to the left (`binary_tree_insert_left`) and right (`binary_tree_insert_right`)
- Deletion of nodes (`binary_tree_delete`)
- Checking if a node is a leaf (`binary_tree_is_leaf`)
- Checking if a node is the root (`binary_tree_is_root`)
- Traversal methods: pre-order (`binary_tree_preorder`), in-order (`binary_tree_inorder`), post-order (`binary_tree_postorder`)
- Calculating the height (`binary_tree_height`) and depth (`binary_tree_depth`) of a tree
- Counting the size (`binary_tree_size`) of a tree, leaves (`binary_tree_leaves`), and nodes (`binary_tree_nodes`)
- Calculating the balance factor (`binary_tree_balance`)
- Checking if a tree is full (`binary_tree_is_full`) or perfect (`binary_tree_is_perfect`)
- Finding the sibling (`binary_tree_sibling`) and uncle (`binary_tree_uncle`) of a node

## Project Structure

The project structure is organized as follows:

- `binary_trees.h`: Header file containing function prototypes and the definition of the `binary_tree_t` structure.
- `0-binary_tree_node.c`: Implementation of the function to create a binary tree node.
- `1-binary_tree_insert_left.c`: Implementation of the function to insert a node as the left child of another node.
- `2-binary_tree_insert_right.c`: Implementation of the function to insert a node as the right child of another node.
- ...
- `binary_tree_print.c`: Implementation of a print function for visualization purposes (you can use it during development but not required to push to the repo).
- `main.c`: Example usage of the implemented functions.

## How to Use

To use these binary tree functions in your C project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/binary-trees-c.git
