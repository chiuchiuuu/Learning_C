## 2.11 条件语句

`?:` 语句的一些技巧

```c
/* 输出一个数组，每10个换一次行 */
for (int i = 0; i < n; i++)
{
  	printf("%6d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
}
```

```c
/* 输出单词的单复数 */
printf("You have %d item&s.\n", n, n == 1 ? "" : "s");
```

## 2.12 运算符优先级

按位运算符的优先级比判等运算符高

```c
if ((x & MASK) == 0) 
  	...
```

C语言没有规定操作数的运算顺序

```c
x = f() + g() /* 可能先求f(),  也可能先算g() */
```

> C++也没有：Order of evaluation of the operands of almost all C++ operators (including the order of evaluation of function arguments in a function-call expression and the order of evaluation of the subexpressions within any expression) is **unspecified**. The compiler can evaluate operands **in any order**, and may choose another order when the same expression is evaluated again.
>
> There are exceptions to this rule which are noted below.
>
> Except where noted below, there is no concept of left-to-right or right-to-left evaluation in C++. This is not to be confused with left-to-right and right-to-left associativity of operators: the expression `f1() + f2() + f3()` is parsed as `(f1() + f2()) + f3()` due to left-to-right associativity of operator+, but the function call to `f3` may be evaluated first, last, or between `f1()` or `f2()` at run time.

类似的，在函数参数的计算求值顺序也不确定

```c
printf("%d %d\n", ++n, power(2, n));  /* WRONG */
```

函数调用，嵌套赋值语句，自增自减运算符的求值过程中可能会产生副作用。

> In computer science, a function or expression is said to have a **side effect** if, in addition to returning a value, it also modifies some state or has an observable  interaction with calling functions or the outside world. 

一个典型的例子是调用 `printf()`，其返回值是没有意义的，我们利用的是他的副作用：向标准输出流进行输出。

在产生副作用的表达式的计算过程中，可能会由于操作数的更新（update）顺序不确定而导致未定义行为。例如：`a[i] = i++`。下标 `i` 的值是不确定的，不同的编译器可能会有不同的结果。

> In computer programming, **undefined behavior (UB)** is the result of executing computer code whose behavior is not prescribed by the language specification to which the code adheres, for the current state of the program. This happens when the translator of the source code makes certain assumptions, but these assumptions are not satisfied during execution.



# 3. 控制流

## 3.1 语句(Statements)和块(Blocks)

语句：`;`

块：`{}`

## 3.2 If-Else

## 3.3 Else-If

## 3.4 Switch

## 3.5 While and For

样例程序：

- shell sort
- reverse string

## 3.6 Loops-Do-While

## 3.7 Break and Continue

样例：去掉一串字符串的尾部blank，tab和newline

```
int trim(char s[]);
```

## 3.8 Goto and labels

Goto语句最好不要用。不过作者还是介绍了可能用到Goto的一些情况。

1. 跳出多重循环

```c
for (...)
{
	for (...)
	{
		...
		if (something wrong)
			goto error;
    }
}

error:
	/* handle the error */
```

2. 判断两个数组相等，其实也是跳出多重循环，一般可以多加一个 `flag` 变量来避免 `Goto` 的使用。



# 4. 函数和编程结构

## 4.1 函数基础

最小的函数

```
dummy() {}
```

- 在程序开发过程中作为place holder使用
- 缺省返回值为 `int`

`main` 函数的返回值一般是给操作系统接收。

## *4.2 返回非整数的函数

这一节我看了很多遍都不是很明白，写了个大概的总结。

1. 为什么要把返回值区分为整型和非整型来讨论？我的一个理解是，C语言函数的默认返回值是 `int`，所以作者分开来讨论。
2. 在C89规范中，是允许隐式声明函数的，即以下代码中，`foo()` 被隐式声明为一个函数，其默认返回值是 `int`。这样的程序在编译时不会有问题，但连接和运行的阶段会出错。C99标准中已经废弃了隐式函数声明。

```c
int main()
{
  	double a = foo();
}
```

3. 在 `atof` 这个程序中，作者说为了明确其返回值是非整型的，在 `main()` 函数里还要对其进行声明，而且这个声明要与函数原型保持一致。

   ```c
   double sum, atof(char []);
   ```

4. 在不一致的情况下：如果在同一个文件里编译，编译器会报错，如果不在同一个文件里编译，编译器无法检测到匹配，于是这里的声明就变成隐式声明函数 `int atof()`。

5. 在C语言中，以下两个函数原型的含义是不同的，第一个说明可以接受任意个参数，第二个说明参数个数为0。

   ```c
   int foo();
   int foo(void);
   ```

但是，以上做法都已经过时了！！我一开始很疑惑为什么要在主函数里声明函数？类比变量声明我做出以下理解。在K&R那个时代，人们喜欢把所有变量声明都放在函数的开头，然后再进行赋值什么的操作，实际上并不需要这样，变量等用到的时候再声明即可。所以对于被调用的函数可能也是如此，在开头写出声明，只是告诉人们，我接下来的程序会调用这个函数。

最后，我也不知道我为什么要花时间去研究这些废除了的机制……只是单纯觉得有意思吧。

写了一个很丑陋的程序验证以上几点，编译的时候必须用C89规范

```c
#include "stdio.h"
/* int foo(); */
/* int bar(); */

int main()
{
    int a = foo(); /* 隐式声明，但最后调用了最下面的foo()，我也不知道为什么 */
    bar();  /* 隐式声明 int bar(); 与 double bar() 冲突，编译器报错 */
}

double bar()
{
   foo(2);
}

int foo(int a) 
{
    printf("foo%d\n", a);
}

```

```c
#include "stdio.h"
int main()
{
  	int foo(int x); /* 显式声明 */
    int a = foo(); /* 参数不匹配报错 */

}
int foo(int a) 
{
    printf("foo%d\n", a);
}

```

## 4.3 外部变量 External Variables

外部变量与全局变量的含义差不多，自动(Automatic)变量与局部变量含义差不多。



## 4.4 作用域(Scope)规则