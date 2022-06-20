class LRUCache {

    int MaxSize;
    list<pair<int,int>> m_list;
    unordered_map<int,list<pair<int,int>> ::iterator> m_map;
	
public:
    LRUCache(int capacity) {
        MaxSize=capacity;
    }
    
    int get(int key) {
        auto itr = m_map.find(key);
        if(itr==m_map.end())return -1;
        int val= itr->second->second;
        m_list.erase(itr->second);
        m_list.push_front({key,val});
        m_map[key]=m_list.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto itr = m_map.find(key);
        if(itr!=m_map.end()) m_list.erase(itr->second);
        else if(m_map.size()==MaxSize){
            m_map.erase(m_list.back().first);
            m_list.pop_back();
        }
        m_list.push_front({key,value});
        m_map[key]=m_list.begin();
        return;
    }
};
