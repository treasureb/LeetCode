#include<iostream>

#include"Tree.h"


//序列化
void Serialize(Node* Root,ostream& stream)
{
    if(nullptr == Root){
        stream<<"#,";
        return;
    }

    stream<<Root->_value<<',';
    Serialize(Root->_left,stream);
    Serialize(Root->_right,stream);
}

void DeSerialize(Node** Root,istream& stream)
{
    int number;
    if(ReadStream(stream,&number)){
        *Root = new Node();
        (*Root)->_value = number;
        (*Root)->_left = nullptr;
        (*Root)->_right = nullptr;

        DeSerialize(&(*Root)->_left,stream);
        DeSerialize(&(*Root)->_right,stream);
    }
}
