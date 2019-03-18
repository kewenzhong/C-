算法思想一下两篇博客讲得很不错，我就不再赘述：

https://www.cnblogs.com/lojunren/p/3865234.html

https://www.cnblogs.com/c-cloud/p/3224788.html#!comments

https://blog.csdn.net/x__1998/article/details/79951598

下面结合我的代码做一些补充讲解：

1、next[] 记录的是部分匹配表，即后缀与前缀相同的长度

2、getNext中for循环是从1开始的，所以先将next[0]置为0。为什么从1开始？因为如果从0开始，那么for循环计算出来的next[0]就等于1了，而根据我们的前缀后缀理论，next[0]恒为0.

3、next[]数组只是记录了部分匹配长度，当发生不匹配时，目标串需要右移的位数，还需要进一步计算：

  右移位数 = 已匹配的字符数 - 对应的部分匹配值