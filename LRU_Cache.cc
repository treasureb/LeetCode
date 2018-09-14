#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

/* Least recently used : 最近最久未使用 */

class LRUCache{
public:
    LRUCache(size_t capacity)
        :capacity_(capacity)
    {}

    int get(int key){
        auto found_iter = map_.find(key);
        if(found_iter == map_.end()){   //key doesn't exist
            return -1;
        }
        list_.splice(list_.begin(),list_,found_iter->second);   //将最近一次使用的，放置list的头部位置
        return found_iter->second->second;
    }

    void set(int key,int value){
        auto found_iter = map_.find(key);
        if(found_iter != map_.end()){
            list_.splice(list_.begin(),list_,found_iter->second);
            found_iter->second->second = value;
            return;
        }
        if(map_.size() == capacity_){
            int key_to_del = list_.back().first;    //最近最久未使用
            list_.pop_back();
            map_.erase(key_to_del);
        }
        list_.emplace_front(key,value);
        map_[key] = list_.begin();
    }
private:
    size_t capacity_;   //保存大小
    unordered_map<int,list<pair<int,int>>::iterator> map_;  //first is key,second is list iterator
    list<pair<int,int>> list_;  //first is key,second is value
};
