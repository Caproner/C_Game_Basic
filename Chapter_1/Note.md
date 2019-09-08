# 第一章笔记

### 1-1

+ 区别于Linux，在Windows系统中，`Sleep`函数位于头文件`windows.h`中，其函数参数只有一个，表示停止的毫秒数。使用时注意大小写。

### 1-2

+ `kbhit()`函数位于头文件`conio.h`中，用于非阻塞的相应键盘输入事件。

  + 简单的讲就是，判断是否有键盘输入，如果有则返回1，否则返回0。
  + 其实就是`Keyboard Hit`的简写。

+ 头文件`ctime`中包含着可以获取当前系统挂钟时间的函数`clock()`。于是便可以像下面这样取到运行时间：

  ```c++
  #include <cstdio>
  #include <ctime>
  
  int main()
  {
      clock_t start, end;
      start = clock();
      for(int i = 0; i < 1000000000; i++)
      {
          int k = 3;
      }
      end = clock();
      printf("%.2lf\n", (double)(end-start)/CLOCKS_PER_SEC);
      return 0;
  ```

