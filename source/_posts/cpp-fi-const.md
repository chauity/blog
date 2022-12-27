---
title: 关于 const 那些事儿 
date: 2022-11-08 10:55:15
tags: cpp -> const
---
# C++ const 关键字小结

`const` 是 `constant` 的缩写，本意是不变的，不易改变的意思。在 `C++` 是用来修饰 `内置类型变量` ， `自定义对象` ， `成员函数` ，`返回值` ， `函数参数` 。

`C++ const` 允许指定一个语句约束，编辑器会强制实施这个约束，允许程序员告诉编译器某值是保持不变的。如果在编程中确实有某个值保持不变，就应该使用 `const`，这样可以获得编译器的帮助。

## 一、const 修饰普通类型的变量

```cpp
const int a = 7;
int b = a;	//正确
a = 8;		//错误，a不能改变
b = 8;		//正确
```

![20221108113336](https://cdn.staticaly.com/gh/chauity/images@master/blog/pictures/20221108113336.png)
