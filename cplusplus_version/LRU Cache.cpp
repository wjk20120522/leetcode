/**
 * my method, timeout
class LRUCache{
public:

	int **arr;
	int begin;
	int end;
	int capacity;

	LRUCache(int capacity) {
		
		arr = new int*[capacity+1];
		for (int i = 0; i < capacity+1; i++) {
			arr[i] = new int[2];
		}
		begin = end = 0;
		this->capacity = capacity + 1;
	}

	int get(int key) {
		if (begin == end) return -1; // empty
		for (int i = begin; (i + 1) % capacity != end; i=(i+1)%capacity) {
			if (arr[i][0] == key) {
				return arr[i][1];
			}
		}
		return -1;
	}

	void set(int key, int value) {
		for (int i = begin; (i + 1) % capacity != end; i = (i + 1) % capacity) {
			if (arr[i][0] == key) {
				arr[i][1] = value;    // find the key
				return;
			}
		}
		if ((end + 1) % capacity != begin) {   // not full
			arr[end][0] = key;
			arr[end][1] = value;
			end = (end + 1) % capacity;
		}
		else {                   // full, then invalid the begin then insert
			begin = (begin + 1) % capacity;
			arr[end][0] = key;
			arr[end][1] = value;
			end = (end + 1) % capacity;

		}
	}
};

 */

