#include "solution.h"
#include <stdio.h>
#include <stdlib.h>


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize <= 0 || *matrixColSize <= 0)
    {
        return false;
    }

    int left = 0, bottom = matrixSize - 1;
    int current_num;
    while(left < *matrixColSize && bottom >= 0)
    {
        current_num = matrix[bottom][left];
        if(target == current_num)
        {
            return true;
        }
        else if(target > current_num)
        {
            left++;
        }
        else if(target < current_num)
        {
            bottom--;
        }
    }

    return false;
}

/*
struct Matrix_t {
    int** matrix;
    int matrixSize;
    int matrixColSize;
};

int getElement(struct Matrix_t* my_matrix, int i, int j)
{
    if(i < 0 || j < 0 || i >= my_matrix->matrixSize || j >= my_matrix->matrixColSize)
    {
        printf("i = %d, j = %d\n", i, j);
        printf("out of matrix access\n");
        exit(0);
    }

    printf("i = %d, j = %d, ", i, j);
    int ret = *(*(my_matrix->matrix + i) + j);
    printf("read success, ret = %d\n", ret);

    return ret;
}

bool searchSubMatrix(struct Matrix_t* matrix, int left, int top, int right, int bottom, int target)
{
    if(right < left || bottom < top || 
       left < 0 || top < 0 || right >= matrix->matrixColSize || bottom >= matrix->matrixSize)
    {
        return false;
    }

    int leftTop = getElement(matrix, top, left);
    int rightBottom = getElement(matrix, bottom, right);

    // 只有一个格子，验证是否为目标数字
    if(left == right && top == bottom)
    {
        if(target == leftTop)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 左上角的数字 或者 右下角的数字 是否等于目标数字
    if(target == leftTop || target == rightBottom)
    {
        return true;
    }

    // 验证数字是否不在此分区
    if(target < leftTop || target > rightBottom)
    {
        return false;
    }

    // 分成小格查找
    int midRow = (top + bottom) / 2;
    int midCol = (left + right) / 2;

    return searchSubMatrix(matrix, left, top, midCol, midRow, target) ||
           searchSubMatrix(matrix, midCol + 1, top, right, midRow, target) ||
           searchSubMatrix(matrix, left, midRow + 1, midCol, bottom, target) ||
           searchSubMatrix(matrix, midCol + 1, midRow + 1, right, bottom, target);
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize <= 0 || *matrixColSize <= 0)
    {
        return false;
    }

    struct Matrix_t my_matrix;
    my_matrix.matrix = matrix;
    my_matrix.matrixSize = matrixSize;
    my_matrix.matrixColSize = *matrixColSize;

    return searchSubMatrix(&my_matrix, 0, 0, my_matrix.matrixColSize - 1,
                    my_matrix.matrixSize - 1, target);
}
*/