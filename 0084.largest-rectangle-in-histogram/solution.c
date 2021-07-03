#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
typedef struct stack_node
{
    int value;
    struct stack_node* front;
} stack_node_t;

typedef struct stack
{
    stack_node_t* top;
    int size;
} stack_t;

stack_t* stack_init(void)
{
    stack_t* stack_p = (stack_t*)malloc(sizeof(stack_t));

    stack_p->top = NULL;
    stack_p->size = 0;

    return stack_p;
}

void stack_clear(stack_t* stack_p)
{
    stack_node_t* top_node_p = stack_p->top;
    while(stack_p->size > 0)
    {
        top_node_p = stack_p->top;
        stack_p->top = top_node_p->front;
        stack_p->size--;
        free(top_node_p);
    }
}

void stack_deinit(stack_t* stack_p)
{
    stack_node_t* top_node_p = stack_p->top;
    while(stack_p->size > 0)
    {
        top_node_p = stack_p->top;
        stack_p->top = top_node_p->front;
        stack_p->size--;
        free(top_node_p);
    }

    free(stack_p);
}

void stack_push(stack_t* stack_p, int value)
{
    stack_node_t* stack_node_p = (stack_node_t*)malloc(sizeof(stack_node_t));
    stack_node_p->value = value;
    stack_node_p->front = stack_p->top;
    stack_p->top = stack_node_p;
    stack_p->size++;
}

int stack_pop(stack_t* stack_p)
{
    if(stack_p->size <= 0)
    {
        printf("Error. Stack empty, can not pop.\n");
        exit(0);
    }

    stack_node_t* top_node_p = stack_p->top;
    stack_p->top = top_node_p->front;
    stack_p->size--;

    int value = top_node_p->value;

    free(top_node_p);
    return value;
}
*/
int largestRectangleArea(int* heights, int heightsSize)
{
    if(heightsSize < 1 || heights == NULL)
    {
        return 0;
    }
    
    int* stack = (int*)malloc(heightsSize * sizeof(int));
    int* left = (int*)malloc(heightsSize * sizeof(int));
    int stack_count = 0;

    // left
    for(int i = 0; i < heightsSize; ++i)
    {
        while(stack_count > 0 && heights[stack[stack_count - 1]] >= heights[i])
        {
            stack_count--;
        }
        if(stack_count == 0)
        {
            left[i] = -1;
        }
        else
        {
            left[i] = stack[stack_count - 1];
        }
        stack[stack_count] = i;
        stack_count++;
        // 栈空， 标记
        /*
        if(rise_stack->size == 0)
        {
            left[i] = -1;
            stack_push(rise_stack, i);
        }
        else
        {
            // 当前高度大于栈顶元素高度
            if(heights[rise_stack->top->value] < heights[i])
            {
                stack_push(rise_stack, i);
                left[i] = i - 1;
            }
            // 当前高度小于等于栈顶圆度高度，出栈
            else
            {
                while(rise_stack->size > 0 && heights[rise_stack->top->value] >= heights[i])
                {
                    stack_pop(rise_stack);
                }
                if(rise_stack->size == 0)
                {
                    left[i] = -1;
                }
                else
                {
                    left[i] = rise_stack->top->value;
                }
                stack_push(rise_stack, i);
            }
        }
        */
    }

    stack_count = 0;

    // right
    int max = 0, current = 0;
    for(int i = heightsSize - 1; i >= 0; --i)
    {
        while(stack_count > 0 && heights[stack[stack_count - 1]] >= heights[i])
        {
            stack_count--;
        }
        if(stack_count == 0)
        {
            //right[i] = heightsSize;
            current = (heightsSize - left[i] - 1) * heights[i];
            max = current > max ? current : max;
        }
        else
        {
            //right[i] = rise_stack->top->value;
            current = (stack[stack_count - 1] - left[i] - 1) * heights[i];
            max = current > max ? current : max;
        }
        stack[stack_count] = i;
        stack_count++;
        /*
        // 栈空
        if(rise_stack->size == 0)
        {
            //right[i] = heightsSize;
            current = (heightsSize - left[i] - 1) * heights[i];
            max = current > max ? current : max;
            stack_push(rise_stack, i);
        }
        else
        {
            // 当前高度大于栈顶元素高度
            if(heights[rise_stack->top->value] < heights[i])
            {
                stack_push(rise_stack, i);
                //right[i] = i + 1;
                current = (i + 1 - left[i] - 1) * heights[i];
                max = current > max ? current : max;
            }
            // 当前高度小于等于栈顶圆度高度，出栈
            else
            {
                while(rise_stack->size > 0 && heights[rise_stack->top->value] >= heights[i])
                {
                    stack_pop(rise_stack);
                }
                if(rise_stack->size == 0)
                {
                    //right[i] = heightsSize;
                    current = (heightsSize - left[i] - 1) * heights[i];
                    max = current > max ? current : max;
                }
                else
                {
                    //right[i] = rise_stack->top->value;
                    current = (rise_stack->top->value - left[i] - 1) * heights[i];
                    max = current > max ? current : max;
                }
                stack_push(rise_stack, i);
            }
        }
        */
    }

    // 计算最大面积
    /*
    for(int i = 0; i < heightsSize; ++i)
    {
        current = (right[i] - left[i] - 1) * heights[i];
        if(current > max)
        {
            max = current;
        }
    }
    */
    free(stack);
    free(left);
    return max;
}
