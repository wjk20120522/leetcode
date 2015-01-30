class LRUCache{
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		
		auto it = dict.find(key);
		if (it != dict.end()) {
			data.splice(data.begin(), data, it->second);
			dict[key] = data.begin();                    // if no this line code, it's ac also but i don't think so  
			return it->second->second;
		}
		return -1;
	}

	void set(int key, int value) {
		if (dict.find(key) != dict.end()) {
			dict[key]->second = value;
			data.splice(data.begin(), data, dict[key]);
			return;
		}

		if (dict.size() == cap) {
			int tail_key = data.back().first;
			dict.erase(tail_key);
			data.pop_back();
		}

		data.push_front(make_pair(key, value));
		dict[key] = data.begin();
	}

private:
	int cap;
	list< pair<int, int> > data;
	unordered_map<int, list< pair<int, int> >::iterator > dict;
};