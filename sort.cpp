#include "datastructor.h"
VertexType* listMergeSort_len(VertexType* head) //传入需要归并排序的链表的头指针
{
     //一个元素就返回
    if (head->next == nullptr)
        return head;
    //使用 slow-fast方法找到链表的中间位置，注意这里写的链表的头节点是非空的，即头节点也是存贮数据的
    VertexType* fast = head->next;  //   fast指向第2个节点
    VertexType* slow = head;	  //   slow指向第1个节点
    while (fast != nullptr&&fast->next != nullptr)
    {
        fast = fast->next->next; //fast每次走两步
        slow = slow->next;	//slow每次走一步，这样slow就会到lian'biao中点
    }
    //slow最后指向有n个元素的链表的第n/2个元素。如一共6个元素，slow指向第3个，一共5个元素，slow指向第2个。
    VertexType* left = head;
    VertexType* right = slow->next;
    slow->next = nullptr;
    //但是实际上将链表截断，左边的部分从第1个开始，右边的要从第4个(共6个)或者第3个(共5个)开始，所以有right=slow->next;
    //假设上面截断的左右两个子链表调用归并排序后变成了排好序(new，新)的“新”左右两个链表，然后开始归并
    VertexType* newLeft = listMergeSort_len(left);
    VertexType* newRight = listMergeSort_len(right);

    VertexType * newList ;  //注意指针tail才是后面进行操作的指针，newList是为了保存起点
    VertexType * tail ;


    if (newLeft->len < newRight->len)
    {
        newList = newLeft;
        newLeft = newLeft->next;
    }
    else
    {
        newList = newRight;
        newRight = newRight->next;
    }
        tail=newList ;
        tail->next = nullptr;
    //以上代码是向newList的第一个节点存入左右两个链表的头节点的较小的元素
        while (newLeft != nullptr|| newRight != nullptr)//在&&和||之间踩了大坑，调了一个多小时的bug,让我骂一句真是mmp
    {
        if (newLeft == nullptr)			//左边全部接完了
        {
            tail->next = newRight; //右边就直接整条链表接上去
            newRight = nullptr;
        }
        else if (newRight == nullptr) {	//同理，右边接完了
            tail->next = newLeft;  //左边就直接整条链表接上去，复杂度为O（1），操作爽yy
            newLeft = nullptr;
        }
        else if (newLeft->len < newRight->len)
        {
            tail->next = newLeft;		//上面接一整个链表，这里就是接链表中单个元素的操作
            newLeft = newLeft->next;
            tail = tail->next;
            tail->next = nullptr;
        }
        else {
            tail->next = newRight;
            newRight = newRight->next;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
    return newList;   //返回新接好的List，美滋滋。
}

VertexType* listMergeSort_comm_view(VertexType* head) //传入需要归并排序的链表的头指针
{
     //一个元素就返回
    if (head->next == nullptr)
        return head;
    //使用 slow-fast方法找到链表的中间位置，注意这里写的链表的头节点是非空的，即头节点也是存贮数据的
    VertexType* fast = head->next;  //   fast指向第2个节点
    VertexType* slow = head;	  //   slow指向第1个节点
    while (fast != nullptr&&fast->next != nullptr)
    {
        fast = fast->next->next; //fast每次走两步
        slow = slow->next;	//slow每次走一步，这样slow就会到lian'biao中点
    }
    //slow最后指向有n个元素的链表的第n/2个元素。如一共6个元素，slow指向第3个，一共5个元素，slow指向第2个。
    VertexType* left = head;
    VertexType* right = slow->next;
    slow->next = nullptr;
    //但是实际上将链表截断，左边的部分从第1个开始，右边的要从第4个(共6个)或者第3个(共5个)开始，所以有right=slow->next;
    //假设上面截断的左右两个子链表调用归并排序后变成了排好序(new，新)的“新”左右两个链表，然后开始归并
    VertexType* newLeft = listMergeSort_comm_view(left);
    VertexType* newRight = listMergeSort_comm_view(right);

    VertexType * newList ;  //注意指针tail才是后面进行操作的指针，newList是为了保存起点
    VertexType * tail ;


    if (newLeft->v_view.view_comm > newRight->v_view.view_comm)
    {
        newList = newLeft;
        newLeft = newLeft->next;
    }
    else
    {
        newList = newRight;
        newRight = newRight->next;
    }
        tail=newList ;
        tail->next = nullptr;
    //以上代码是向newList的第一个节点存入左右两个链表的头节点的较小的元素
        while (newLeft != nullptr|| newRight != nullptr)//在&&和||之间踩了大坑，调了一个多小时的bug,让我骂一句真是mmp
    {
        if (newLeft == nullptr)			//左边全部接完了
        {
            tail->next = newRight; //右边就直接整条链表接上去
            newRight = nullptr;
        }
        else if (newRight == nullptr) {	//同理，右边接完了
            tail->next = newLeft;  //左边就直接整条链表接上去，复杂度为O（1），操作爽yy
            newLeft = nullptr;
        }
        else if (newLeft->v_view.view_comm > newRight->v_view.view_comm)
        {
            tail->next = newLeft;		//上面接一整个链表，这里就是接链表中单个元素的操作
            newLeft = newLeft->next;
            tail = tail->next;
            tail->next = nullptr;
        }
        else {
            tail->next = newRight;
            newRight = newRight->next;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
    return newList;   //返回新接好的List，美滋滋。
}

VertexType* listMergeSort_comm_renut(VertexType* head) //传入需要归并排序的链表的头指针
{
     //一个元素就返回
    if (head->next == nullptr)
        return head;
    //使用 slow-fast方法找到链表的中间位置，注意这里写的链表的头节点是非空的，即头节点也是存贮数据的
    VertexType* fast = head->next;  //   fast指向第2个节点
    VertexType* slow = head;	  //   slow指向第1个节点
    while (fast != nullptr&&fast->next != nullptr)
    {
        fast = fast->next->next; //fast每次走两步
        slow = slow->next;	//slow每次走一步，这样slow就会到lian'biao中点
    }
    //slow最后指向有n个元素的链表的第n/2个元素。如一共6个元素，slow指向第3个，一共5个元素，slow指向第2个。
    VertexType* left = head;
    VertexType* right = slow->next;
    slow->next = nullptr;
    //但是实际上将链表截断，左边的部分从第1个开始，右边的要从第4个(共6个)或者第3个(共5个)开始，所以有right=slow->next;
    //假设上面截断的左右两个子链表调用归并排序后变成了排好序(new，新)的“新”左右两个链表，然后开始归并
    VertexType* newLeft = listMergeSort_comm_renut(left);
    VertexType* newRight = listMergeSort_comm_renut(right);

    VertexType * newList ;  //注意指针tail才是后面进行操作的指针，newList是为了保存起点
    VertexType * tail ;


    if (newLeft->v_renut.renut_comm > newRight->v_renut.renut_comm)
    {
        newList = newLeft;
        newLeft = newLeft->next;
    }
    else
    {
        newList = newRight;
        newRight = newRight->next;
    }
        tail=newList ;
        tail->next = nullptr;
    //以上代码是向newList的第一个节点存入左右两个链表的头节点的较小的元素
        while (newLeft != nullptr|| newRight != nullptr)//在&&和||之间踩了大坑，调了一个多小时的bug,让我骂一句真是mmp
    {
        if (newLeft == nullptr)			//左边全部接完了
        {
            tail->next = newRight; //右边就直接整条链表接上去
            newRight = nullptr;
        }
        else if (newRight == nullptr) {	//同理，右边接完了
            tail->next = newLeft;  //左边就直接整条链表接上去，复杂度为O（1），操作爽yy
            newLeft = nullptr;
        }
        else if (newLeft->v_renut.renut_comm > newRight->v_renut.renut_comm)
        {
            tail->next = newLeft;		//上面接一整个链表，这里就是接链表中单个元素的操作
            newLeft = newLeft->next;
            tail = tail->next;
            tail->next = nullptr;
        }
        else {
            tail->next = newRight;
            newRight = newRight->next;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
    return newList;   //返回新接好的List，美滋滋。
}
