/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		UndirectedGraphNode * res = new UndirectedGraphNode(node->label);
		map<UndirectedGraphNode *, UndirectedGraphNode *> map;
		map[node] = res;
		clone(res, node, map);
		return res;

	}
	void clone(UndirectedGraphNode *res, UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> &map) {
		 
	for (unsigned int i = 0; i < node->neighbors.size(); i++) {
			if (map.find((node->neighbors)[i]) != map.end()) {
				res->neighbors.push_back(map[(node->neighbors)[i]]);
				continue;
			}
				
			UndirectedGraphNode *newNode = new UndirectedGraphNode((node->neighbors)[i]->label);
			map[(node->neighbors)[i]] = newNode;
			res->neighbors.push_back(newNode);
			clone(newNode, (node->neighbors)[i], map);

		}
	}
};

