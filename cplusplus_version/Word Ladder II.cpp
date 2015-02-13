/**
 * My solution , TLE
 */

/*
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		
		unordered_map<string, int> dis;
		vector<vector<string> > res;
		vector<string> onepath;

		if (start == end) {
			onepath.push_back(start);
			res.push_back(onepath); return res;
		}
		
		
		stack<string> q;
		dict.insert(end);
		dis[start] = 1;
		q.push(start);
		
		vector<string> v;
		v.push_back(start);


		
		//create a dictionary to store alphabet used
		
		int i, j;
		vector< vector<char> > alpha(end.size());
		for (string str : dict) {
			for (i = 0; i < str.length(); i++) {

				for (j = 0; j < alpha[i].size(); j++) {
					if (alpha[i][j] == str[i]) break;
				}
				if (j == alpha[i].size())
					alpha[i].push_back(str[i]);
			}
		}
		int min = INT_MAX;
		getPath(dis, res, end, v, dict, start, min, alpha);
	
		return res;
	}

	void getPath(unordered_map<string, int> &dis, vector<vector<string> >& res,
		string& end, vector<string>& v, unordered_set<string> &dict, string& cur, int& min,
		vector< vector<char> >& alpha) {
	
			if (cur == end) {
				if (dis[cur] <= min) {
					if (dis[cur] < min) {
						res.clear();
						min = dis[cur];
					}
					res.push_back(v);
				}
				return;
			}

			

			
			for (int i = 0; i < cur.length(); i++) {
				string tmp = cur;
				for (int j = 0; j<alpha[i].size(); j++) {
					tmp[i] = alpha[i][j];
				
					if (dict.find(tmp) != dict.end() && ( dis.find(tmp) == dis.end()  || dis[tmp] > dis[cur] )     ) {
						dis[tmp] = dis[cur] + 1;
						v.push_back(tmp);
						getPath(dis, res, end, v, dict, tmp, min, alpha);
						v.pop_back();
					}
				}
			} // end for	
	}
};
*/


/*
other people method
 */
class Solution {
public:
    void calAdj(const string s, unordered_set<string> & dict, unordered_set<string>& adjset){
         adjset.clear();
         for( int i = 0; i < s.size(); ++i){
             string tmp(s);
             for( char az = 'a'; az <= 'z'; ++az){
                 tmp[i] = az;
                 if( dict.find(tmp) != dict.end()){ //tmp is in dictionary
                     adjset.insert(tmp);
                 }
             }
         }
    }

    void pathreverse(unordered_map<string, unordered_set<string>>& pathmap, string start, vector<vector<string>>& pathlist){
    
         vector<string> & lastpath = pathlist[pathlist.size()-1];
         lastpath.push_back( start );
         vector<string> prepath(lastpath);
    
         int p = 0;
         for( auto nstr : pathmap[start] ){
              if( p > 0 )//generate new path
                  pathlist.push_back(prepath);
              pathreverse(pathmap, nstr, pathlist);
              ++p;
         }
    }

    vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict){

      vector< vector<string> > pathlist;
      string tmp = start;
      start = end;
      end = tmp;
      int slen = start.size();
      int elen = end.size();
      if( slen != elen )
          return pathlist;

      dict.insert(start);
      dict.insert(end);

      //run bfs
      unordered_map<string, unordered_set<string>> pathmap;
      unordered_set<string> curset;
      curset.insert(start);
      dict.erase(start);
      unordered_set<string> adjset;
      bool find = false;

      while( !find && curset.size() > 0 ){
           unordered_set<string> preset(curset);
           curset.clear();
           for( auto pres : preset){
                if( pres == end ){//find it
                    find = true;
                    pathlist.push_back(vector<string>());
                    pathreverse(pathmap, end, pathlist);
                    break;
                }
                calAdj(pres, dict, adjset);
                curset.insert(adjset.begin(),adjset.end());//put in next layer
                for( auto nexts : adjset ){
                     pathmap[nexts].insert(pres); // record its parents
                }
           }
           for( auto vs : curset) // remove visited string
                dict.erase(vs);
      }
      return pathlist;
    }
};