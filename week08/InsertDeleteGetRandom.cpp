mt19937 rd(0);
class RandomizedSet
{
public:
    vector<int> v;
    unordered_map<int, int> map;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;

        v.push_back(val);
        map[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;

        auto it = map.find(val);
        v[it->second] = v.back();
        v.pop_back();

        map[v[it->second]] = it->second;
        map.erase(val);

        return true;
    }

    int getRandom()
    {
        return v[rd() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */