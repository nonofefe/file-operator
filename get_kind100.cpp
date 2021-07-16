
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

int main()
{
  string filename("datasets/input/poke_factory.txt");
  vector<string> lines;
  string line;

  ifstream input_file(filename);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '"
      << filename << "'" << endl;
    return EXIT_FAILURE;
  }


  int MAX = 250;
  int ind = 0;
  set<string> st;
  while (getline(input_file, line)){
    ull len = line.size();
    if(ind % 6 == 1){
      int cnt = 0;
      vector<string> arr = split(line,'-');
      st.insert(arr[0]);
    }
    ind++;
  }

  input_file.close();

  ofstream outputfile("datasets/generate/poke_kind100.txt");

  for(auto itr:st){
    outputfile << itr;
    outputfile << "\n";
  }
  outputfile.close();


  

  return EXIT_SUCCESS;
}