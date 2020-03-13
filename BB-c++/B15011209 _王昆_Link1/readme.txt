函数介绍

本工程主要完成
1.创建一个新的链表
2.输出新链表
3.分解链表为三个
4.在把三个按照给定的顺序连接成一个


本函数除主函数外，含有五个函数，分别为creat(),
print(struct Student *head),
print1(struct Student *head),
resolve(struct Student *head, struct Student *letter, struct Student *digit, struct Student *other),
link(struct Student *letter, struct Student *digit, struct Student *other)


其中，creat（）函数是创建一个新的单链表，函数会返回单链表的表头节点的地址    无入口参数


print(struct Student *head),此函数的功能是打印以NULL为链表最后一个节点指向的单链表   入口参数为需要打印的链表的表头节点的地址
print1(struct Student *head),此函数的功能是打印以head为链表最后一个节点指向的单循环链表   入口参数为需要打印的链表的表头节点的地址


resolve(struct Student *head, struct Student *letter, struct Student *digit, struct Student *other)，此函数的功能是分解单链表为三个链表，分别用来储存数字，字符，字母               函数无返回值                 入口参数为   head：需要分解的函数   letter，digit，other三个新的节点


link(struct Student *letter, struct Student *digit, struct Student *other)，此函数的功能是连接，把三个链表连接成一个按照给定的，字母，数字，字符的顺序连接
     函数会返回一个接成的函数的头节点的地址         入口参数为需要连接的三个函数的头节点地址。






