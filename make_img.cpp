
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
  string input_filename("datasets/input/poke_img.txt");
  vector<string> lines;
  string line;
  ifstream input_file(input_filename);
  //string output_filename("datasets/generate/poke_img.txt");
  //ofstream output_file(output_filename);
  if (!input_file.is_open() || !output_file.is_open()) {
    cerr << "Could not open the file - '"
      << "'" << endl;
    return EXIT_FAILURE;
  }

  while (getline(input_file, line)){
    vector<string> arr = split(line, ' ');
    ull len = arr.size();
    rep(i,len){
      if(arr[i].substr(0,4) == "alt="){
        cout << arr[i].substr(5,arr[i].size()-6) << endl;
      }
      if(arr[i].substr(0,4) == "src="){
        cout << arr[i].substr(5,arr[i].size()-6) << endl;
      }
    }
  }
  input_file.close();
  //output_file.close();

  return EXIT_SUCCESS;
}