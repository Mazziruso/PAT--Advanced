# 题解
----

* 根据损失函数最小化原则：长度短的segment对折次数应该越多，长度长的segment对折次数应该越少。
* 根据此原则，将segments进行从小到大进行排序，然后依次从前往后进行对折。
* 最后应该对结果进行舍入
