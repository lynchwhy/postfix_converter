/*
 * infix_to_postfix_converter.cpp
 * Written by : Jo Lynch (c3200655)
 * Modified : 03/09/2023
 *
 * This class represents the implementation for an infix to postfix expression converter.
 * This file should be used in conjunction with Assignment 2 for SENG1120.
 */

#include "infix_to_postfix_converter.h"

infix_to_postfix_converter::infix_to_postfix_converter(std::string &input)
{
    infix = input;
    postfix = convert_to_postfix(input);
}

infix_to_postfix_converter::~infix_to_postfix_converter()
{
    // empty destructor
}

const std::string &infix_to_postfix_converter::get_infix() const
{
    return infix;
}

const std::string &infix_to_postfix_converter::get_postfix() const
{
    return postfix;
}

int infix_to_postfix_converter::precedence(char op) const
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '(')
        return 0;
    else
        return -1;
}

std::string infix_to_postfix_converter::convert_to_postfix(std::string &input)
{
    LStack<char> stack;
    LQueue<char> queue;

    // parse each character in the input string
    for (char sym : input)
    {

        // if sym is a space character: skip it
        if (isspace(sym))
        {
            continue; // skip the rest of the iteration
        }
        // if the character is a digit or a letter
        if (isalnum(sym))
        {
            // push to the queue
            queue.enqueue(sym);
        }
        else if (sym == '(')
        {
            // push to the stack
            stack.push(sym);
        }
        else if (sym == ')')
        {
            // while the stack is not empty and the top of the stack is not a left bracket
            while (!stack.empty() && stack.top() != '(')
            {
                // pop the top of the stack and push to the queue
                queue.enqueue(stack.pop());
            }
            // if the stack is empty
            if (stack.empty())
            {
                // throw an exception
                throw std::runtime_error("Invalid expression: missing left bracket");
            }
            // otherwise
            else
            {
                // pop the top of the stack
                stack.pop();
            }
        }
        // if the character is an operator
        else if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
        {
            // while the stack is not empty and the top of the stack is not a left bracket
            while (!stack.empty() && stack.top() != '(')
            {
                // if the precedence of the current character is less than or equal to the precedence of the top of the stack
                if (precedence(sym) <= precedence(stack.top()))
                {
                    // pop the top of the stack and push to the queue
                    queue.enqueue(stack.pop());
                }
                // otherwise
                else
                {
                    // break out of the loop
                    break;
                }
            }

            // push the current character to the stack
            stack.push(sym);
        }
        else
        {
            // throw an exception
            throw std::invalid_argument("Invalid expression: invalid character");
        }
    }
    // if the stack is not empty pop and enqueue the remaining operators
    while (!stack.empty())
    {
        queue.enqueue(stack.pop());
    }

    // while the queue is not empty
    while (!queue.empty())
    {
        // append the front of the queue to the postfix string
        postfix += queue.dequeue();
    }

    return postfix;
}
