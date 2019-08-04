---
title: "Forcing Newlines while using clang-format"
author: lyrahgames
---

[`clang-format`](https://clang.llvm.org/docs/ClangFormat.html) is a tool which can automatically format your C++ source code.
It provides different standard styles and custom configuration possibilities.
Its usage lets you think more about the content of your code instead of its appearance.
Most text editors provide packages to automatically run `clang-format` every time a specific file was changed or saved.

But all this automation can introduce certain kinds of artifacts.
Take the following example:

{% raw %}
```c++
pair<int,int> array[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
```
{% endraw %}

Applying `clang-format` to this piece of code will result in the following code snippet.

{% raw %}
```c++
pair<int, int> array[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5},
                          {5, 6}, {6, 7}, {7, 8}, {8, 9}};
```
{% endraw %}

A newline character has been added between the forth and the fifth element.
In most cases, this generic insertion of newline characters may be good enough.
But let us assume you would like to have a newline character right after the equality sign.
Applying `clang-format` will always result in the code snippet shown above.
Hence, we somehow have to instruct `clang-format` to keep and insert newlines when needed.
One way of doing this is to disable formatting on a piece of code by using the comments `// clang-format on` and `// clang-format off`.

{% raw %}
```c++
// clang-format off
pair<int, int> array[] =
  {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
// clang-format on
```
{% endraw %}

This method consists of certain drawbacks.
First, we do not want to mention `clang-format` inside our code.
Another issue is that by adding these comments, we have completely disabled the automatic formatting.
But we only wanted to force `clang-format` to add one newline character.

A much better solution is given by the following idea.
We add an empty comment in front of newline characters we would like to keep.

{% raw %}
```c++
pair<int, int> array[] =  //
    {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
```
{% endraw %}

In this case, `clang-format` will not remove the newline character and therefore keep the custom formatting.
Additionally, `clang-format` is not mentioned in the code and all other parts will still be formatted automatically.
Of course, it is possible to go even further.
For example, by inserting newline characters after every second element in the array we get the following.

{% raw %}
```c++
pair<int, int> array[] = {
    {1, 2}, {2, 3},  //
    {3, 4}, {4, 5},  //
    {5, 6}, {6, 7},  //
    {7, 8}, {8, 9}   //
};
```
{% endraw %}

Special formatting is possible as well.

{% raw %}
```c++
pair<int, int> array[] = {
    {1, 2},                          //
    {2, 3}, {3, 4}, {4, 5}, {5, 6},  //
    {6, 7}, {7, 8}, {8, 9}           //
};
```
{% endraw %}

So next time `clang-format` does not format the code the way you like it, think about the insertion of empty comments to force newline characters.