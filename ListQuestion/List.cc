#include "List.h"

//初始化单链表
//改变指针指向，所以穿二级指针
void InitList(Node **Head)
{
	*Head = NULL;
}

//创建一个新的节点
Node* BuyNode(TYPE data)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (NULL == tmp){
		printf("Malloc error!\n");
		return NULL;
	}
	else{
		tmp->_data = data;
		tmp->_next = NULL;
	}
	return tmp;
}

//尾部插入一个节点
void PushBack(Node** Head,TYPE data)
{
	assert(Head);

	//先判断头节点是否为空
	if (NULL == *Head)
	{
		*Head = BuyNode(data);
	}
	else{
		Node *pre = *Head;
		Node *newNode = BuyNode(data);
		while (pre->_next != NULL){
			pre = pre->_next;
		}
		pre->_next = newNode;
	}
}

//判断链表是否带环
bool IsExistLoop(Node* Head)
{
	if (NULL == Head)
		return true;

	Node *Fast = Head;
	Node *Slow = Head;

	//如果链表不带环，则Fast肯定先走到NULL
	while (Fast&& Fast->_next){
		Fast = Fast->_next->_next;
		Slow = Slow->_next;

		if (Fast == Slow)
			return true;
	}

	if (Fast == NULL || Fast->_next == NULL)
		return false;

	return false;
}

//求环的长度
int GetLoopLength(Node* Head)
{
	if (NULL == Head)
		return 0;

	Node *Fast = Head;
	Node *Slow = Head;
	while (Fast && Fast->_next){
		Fast = Fast->_next->_next;
		Slow = Slow->_next;

		//第一次相遇
		if (Fast == Slow)
			break;
	}

	//当再次相遇时，len的长度为环的长度
	int len = 0;
	while (Fast && Fast->_next){
		Fast = Fast->_next->_next;
		Slow = Slow->_next;
		len++;

		if (Fast == Slow)
			return len;
	}
	return -1;
}

/*  求环的入口点
	s = Len + x;
	2s = Len + nR + x;

	Len = nR - x
	故在相遇点设置一个指针，链表起始位置一个指针，两者相遇即为入口点
*/
Node* FindLoopPort1(Node *Head)
{
	if (NULL == Head)
		return NULL;

	Node *Fast = Head;
	Node *Slow = Head;

	//求第一次相遇的点
	while (Fast && Fast->_next){
		Fast = Fast->_next->_next;
		Slow = Slow->_next;
		if (Fast == Slow)
			break;
	}

	if (Fast == NULL || Fast->_next == NULL)
		return NULL;

	//然后两个指针以相同的速度走
	Slow = Head;
	while (Fast != Slow){
		Slow = Slow->_next;
		Fast = Fast->_next;
	}
	return Fast;
}

Node* FindLoopPortPre(Node *Head)
{
	if (NULL == Head)
		return NULL;

	Node *Fast = Head;
	Node *Slow = Head;

	//求第一次相遇的点
	while (Fast && Fast->_next){
		Fast = Fast->_next->_next;
		Slow = Slow->_next;
		if (Fast == Slow)
			break;
	}

	if (Fast == NULL || Fast->_next == NULL)
		return NULL;

	//然后两个指针以相同的速度走
	Slow = Head;
	while (Fast != Slow){
		Slow = Slow->_next;
		Fast = Fast->_next;
	}
	return Fast;
}


Node* FindLoopPort2(Node *Head)
{
	int LoopLen = GetLoopLength(Head);
	Node *Fast = Head;
	Node *Slow = Head;

	while (LoopLen--){
		Fast = Fast->_next;
	}

	while(Fast && Fast->_next){
		Fast = Fast->_next;
		Slow = Slow->_next;

		if (Fast == Slow)
			return Slow;
	}

	return NULL;
}



//判断两个不带环单链表是否相交
//bool TwoListCrossNotLoop(Node *Head1, Node *Head2)
//{
//	if (NULL == Head1 || NULL == Head2)
//		return false;
//	
//	Node *node1 = Head1;
//	Node *head1 = Head1;
//	Node *node2 = Head2;
//
	//1、如果只判断是否相交，则直接看最后的节点是否相同即可
	//时间复杂度为O(len1 + len2)
	/*while (node1->_next){
		node1 = node1->_next;
	}

	while (node2->_next){
		node2 = node2->_next;
	}

	if (node1 == node2)
		return true;

	return false;*/
//#endif
//
//
////	//2、先遍历其中一个链表，将其首尾相接
////	//则判断相交转换为判断是否带环
//	while(node1->_next){
//		node1 = node1->_next;
//	}
//	//尾部指向头部，勾成环
//	node1->_next = head1;
//	
//	//判断另一个是否带环
//	Node *Fast = Head1;
//	Node *Slow = Head2;
//	while (Fast && Fast->_next){
//		Fast = Fast->_next->_next;
//		Slow = Slow->_next;
//
//		if (Fast == Slow)
//			return true;
//	}
//
//		if (NULL == Fast || NULL == Fast->_next)
//			return false;
//
//		return false;
//

	//采用哈希表来判断两个链表中是否有地址相同的节点
	//set<string> s;
	//unordered_set<Node>::const_iterator it;
	/*while (node1){
		s.insert(node1);
		node1 = node1->_next;
	}

	while (node2){	
		if ((*it = find(s.begin(), s.end(), node2) == node2))
			return true;

		it++;
		node2 = node2->_next;
	}*/

	//return false;

//}

//求相交链表的交点
Node* FindTwoListPoint(Node* Head1, Node* Head2)
{
	if (NULL == Head1 || NULL == Head2)
		return NULL;

	int len1 = 0;
	int len2 = 0;
	Node *node1 = Head1;
	Node *node2 = Head2;
	//求链表1的长度
	while (node1){
		len1++;
		node1 = node1->_next;
	}

	//求链表2的长度
	while (node2){
		len2++;
		node2 = node2->_next;
	}

	//求两个链表长度的差值
	int len = len1 > len2 ? len1 - len2 : len2 - len1;

	//将指针移到链表头部位置
	node1 = Head1;
	node2 = Head2;
	if (len1 > len2){
		while (len-- && node1->_next){
			node1 = node1->_next;
		}

		while (node1 && node2){
			if (node1 == node2)
				return node2;

				node1 = node1->_next;
				node2 = node2->_next;
		}
	}
	else{
		while (len--&&node2->_next){
			node2 = node2->_next;
		}
		while (node1 && node2){
			if (node1 == node2)
				return node2;

			node1 = node1->_next;
			node2 = node2->_next;
		}
	}
	return NULL;
}

Node* FindTwoLoopListPoint(Node* Head1, Node* Head2)
{
	if (NULL == Head1 || NULL == Head2)
		return NULL;

	Node* node1 = Head1;
	//找到环的前一个节点，然后指向其头部构成环
	Node* Pre = FindLoopPortPre(node1);
	Pre->_next = node1;

	//判断Head2是否带环即可
	if (IsExistLoop(Head2)){
		return FindLoopPort1(Head2);
	}
	
	return NULL;
}

void TestIsLoop()
{
	Node* Head;
	InitList(&Head);
	Node* Node1 = BuyNode(1);
	Node* Node2 = BuyNode(2);
	Node* Node3 = BuyNode(3);
	Node* Node4 = BuyNode(4);

	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node2;

	printf("%d\n", IsExistLoop(Head));
	int len = GetLoopLength(Node1);
    cout<<len<<endl;
	Node* ret = FindLoopPort2(Node1);
    
}

Node* ReverseList(Node *Head)
{
    Node* ReverseHead = nullptr;
    Node* node = Head;
    Node* pre = nullptr;

    while(node){
        Node* next = node->_next;

        if(node->_next == nullptr)
            ReverseHead = node;
        
        node->_next = pre;
        pre = node;
        node = next;
    }
    return ReverseHead;
}


void TestCross()
{
	Node* Node1 = BuyNode(1);
	Node* Node2 = BuyNode(2);
	Node* Node3 = BuyNode(3);
	Node* Node4 = BuyNode(4);

	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node4;

	Node* Node5 = BuyNode(5);
	Node* Node6 = BuyNode(6);

	Node5->_next = Node6;
	Node6->_next = Node4;

	Node *ret = FindTwoListPoint(Node1, Node5);
	//bool ret = TwoListCrossNotLoop(Node1, Node5);
}

void TestReverse()
{
    Node* Node1 = BuyNode(1);
    Node* Node2 = BuyNode(2);
    Node* Node3 = BuyNode(3);
    Node* Node4 = BuyNode(4);
    Node* Node5 = BuyNode(5);
    
    Node1->_next = Node2;
    Node2->_next = Node3;
    Node3->_next = Node4;
    Node4->_next = Node5;

    Node* ret = ReverseList(Node1);
    cout<<"ret:"<<ret->_data<<endl;
}

int main()
{
	//TestIsLoop();
//	TestCross();
    TestReverse();
	return 0;
}
