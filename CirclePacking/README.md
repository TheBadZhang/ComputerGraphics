# Circle Pakcing（图形学概念）

## 何为Circle Pakcing？

![Circle Packing 示例图 1](./CP2018.jpg)

就差不多是上面的东西吧……只不过上面做了一点处理，如果按照定义的话，就应该是一堆[相切的圆](https://en.wikipedia.org/wiki/Circle_packing_theorem)。只不过放到图形学里面就不一定是大小相同的了，可以根据需求和效果调整大小，
## 算法实现？

用一个vector存储圆，每次生成新的圆就遍历一遍，直到生成的圆没有与任何圆相交（我的实现里面没有保证每个圆都要相切，但是，当圆的数量达到一定程度了，所有圆也就都相切了。具体也可以看代码的实现。

## 编译？

代码在VS2017 19.11 with xege_for_windows 上编译通过

首先需要在电脑上配置[xege](http://xege.org/)，然后编译……