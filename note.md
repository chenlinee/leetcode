# 解题过程中常见的小错误  

　　做题的时候，经常出现题目思路正确，但是不能一次写对的情况出现。花在寻找 Bug 上的时间，已经和解题的时间相当，十分浪费时间。为了减小代码的出错率，在这个文档上记录自己经常犯下的小错误。  

[TOC]  

## 函数中局部变量问题  

　　由于解题过程中进场出现指针，指针的指针，局部变量等变量共存，有时会出现想要修改函数参数的指针指向的数据内容，实际代码却是修改了局部变量的内容。  

### 1. 并查集问题合并集合错误  

　　下面代码是 leetcode 200.number-of-islands 题目解答中用到的一个函数，这里想要把两个集合的根节点合并起来。但是错误的代码只修改了集合 a 的根节点局部变量合并值，没有把修改写到数组 arr 里面，导致解答错误。  

```c
void merge(array_2d** arr, int a_i, int a_j, int b_i, int b_j)
{
    array_2d a_parent = arr[a_i][a_j], b_parent = arr[b_i][b_j];
    while(a_parent.row != arr[a_parent.row][a_parent.col].row || 
            a_parent.col != arr[a_parent.row][a_parent.col].col)
    {
        a_parent = arr[a_parent.row][a_parent.col];
    }
    while(b_parent.row != arr[b_parent.row][b_parent.col].row || 
            b_parent.col != arr[b_parent.row][b_parent.col].col)
    {
        b_parent = arr[b_parent.row][b_parent.col];
    }
// <<<<<<< right
    arr[a_parent.row][a_parent.col] = b_parent;
// =======
    a_parent = b_parent;
// >>>>>>> error
}
```

### 2. ...  

## 注意边界条件  

　　leetcode 上比较复杂的问题，一个难点是边界条件的判断和处理。边界条件有两种情况，一种是函数传入参数的边界条件判断，一种是数据处理过程中的边界条件。  

　　对于函数参数边界条件的判断，现在我在做题时已经会注意。传入参数的边界条件判断，可以提高程序的健壮性。对于不合理的传入参数数值，先判断一下数值是否合法，非常有助于减少段错误。如果在传入参数出错时，加入适当的打印，在网上做题无法调试的情况下，更是有助于判断程序哪里出现了错误。  

　　另外一种是处理处理过程的边界条件。比如数组的第一项和最后一项，链表（栈、队列）为空的情况等。写代码之前，先考虑好所有的情况，先把所有情况的注释写出来，再去填充所有情况，避免遗漏。  

### 1. ...  

